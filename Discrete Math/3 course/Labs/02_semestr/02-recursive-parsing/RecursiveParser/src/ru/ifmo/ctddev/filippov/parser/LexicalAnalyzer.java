package ru.ifmo.ctddev.filippov.parser;

public class LexicalAnalyzer {
    public enum Token {
        LPAREN, RPAREN, VARIABLE, AND, OR, XOR, NOT, END
    }

    private char[] expression;
    private int curPos;
    private char curChar;
    Token curToken;

    private boolean isBlank(int c) {
        return c == ' ' || c == '\r' || c == '\n' || c == '\t';
    }

    private String skipBlank(String s) {
        StringBuilder ns = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (!isBlank(s.charAt(i))) {
                ns.append(s.charAt(i));
            }
        }
        return ns.toString();
    }

    public LexicalAnalyzer(String expression) {
        this.expression = skipBlank(expression).toCharArray();
        this.curPos = 0;
        try {
            nextToken();
        } catch (ParseException e) {
            System.out.println(e.toString());
        }
    }

    public Token predictToken() throws ParseException {
        Token lastToken = curToken;
        int symbols = nextToken();
        Token result = curToken;
        curToken = lastToken;
        curPos -= symbols;
        return result;
    }

    public int nextToken() throws ParseException {
        if (curPos >= expression.length) {
            curToken = Token.END;
            curChar = '$';
            return 0;
        }
        if (curPos + 2 < expression.length && expression[curPos] == 'a' &&
                expression[curPos + 1] == 'n' && expression[curPos + 2] == 'd') {
            curToken = Token.AND;
            curChar = expression[curPos];
            curPos += 3;
            return 3;
        } else if (curPos + 1 < expression.length && expression[curPos] == 'o' && expression[curPos + 1] == 'r') {
            curToken = Token.OR;
            curChar = expression[curPos];
            curPos += 2;
            return 2;
        } else if (curPos + 2 < expression.length && expression[curPos] == 'x' && expression[curPos + 1] == 'o' &&
                expression[curPos + 2] == 'r') {
            curToken = Token.XOR;
            curChar = expression[curPos];
            curPos += 3;
            return 3;
        } else if (curPos + 2 < expression.length && expression[curPos] == 'n' && expression[curPos + 1] == 'o' &&
                expression[curPos + 2] == 't') {
            curToken = Token.NOT;
            curChar = expression[curPos];
            curPos += 3;
            return 3;
        } else if (Character.isLetter(expression[curPos])) {
            curToken = Token.VARIABLE;
            curChar = expression[curPos];
            curPos++;
            return 1;
        } else if (expression[curPos] == '(') {
            curToken = Token.LPAREN;
            curChar = expression[curPos];
            curPos++;
            return 1;
        } else if (expression[curPos] == ')') {
            curToken = Token.RPAREN;
            curChar = expression[curPos];
            curPos++;
            return 1;
        } else {
            throw new ParseException("Wrong symbol - " + expression[curPos], curPos);
        }
    }

    public Token getCurToken() {
        return curToken;
    }

    public int getCurPos() {
        return curPos;
    }

    public char getCurChar() {
        return curChar;
    }
}
