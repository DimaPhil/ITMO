package ru.ifmo.ctddev.filippov.parallelmapper;

import info.kgeorgiy.java.advanced.mapper.ParallelMapper;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.function.Consumer;
import java.util.function.Function;

public class ParallelMapperImpl implements ParallelMapper {
    private volatile boolean isTerminated = false;
    private final ArrayDeque<Consumer<Void>> queue;
    private final Thread[] threads;

    /**
     * Creates class with given number of threads to execute tasks on
     * @param threads number of threads
     */
    public ParallelMapperImpl(int threads) {
        queue = new ArrayDeque<>();
        this.threads = new Thread[threads];
        for (int i = 0; i < threads; i++) {
            this.threads[i] = new Thread(new Runnable() {
                @Override
                public void run() {
                    while (!isTerminated) {
                        Consumer<Void> currentElement = null;
                        synchronized (queue) {
                            if (!queue.isEmpty()) {
                                currentElement = queue.pop();
                            }
                        }
                        if (currentElement != null) {
                            currentElement.accept(null);
                            synchronized (queue) {
                                queue.notifyAll();
                            }
                            continue;
                        }
                        if (isTerminated) {
                            return;
                        }
                        try {
                            synchronized (queue) {
                                queue.wait();
                            }
                        } catch (InterruptedException e) {
                            return;
                        }
                    }
                }
            });
            this.threads[i].start();
        }
    }

    /**
     * Maps the sequence, using the number of threads, containing in this object entry. It actually puts functions
     * that map every single list item, to the special queue, and eventually threads execute it and put the
     * result in the result list
     *
     * @param f function to map
     * @param args  list to map
     * @param <T> type of initial array item
     * @param <R> type of result array item
     * @return  mapped list
     * @throws InterruptedException throws {@link InterruptedException} like all parallel functions
     */
    @Override
    public <T, R> List<R> map(Function<? super T, ? extends R> f, List<? extends T> args) throws InterruptedException {
        final int argsSize = args.size();
        AtomicInteger counter = new AtomicInteger(0);
        ArrayList<R> resultList = new ArrayList<>(argsSize);
        for (int i = 0; i < argsSize; i++) {
            resultList.add(null);
        }
        for (int i = 0; i < argsSize; i++) {
            final int finalI = i;
            synchronized (queue) {
                queue.push((everything) -> {
                    T element;
                    element = args.get(finalI);
                    R result = f.apply(element);
                    synchronized (resultList) {
                        resultList.set(finalI, result);
                    }
                    counter.incrementAndGet();
                    synchronized (queue) {
                        queue.notifyAll();
                    }
                });
            }
        }
        synchronized (queue) {
            queue.notifyAll();
            while (counter.get() < argsSize) {
                queue.wait();
            }
        }
        return resultList;
    }

    /**
     * Closes this object, stopping all threads from execution. After this method is invoked, object can't be used.
     * @throws InterruptedException like all parallel functions
     */
    @Override
    public void close() throws InterruptedException {
        isTerminated = true;
        for (Thread thread : threads) {
            thread.interrupt();
            thread.join();
        }
    }
}
