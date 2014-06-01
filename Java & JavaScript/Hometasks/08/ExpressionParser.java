import java.math.*;

public class ExpressionParser<T extends MyNumber<T>> {
    enum expr {
      Num, Variable, Plus, Minus, Tilda, Abs,
      Log, Power, Mul, Div, Open, Close, End;
    }

    private String expression;
    private expr curLexem;
    T value;
    private char variableName;
    private int index;
    private String type;

    private boolean isDigit(char symbol) {
        return '0' <= symbol && symbol <= '9';
    }

    private boolean isVariable(char symbol) {
        return (symbol == 'x' || symbol == 'y' || symbol == 'z');
    }

    private boolean isOperation(char symbol) {
        return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
    }

    private void parseNumber() {
        if (type.equals("-i")) {
            String tmp = "";
            while (index < expression.length() && isDigit(expression.charAt(index))) {
                tmp += expression.charAt(index++);
            }
            value = value.parse(tmp);
        } else if (type.equals("-d")) {
            String tmp = "";
            while (index < expression.length() && (isDigit(expression.charAt(index)) || expression.charAt(index) == '.')) {
                tmp += expression.charAt(index++);
            }
            if (index < expression.length() && expression.charAt(index) == 'E') {
                tmp += expression.charAt(index++);
                if (expression.charAt(index) == '-' || expression.charAt(index) == '+') {
                    tmp += expression.charAt(index++);
                }
                while (index < expression.length() && isDigit(expression.charAt(index))) {
                    tmp += expression.charAt(index++);
                }
            }
            value = value.parse(tmp);
        } else if (type.equals("-bi")) {
            String tmp = "";
            while (index < expression.length() && isDigit(expression.charAt(index))) {
                tmp += expression.charAt(index++);
            }
            value = value.parse(tmp);
        }
    }

    private void nextLexem() throws SyntaxErrorException {
        while (index < expression.length() && Character.isWhitespace(expression.charAt(index))) {
            index++;
        }
        if (index >= expression.length()) {
            curLexem = expr.End;
            return;
        }    
        char symbol = expression.charAt(index);
        if (isDigit(symbol)) {
            curLexem = expr.Num;
            parseNumber();
            index--;
        } else if (isVariable(symbol)) {
            curLexem = expr.Variable;
            variableName = symbol;
        } else if (symbol == '+') {
            curLexem = expr.Plus;
        } else if (symbol == '-') {
            curLexem = expr.Minus;
        } else if (symbol == '^') {
            curLexem = expr.Power;
        } else if (symbol == 'l') {
            if (expression.substring(index, index + 2).equals("lb")) {
                curLexem = expr.Log;
                index++;
            }
        } else if (symbol == '~') {
            curLexem = expr.Tilda;
        } else if (symbol == 'a') {
            if (expression.substring(index, index + 3).equals("abs")) {
                curLexem = expr.Abs;
                index += 2;
            }                 
        } else if (symbol == '*') {
            curLexem = expr.Mul;
        } else if (symbol == '/') {
            curLexem = expr.Div;
        } else if (symbol == '(') {
            curLexem = expr.Open;
        } else if (symbol == ')') {
            curLexem = expr.Close;
        } else {
            throw new WrongSymbolException("Wrong symbol at position " + index + ": " + symbol);
        }
        index++;
    }                

    private Expression3<T> parseMultiplier() throws SyntaxErrorException {
        if (curLexem == expr.Minus) {
            nextLexem();
            return new UnaryMinus<T>(parseMultiplier());
        } else if (curLexem == expr.Log) {
            nextLexem();
            return new Log<T>(parseMultiplier());
        } else if (curLexem == expr.Tilda) {
            nextLexem();
            return new Inverse<T>(parseMultiplier());
        } else if (curLexem == expr.Abs) {
            nextLexem();
            return new AbsoluteValue<T>(parseMultiplier());
        } else if (curLexem == expr.Num) {
            T number = value;
            nextLexem();
            return new Const<T>(number);
        } else if (curLexem == expr.Variable) {
            String name = String.valueOf(variableName); 
            nextLexem();
            return new Variable<T>(name);
        } else if (curLexem == expr.Open) {
            nextLexem();
            Expression3<T> answer = parseExpression();
            if (curLexem != expr.Close) {
                throw new WrongBracketsSequenceException("Cannot find pair to open bracket");
            }
            nextLexem();
            return answer;                                                           
        }
        throw new ParseErrorException("Parse error at symbol " + index + ": " + expression.charAt(index));
    }

    private Expression3<T> parseSummand() throws SyntaxErrorException {
        Expression3<T> answer = parseMultiplier();
        while (curLexem == expr.Mul || curLexem == expr.Div || curLexem == expr.Power) {
            expr c = curLexem;
            nextLexem();
            if (c == expr.Mul) {
                answer = new Multiply<T>(answer, parseMultiplier());
            } else if (c == expr.Power) {
                answer = new Power<T>(answer, parseMultiplier());
            } else {
                answer = new Divide<T>(answer, parseMultiplier());
            }
        }
        return answer;
    }

    private Expression3<T> parseExpression() throws SyntaxErrorException {
        Expression3<T> answer = parseSummand();
        while (curLexem == expr.Plus || curLexem == expr.Minus) {
            expr c = curLexem;
            nextLexem();
            if (c == expr.Plus) {
                answer = new Add<T>(answer, parseSummand());
            } else {
                answer = new Subtract<T>(answer, parseSummand());
            }
        }
        return answer;
    }

    public Expression3<T> parse(String s, String expressionType, T typeValue) throws SyntaxErrorException { 
        if (s.equals("")) {
            throw new EmptyExpressionException("Cannot parse empty expression");
        }
        expression = s;
        type = expressionType;
        value = typeValue;
        index = 0;
        nextLexem();
        Expression3<T> answer = parseExpression();
        if (index != expression.length()) {
            throw new ParseErrorException("Parse error at symbol " + index + ": " + expression.charAt(index));
        }
        return answer;
    }


    /*private void test(String s, int x, int y, int z) {
        expression = s;
        try {
            Expression3 result = parse(expression);
            try {
                int answer = result.evaluate(x, y, z);
                System.out.println(answer);
            } catch (MyArithmeticException e) {
                System.out.println(e.getMessage());
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    } */

    /*public static void main(String[] args) {
        String expression = "";
        try {
            Expression3 result = parse(expression);
            for (int x = 0; x <= 10; x++) {
                System.out.print(x + ": ");
                try {
                    int answer = result.evaluate(x, 0, 0);
                    System.out.println(answer);
                } catch (MyArithmeticException e) {
                    System.out.println(e.getMessage());
                }
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        test("-(2147483648)", 3, 1, 1);
    } */
}
    
