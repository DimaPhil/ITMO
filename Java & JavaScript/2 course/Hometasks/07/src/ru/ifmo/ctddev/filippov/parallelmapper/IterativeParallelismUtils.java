package ru.ifmo.ctddev.filippov.parallelmapper;

import info.kgeorgiy.java.advanced.mapper.ParallelMapper;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.function.BinaryOperator;
import java.util.function.Function;
import java.util.stream.Collectors;

/**
 * This class represents some static methods for easily realisation of {@link IterativeParallelism} class functions
 *
 * @author Dmitry Philippov
 * @see ru.ifmo.ctddev.filippov.parallelmapper.Monoid
 */
public class IterativeParallelismUtils {
    private IterativeParallelismUtils() {
    }

    /**
     * Method that returns left fold of list elements - for given function f and list l it returns f(l[0], f(l[1], f(l[2], ...)))
     * Also list is divided in threadsCount parts for iterative parallelism
     * If function of Optional.empty(), than binary operation of monoid applies to elements, left fold too
     *
     * @param threadsCount count of threads that list should be divide to
     * @param monoid       entry of Monoid class
     * @param function     function that applies to list elements
     * @param mapper       parallel mapper
     * @param <T>          type of elements in list
     * @param <R>          the type of function applied to element of {@code T} type
     * @param list         list of elements
     * @return left fold of list elements divided by threadsCount parts
     * @throws InterruptedException throws {@link InterruptedException} like all parallel functions
     *
     * @see ru.ifmo.ctddev.filippov.parallelmapper.Monoid
     */
    @SuppressWarnings("unchecked")
    public static <T, R> R foldl(int threadsCount,
                                  Monoid<R> monoid,
                                  Function<List<T>, R> function,
                                  Optional<ParallelMapper> mapper,
                                  final List<? extends T> list) throws InterruptedException {
        assert threadsCount >= 1;
        final int size = list.size();
        threadsCount = Math.min(threadsCount, size);
        final List<R> linearOrder = new ArrayList<>(threadsCount);
        for (int i = 0; i < threadsCount; i++) {
            linearOrder.add(null);
        }

        class Worker {
            final int i;
            final List<? extends T>  subList;

            Worker(int i, List<? extends T> subList) {
                this.i = i;
                this.subList = subList;
            }

            public R apply() {
                return function.apply((List<T>) this.subList);
            }
        }

        ArrayList<Worker> workers = new ArrayList<>();
        for (int i = 0; i < threadsCount; i++) {
            int leftBound = i * (size / threadsCount);
            int rightBound = i == threadsCount - 1 ? size : (i + 1) * (size / threadsCount);
            workers.add(i, new Worker(i, list.subList(leftBound, rightBound)));
        }
        if (mapper.isPresent()) {
            List<R> newList = mapper.get().<List<T>, R>map(function, workers.stream().map(a -> (List<T>) a.subList).collect(Collectors.toList()));
            linearOrder.clear();
            linearOrder.addAll(newList);
        } else {
            ArrayList<Thread> threads = new ArrayList<>(threadsCount);
            for (int i = 0; i < threadsCount; i++) {
                final int finalI = i;
                threads.add(i, new Thread(new Runnable() {
                    @Override
                    public void run() {
                        R result = workers.get(finalI).apply();
                        linearOrder.set(finalI, result);
                    }
                }));
                threads.get(i).start();
            }
            for (int i = 0; i < threadsCount; i++) {
                threads.get(i).join();
            }
        }

        R value = monoid.getIdentityElement().orElse(() -> (R) list.get(0)).get();
        for (int i = 0; i < threadsCount; i++) {
            value = monoid.getOperation().apply(value, linearOrder.get(i));
        }
        return value;
    }

    /**
     * Method that returns left fold by {@code threads}, {@code monoid}, {@code function} and {@code list} of elements
     *
     * @param threads  count of threads that list should be divide to
     * @param monoid   monoid with some binary operation
     * @param list     list of elements
     * @param <T>      type of elements in the list
     * @return left fold of list elements divided by threads parts with {@code function} and monoid with binary operation {@code operation}
     * @throws InterruptedException throws {@link InterruptedException} like all parallel functions
     *
     * @see ru.ifmo.ctddev.filippov.parallelmapper.Monoid
     */
    public static <T> T foldl(int threads, final Monoid<T> monoid, final List<? extends T> list) throws InterruptedException {
        return foldl(
                threads,
                monoid,
                someList -> {
                    T value;
                    if (monoid.haveIdentityElement()) {
                        value = monoid.getIdentityElement().get().get();
                    } else {
                        value = someList.get(0);
                    }
                    for (int i = monoid.haveIdentityElement() ? 0 : 1; i < someList.size(); i++) {
                        value = monoid.getOperation().apply(value, someList.get(i));
                    }
                    return value;
                },
                Optional.empty(),
                list
        );
    }

    /**
     * Method that returns left fold by threads, binary operation and list
     *
     * @param threads   count of threads that list should be divide to
     * @param operation binary operation that must be applied to elements
     * @param list      list of elements
     * @param <T>       type of element in list
     * @return left fold of list elements divided by threads parts with function equal to Optional.empty() and monoid with binary operation {@code operation}
     * @throws InterruptedException throws {@link InterruptedException} like all parallel functions
     *
     * @see ru.ifmo.ctddev.filippov.parallelmapper.Monoid
     */
    public static <T> T foldl(int threads, BinaryOperator<T> operation, List<? extends T> list) throws InterruptedException {
        assert !list.isEmpty();
        return foldl(threads, new Monoid<>(operation), list);
    }

    /**
     * Method that applies function to all elements in list
     *
     * @param threads  count of threads that list should be divide to
     * @param function binary function that must be applied to all elements in list
     * @param list     list of elements
     * @param <T>      type of elements in list
     * @param <R>      type of result of applying function to some element of type {@code T}
     * @return new list with new elements that achieved from applying function to old elements
     * @throws InterruptedException throws {@link InterruptedException} like all parallel functions
     */
    @SuppressWarnings("unchecked")
    public static <T, R> List<R> map(int threads, Function<? super T, ? extends R> function, List<? extends T> list) throws InterruptedException {
        return foldl(
                threads,
                Monoid.<R>listConcatenation(),
                (List<T> someList) -> someList.stream().map(function).collect(Collectors.toList()),
                Optional.empty(),
                list
        );
    }

    /**
     * Folds sublists of given list, got from applying function {@code mapper}, with the monoid function and
     * identity element (if monoid is complete)
     *
     * @param threads number of threads
     * @param monoid monoid for joining sublists
     * @param mapper  function to process sublist
     * @param list    list to map
     * @param <T>     type of elements of given list
     * @param <R>     type of function result
     * @return folded list
     * @throws InterruptedException throws {@link InterruptedException} like all parallel functions
     */
    public static <T, R> R concatmap(int threads, Monoid<R> monoid, Function<List<T>, R> mapper, List<? extends T> list) throws InterruptedException {
        return foldl(threads, monoid, mapper, Optional.empty(), list);
    }
}
