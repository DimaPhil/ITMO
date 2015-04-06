package ru.ifmo.ctddev.filippov.iterativeparallelism;

import info.kgeorgiy.java.advanced.concurrent.ListIP;

import java.util.*;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.stream.Collectors;

/**
 * This class represents functions that can be executed simultaneously in the given number
 * of distinct threads.
 * <p>
 * <p>
 * It uses functions from {@link IterativeParallelismUtils} to parallel it's functions (like {@code foldl} and {@code map}).
 * Some functions also use implementation of monoid - {@link Monoid} class.
 * </p>
 *
 * @author Dmitry Philippov
 * @see ru.ifmo.ctddev.filippov.iterativeparallelism.IterativeParallelismUtils
 * @see ru.ifmo.ctddev.filippov.iterativeparallelism.Monoid
 */
public class IterativeParallelism implements ListIP {
    /**
     * Concatenates elements from list to string
     *
     * @param threads count of threads process should be divide to
     * @param values  list of elements which we need to concatenate
     * @return string, containing concatenation of elements from list
     * @throws InterruptedException throws {@link InterruptedException} like all parallel functions
     */
    @Override
    public String concat(int threads, List<?> values) throws InterruptedException {
        return String.join("", IterativeParallelismUtils.map(threads, Object::toString, values));
    }

    /**
     * Filters all elements in list by predicate
     *
     * @param threads   count of threads process should be divide to
     * @param values    list of elements which we need to filter
     * @param predicate predicate to filter elements from list
     * @param <T>       type of elements in result list
     * @return new list, that contains only elements that tests predicate
     * @throws InterruptedException throws {@link InterruptedException} like all parallel functions
     */
    @Override
    public <T> List<T> filter(int threads, List<? extends T> values, Predicate<? super T> predicate) throws InterruptedException {
        return IterativeParallelismUtils.foldl(
                threads,
                Monoid.<T>listConcatenation((a, b) -> !b.isEmpty() && predicate.test(b.get(0))),
                values.stream().map(a -> new ArrayList<T>(Arrays.asList(a))).collect(Collectors.toList())
        );
    }

    /**
     * Applies function to all elements from list
     *
     * @param threads count of threads process should be divide to
     * @param values  list of elements which we need to map
     * @param f       function that we use to map elements
     * @param <T>     type of elements from list
     * @param <U>     function result type
     * @return new list, that contains elements, obtained by applying function {@code f} to all elements from old list
     * @throws InterruptedException throws {@link InterruptedException} like all parallel functions
     */
    @Override
    public <T, U> List<U> map(int threads, List<? extends T> values, Function<? super T, ? extends U> f) throws InterruptedException {
        return IterativeParallelismUtils.map(threads, f, values);
    }

    /**
     * Returns maximum of list
     *
     * @param threads    count of threads process should be divide to
     * @param values     list of elements from which we need to find maximum
     * @param comparator comparator that compares to elements from list
     * @param <T>        type of elements from list
     * @return maximum of elements from list
     * @throws InterruptedException throws {@link InterruptedException} like all parallel functions
     */
    @Override
    @SuppressWarnings("unchecked")
    public <T> T maximum(int threads, List<? extends T> values, Comparator<? super T> comparator) throws InterruptedException {
        return IterativeParallelismUtils.<T>foldl(threads, (a, b) -> comparator.compare(a, b) < 0 ? b : a, (List<T>) values);
    }

    /**
     * Returns minimum of list
     *
     * @param threads    count of threads process should be divide to
     * @param values     list of elements from which we need to find minimum
     * @param comparator comparator that compares to elements from list
     * @param <T>        type of elements from list
     * @return minimum of elements from list
     * @throws InterruptedException throws {@link InterruptedException} like all parallel functions
     */
    @Override
    public <T> T minimum(int threads, List<? extends T> values, Comparator<? super T> comparator) throws InterruptedException {
        return maximum(threads, values, comparator.reversed());
    }

    /**
     * Checks if all elements tests given predicate
     *
     * @param threads   count of threads process should be divide to
     * @param values    list of elements
     * @param predicate predicate that tests one element from list
     * @param <T>       type of elements from list
     * @return true, if all elements tests predicate and false otherwise
     * @throws InterruptedException throws {@link InterruptedException} like all parallel functions
     */
    @Override
    @SuppressWarnings("unchecked")
    public <T> boolean all(int threads, List<? extends T> values, Predicate<? super T> predicate) throws InterruptedException {
        return IterativeParallelismUtils.<T, Boolean>foldl(
                threads,
                Monoid.boolAnd(true),
                a -> a.stream().<Boolean>map(predicate::test).reduce((x, y) -> x && y).get(),
                (List<T>) values
        );
    }

    /**
     * Checks if list have element that tests predicate
     *
     * @param threads   count of threads process should be divide to
     * @param values    list of elements
     * @param predicate predicate that tests one element from list
     * @param <T>       type of elements from list
     * @return true, if exist element in list that tests predicate and false otherwise
     * @throws InterruptedException throws {@link InterruptedException} like all parallel functions
     */
    @Override
    public <T> boolean any(int threads, List<? extends T> values, Predicate<? super T> predicate) throws InterruptedException {
        return !all(threads, values, predicate.negate());
    }
}
