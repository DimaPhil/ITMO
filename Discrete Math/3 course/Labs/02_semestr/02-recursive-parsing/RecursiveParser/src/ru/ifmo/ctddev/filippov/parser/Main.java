package ru.ifmo.ctddev.filippov.parser;

/**
 * Created by dmitry on 27.04.16.
 */
public class Main {
    private static Parser parser = new Parser();
    private static Visualizer visualizer = new Visualizer();

    private static void testExpression(String expression) throws ParseException {
        new Parser().parse(expression);
    }

    private static void visualizeExpression(String expression) {
        try {
            Tree result = parser.parse(expression);
            visualizer.visualize(result);
        } catch (ParseException e) {
            System.out.println(e.toString());
        }
    }

    private static String[] okExpressions = new String[]{
            "a",
            "m",
            "z",
            "a and b",
            "a xor b",
            "a or b",
            "not a",
            "(a)",
            "(a and b)",
            "((a and b))",
            "(((((a and b)))))",
            "(a and (b and (c or (not d and not c))) or not c)",
            "not not not not not b",
    };
    private static String[] failExpressions = new String[]{
            "(",
            ")",
            "(a an b)",
            "(a and (b xor ))",
            "()",
            "a and ()",
            "(a and b))"
    };

    public static void main(String[] args) {
        for (String expression : okExpressions) {
            try {
                testExpression(expression);
            } catch (ParseException e) {
                System.out.println("An error occurred on correct expression. Input: " + expression + ", error: " + e.toString());
            }
        }
        for (String expression : failExpressions) {
            try {
                testExpression(expression);
                System.out.println("Expected error at input: " + expression);
            } catch (Throwable ignored) {

            }
        }
        visualizeExpression("a and b xor c");
    }
}
