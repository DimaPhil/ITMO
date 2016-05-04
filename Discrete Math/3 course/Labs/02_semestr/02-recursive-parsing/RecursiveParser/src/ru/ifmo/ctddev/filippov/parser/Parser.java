package ru.ifmo.ctddev.filippov.parser;

import static ru.ifmo.ctddev.filippov.parser.LexicalAnalyzer.Token.*;

/**
 * Created by dmitry on 23.03.16.
 */
public class Parser {
    private LexicalAnalyzer analyzer;

    private Tree E() throws ParseException {
        Tree sub = C();
        if (analyzer.getCurToken() == OR) {
            Tree cont = EPrime();
            return new Tree("E, or", sub, cont);
        }
        return new Tree("E -> C", sub);
    }

    private Tree EPrime() throws ParseException {
        if (analyzer.getCurToken() == OR) {
            analyzer.nextToken();
            Tree sub = C();
            if (analyzer.getCurToken() == OR) {
                Tree cont = EPrime();
                return new Tree("E', or'", sub, cont);
            } else {
                return new Tree("E', or", sub);
            }
        }
        return new Tree("E', eps");
    }

    private Tree C() throws ParseException {
        Tree sub = X();
        if (analyzer.getCurToken() == AND) {
            Tree cont = CPrime();
            return new Tree("C, and", sub, cont);
        }
        return new Tree("C -> X", sub);
    }

    private Tree CPrime() throws ParseException {
        if (analyzer.getCurToken() == AND) {
            analyzer.nextToken();
            Tree sub = X();
            if (analyzer.getCurToken() == AND) {
                Tree cont = CPrime();
                return new Tree("C', and", sub, cont);
            } else {
                return new Tree("C', and", sub);
            }
        }
        if (analyzer.getCurToken() == OR) {
            return EPrime();
        }
        return new Tree("C', eps");
    }

    private Tree X() throws ParseException {
        Tree sub = N();
        if (analyzer.getCurToken() == XOR) {
            Tree cont = XPrime();
            return new Tree("X, xor", sub, cont);
        }
        return new Tree("X -> N", sub);
    }

    private Tree XPrime() throws ParseException {
        if (analyzer.getCurToken() == XOR) {
            analyzer.nextToken();
            Tree sub = N();
            if (analyzer.getCurToken() == XOR) {
                Tree cont = XPrime();
                return new Tree("X', xor", sub, cont);
            } else {
                return new Tree("X', xor", sub);
            }
        }
        if (analyzer.getCurToken() == AND) {
            return CPrime();
        }
        if (analyzer.getCurToken() == OR) {
            return EPrime();
        }
        return new Tree("X', eps");
    }

    private Tree N() throws ParseException {
        if (analyzer.getCurToken() == VARIABLE) {
            char c = analyzer.getCurChar();
            analyzer.nextToken();
            return new Tree("N, " + c);
        }
        if (analyzer.getCurToken() == NOT) {
            analyzer.nextToken();
            Tree sub = N();
            return new Tree("N, not", new Tree("not"), sub);
        }
        if (analyzer.getCurToken() == LPAREN) {
            analyzer.nextToken();
            Tree sub = E();
            if (analyzer.getCurToken() != RPAREN) {
                throw new ParseException("expected )", analyzer.getCurPos());
            }
            analyzer.nextToken();
            return new Tree("N, (E)", new Tree("("), sub, new Tree(")"));
        }
        throw new ParseException("expected (, not or variable at N()", analyzer.getCurPos());
    }

    Tree parse(String expression) throws ParseException {
        analyzer = new LexicalAnalyzer(expression);
        return E();
    }
}
