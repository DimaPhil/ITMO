package ru.ifmo.ctddev.filippov.parallelmapper;

import java.util.LinkedList;
import java.util.List;
import java.util.Optional;
import java.util.function.BiPredicate;
import java.util.function.BinaryOperator;
import java.util.function.Supplier;

/**
 * Class represents realisation of Monoid - set with one identity element and one binary operation
 *
 * Binary operation may be not associative, identity element may be strange, monoid also can contains no identity element.
 * Identity elements have type {@link java.util.Optional} and operation have type {@link java.util.function.BinaryOperator}
 *
 * @author Dmitry Philippov
 */
public class Monoid<T> {
    private final Optional<Supplier<T>> identityElement;
    private final BinaryOperator<T> operation;

    /**
     * returns entry of Monoid class by two parameters - identityElement and binary operation
     *
     * @param identityElement identity element of monoid
     * @param operation binary operation of monoid
     */
    public Monoid(Supplier<T> identityElement, BinaryOperator<T> operation) {
        this.identityElement = Optional.of(identityElement);
        this.operation = operation;
    }

    /**
     * returns entry of Monoid class by one parameter - binary operation
     *
     * @param operation binary operation of monoid
     */
    public Monoid(BinaryOperator<T> operation) {
        this.identityElement = Optional.empty();
        this.operation = operation;
    }

    /**
     * @return identity element of monoid
     */
    public Optional<Supplier<T>> getIdentityElement() {
        return identityElement;
    }

    /**
     * @return binary operation of monoid
     */
    public BinaryOperator<T> getOperation() {
        return operation;
    }

    /**
     * @return is monoid have identity element
     */
    public boolean haveIdentityElement() {
        return identityElement.isPresent();
    }

    /**
     * method that returns monoid with binary operation - list concatenation
     *
     * @param <T> the type of elements in list of return monoid
     * @return monoid with identity element that creates new {@link java.util.LinkedList} and binary operation that concatenate two lists
     */
    public static <T> Monoid<List<T>> listConcatenation() {
        return new Monoid<>(LinkedList::new, (a, b) -> {
            a.addAll(b);
            return a;
        });
    }

    /**
     * method that takes predicate and returns monoid with binary operation - list concatenation if predicate tests them
     *
     * @param predicate some predicate that tests two lists
     * @param <T> the type of elements in list of predicate and in list of return monoid
     * @return monoid with identity element that creates new {@link java.util.LinkedList} and
     * binary operation that concatenate two lists of predicate tests them
     */
    public static <T> Monoid<List<T>> listConcatenation(BiPredicate<List<T>, List<T>> predicate) {
        return new Monoid<>(LinkedList::new, (a, b) -> {
            if (!predicate.test(a, b)) {
                return a;
            }
            a.addAll(b);
            return a;
        });
    }

    /**
     * method that returns monoid with binary operation "logical and"
     *
     * @param initValue identity element of new monoid
     * @return new monoid that have identity element equal to initValue and binary operation equal to logical and
     */
    public static Monoid<Boolean> boolAnd(boolean initValue) {
        return new Monoid<>(() -> initValue, Boolean::logicalAnd);
    }
}
