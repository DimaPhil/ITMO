package ru.ifmo.ctddev.filippov.bank;

import java.rmi.RemoteException;
import java.util.function.Predicate;

public class Utils {
    public interface RemotePredicate<T> {
        Boolean apply(T value) throws RemoteException;
    }

    public static <T> Predicate<T> ignored(RemotePredicate<T> predicate, boolean defaultValue) {
        return p -> {
            boolean result = defaultValue;
            try {
                result = predicate.apply(p);
            } catch (RemoteException e) {
                System.err.println("ignored exception: " + e.toString());
            }
            return result;
        };
    }

    public static <T> Predicate<T> ignored(RemotePredicate<T> predicate) {
        return ignored(predicate, false);
    }
}