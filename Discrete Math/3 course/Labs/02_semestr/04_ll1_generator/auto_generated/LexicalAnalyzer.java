import java.io.*;

public class LexicalAnalyzer{
    private InputStream is;
    private int curChar;
    private int curPos;
    private Token curToken;

    public LexicalAnalyzer(InputStream is) throws ParseException {
        this.is = is;
        curPos = 0;
        nextChar();
    }

    private boolean isBlank(int c) {
        return c == -1 || c == ' ' || c == '\r' || c == '\n' || c == '\t';
    }

    private void nextChar() throws ParseException {
        curPos++;
        try {
            curChar = is.read();
        } catch (IOException e) {
            throw new ParseException(e.getMessage(), curPos);
        }
    }

    public Token getCurToken() {
        return curToken;
    }

    public int getCurPos() {
        return curPos;
    }

    public void nextToken() throws ParseException {
        if (curChar == -1) {
            curToken = Token.END;
            return;
        }
        while (isBlank(curChar)) {
            nextChar();
        }
        StringBuilder sb = new StringBuilder();
        sb.append((char) curChar);
        if (curChar >= 'a' && curChar <= 'z') {
            nextChar();
            while (!isBlank(curChar) && curChar != '(' && curChar != ')') {
                sb.append((char) curChar);
                nextChar();
            }
        } else {
            nextChar();
        }
        String token = sb.toString();

        switch (token) {
            case "not":
                curToken = Token.NOT;
                break;
            case "or":
                curToken = Token.OR;
                break;
            case "a":
                curToken = Token.VAR;
                break;
            case "b":
                curToken = Token.VAR;
                break;
            case "c":
                curToken = Token.VAR;
                break;
            case "d":
                curToken = Token.VAR;
                break;
            case "and":
                curToken = Token.AND;
                break;
            case ")":
                curToken = Token.RIGHT_PAREN;
                break;
            case "":
                curToken = Token.EPS;
                break;
            case "xor":
                curToken = Token.XOR;
                break;
            case "$":
                curToken = Token.END;
                break;
            case "(":
                curToken = Token.LEFT_PAREN;
                break;
        }
    }
}
