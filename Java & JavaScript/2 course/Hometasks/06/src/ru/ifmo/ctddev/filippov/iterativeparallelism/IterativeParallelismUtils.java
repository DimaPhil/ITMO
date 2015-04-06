package ru.ifmo.ctddev.filippov.iterativeparallelism;

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
 * @see ru.ifmo.ctddev.filippov.iterativeparallelism.Monoid
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
     * @param function     function that applies to list elements
     * @param monoid       monoid with identity element and binary operation
     * @param <T>          type of elements in list
     * @param <R>          the type of function applied to element of {@code T} type
     * @param list         list of elements
     * @return left fold of list elements divided by threadsCount parts
     * @see ru.ifmo.ctddev.filippov.iterativeparallelism.Monoid
     */
    @SuppressWarnings("unchecked")
    private static <T, R> R foldl(int threadsCount, Optional<Function<List<T>, R>> function, final Monoid<R> monoid, final List<T> list) {
        final int size = list.size();
        assert threadsCount >= 1;
        threadsCount = Math.min(threadsCount, size);
        R[] linearOrder = (R[]) new Object[threadsCount];
        ArrayList<Thread> threads = new ArrayList<>(threadsCount);
        for (int i = 0; i < threadsCount; i++) {
            final int finalIndex = i;
            final int finalLeftBound = i * (size / threadsCount);
            final int finalRightBound = (i == threadsCount - 1) ? size : (i + 1) * (size / threadsCount);
            threads.add(i, new Thread(new Runnable() {
                final int index = finalIndex;
                final int leftBound = finalLeftBound;
                final int rightBound = finalRightBound;

                @Override
                public void run() {
                    List<T> subList = list.subList(leftBound, rightBound);
                    R value;
                    if (function.isPresent()) {
                        value = function.get().apply(subList);
                    } else {
                        if (monoid.haveIdentityElement()) {
                            value = monoid.getIdentityElement().get().get();
                        } else {
                            value = (R) subList.get(0);
                        }
                        for (int i = monoid.haveIdentityElement() ? 0 : 1; i < subList.size(); i++) {
                            value = monoid.getOperation().apply(value, (R) subList.get(i));
                        }
                    }
                    linearOrder[index] = value;
                }
            }));
        }
        threads.stream().forEach(Thread::start);
        R value = monoid.getIdentityElement().orElse(() -> (R) list.get(0)).get();
        for (int i = 0; i < threadsCount; i++) {
            try {
                threads.get(i).join();
                value = monoid.getOperation().apply(value, linearOrder[i]);
            } catch (InterruptedException e) {
                System.out.println(e.toString());
            }

        }
        return value;
    }

    /**
     * Method that returns left fold by {@code threads}, {@code monoid}, {@code function} and {@code list} of elements
     *
     * @param threads  count of threads that list should be divide to
     * @param monoid   monoid with some binary operation
     * @param function binary function from list to value that must be applied to all elements in {@code list}
     * @param list     list of elements
     * @param <T>      type of elements in the list
     * @param <R>      the type of function applied to the element of {@code T} type
     * @return left fold of list elements divided by threads parts with {@code function} and monoid with binary operation {@code operation}
     * @see ru.ifmo.ctddev.filippov.iterativeparallelism.Monoid
     */
    public static <T, R> R foldl(int threads, Monoid<R> monoid, Function<List<T>, R> function, List<T> list) {
        return foldl(threads, Optional.of(function), monoid, list);
    }

    /**
     * returns left fold by threadsCount, monoid and list of elements
     * function is equal to Optional.empty()
     *
     * @param threads count of threads that list should be divided to
     * @param monoid  monoid with identity element and binary operation
     * @param list    list of elements
     * @param <T>     the type of elements in list
     * @return left fold of list elements divided by threads parts with function equal to Optional.empty()
     * @see ru.ifmo.ctddev.filippov.iterativeparallelism.Monoid
     */
    public static <T> T foldl(int threads, final Monoid<T> monoid, final List<T> list) {
        return foldl(threads, Optional.empty(), monoid, list);
    }

    /**
     * Method that returns left fold by threads, binary operation and list
     *
     * @param threads   count of threads that list should be divide to
     * @param operation binary operation that must be applied to elements
     * @param list      list of elements
     * @param <T>       type of element in list
     * @return left fold of list elements divided by threads parts with function equal to Optional.empty() and monoid with binary operation {@code operation}
     * @see ru.ifmo.ctddev.filippov.iterativeparallelism.Monoid
     */
    public static <T> T foldl(int threads, BinaryOperator<T> operation, List<T> list) {
        assert !list.isEmpty();
        return foldl(threads, new Monoid<T>(operation), list);
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
     */
    @SuppressWarnings("unchecked")
    public static <T, R> List<R> map(int threads, Function<? super T, ? extends R> function, List<? extends T> list) {
        return foldl(
                threads,
                Optional.of((List<T> someList) -> someList.stream().map(function).collect(Collectors.toList())),
                Monoid.<R>listConcatenation(),
                (List<T>) list
        );
    }
}
