package ru.ifmo.ctddev.filippov.parser;

import static ru.ifmo.ctddev.filippov.parser.LexicalAnalyzer.Token.AND;
import static ru.ifmo.ctddev.filippov.parser.LexicalAnalyzer.Token.OR;
import static ru.ifmo.ctddev.filippov.parser.LexicalAnalyzer.Token.XOR;

/**
 * Created by dmitry on 23.03.16.
 */
public class Parser {
    private LexicalAnalyzer analyzer;

    private boolean isOperationToken(LexicalAnalyzer.Token token) {
        return token == AND ||
                token == LexicalAnalyzer.Token.OR ||
                token == LexicalAnalyzer.Token.XOR;
    }

    private String getOperation(LexicalAnalyzer.Token token) {
        if (token == AND) {
            return "and";
        }
        if (token == OR) {
            return "or";
        }
        if (token == XOR) {
            return "xor";
        }
        return "wrong operation";
    }

    Tree S() throws ParseException {
        if (analyzer.getCurToken() == LexicalAnalyzer.Token.LPAREN) {
            analyzer.nextToken();
            char curChar = analyzer.getCurChar();
            Tree sub = S();
            analyzer.nextToken();
            if (analyzer.getCurToken() != LexicalAnalyzer.Token.RPAREN) {
                throw new ParseException(") expected", analyzer.getCurPos());
            }
            if (!isOperationToken(analyzer.predictToken())) {
                return new Tree("S, " + curChar, new Tree("("), sub, new Tree(")"));
            }
            analyzer.nextToken();
            Tree cont = SPrime();
            return new Tree("S, " + curChar, new Tree("("), sub, new Tree(")"), cont);
        }
        if (analyzer.getCurToken() == LexicalAnalyzer.Token.NOT) {
            analyzer.nextToken();
            Tree sub = S();
            if (!isOperationToken(analyzer.predictToken())) {
                return new Tree("S, not", sub);
            }
            analyzer.nextToken();
            Tree cont = SPrime();
            return new Tree("S, not", sub, cont);
        }
        if (analyzer.getCurToken() == LexicalAnalyzer.Token.VARIABLE) {
            char curChar = analyzer.getCurChar();
            if (!isOperationToken(analyzer.predictToken())) {
                return new Tree("S, " + curChar);
            }
            analyzer.nextToken();
            Tree cont = SPrime();
            return new Tree("S, " + curChar, cont);
        }
        throw new ParseException("Expected LPAREN, NOT or VARIABLE at S(), index: " + analyzer.getCurPos());
    }

    Tree SPrime() throws ParseException {
        if (analyzer.getCurToken() == LexicalAnalyzer.Token.END) {
            return new Tree("S', end");
        }
        if (isOperationToken(analyzer.getCurToken())) {
            String operation = getOperation(analyzer.getCurToken());
            analyzer.nextToken();
            Tree sub = S();
            if (!isOperationToken(analyzer.predictToken())) {
                return new Tree("S', " + operation, sub);
            }
            analyzer.nextToken();
            Tree cont = SPrime();
            return new Tree("S', " + operation, sub, cont);
        }
        return new Tree("S', eps");
    }

    Tree parse(String expression) throws ParseException {
        analyzer = new LexicalAnalyzer(expression);
        return S();
    }
}