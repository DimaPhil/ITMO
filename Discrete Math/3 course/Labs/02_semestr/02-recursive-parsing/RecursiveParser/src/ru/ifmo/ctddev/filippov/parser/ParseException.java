package ru.ifmo.ctddev.filippov.parser;

/**
 * Created by dmitry on 23.03.16.
 */
public class ParseException extends Exception {
    public ParseException(String message) {
        super(message);
    }

    public ParseException(String message, int pos) {
        super("An error occurred while parsing at position " + pos + ": " + message);
    }
}
