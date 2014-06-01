public class ExpressionParser {
    enum expr {
      Num, Variable, Plus, Minus, Tilda, Abs,
      Log, Power, Mul, Div, Open, Close, End;
    }

    private static String expression;
    private static expr curLexem;
    private static int value;
    private static char variableName;
    private static int index;

    private static boolean isDigit(char symbol) {
        return '0' <= symbol && symbol <= '9';
    }

    private static boolean isVariable(char symbol) {
        return (symbol == 'x' || symbol == 'y' || symbol == 'z');
    }

    private static boolean isOperation(char symbol) {
        return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
    }

    private static void parseNumber() {
        value = 0;
        while (index < expression.length() && isDigit(expression.charAt(index))) {
            value = value * 10 + (expression.charAt(index) - '0');
            index++;
        }
    }

    private static void nextLexem() throws SyntaxErrorException {
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

    private static Expression3 parseMultiplier() throws SyntaxErrorException {
        if (curLexem == expr.Minus) {
            nextLexem();
            return new UnaryMinus(parseMultiplier());
        } else if (curLexem == expr.Log) {
            nextLexem();
            return new Log(parseMultiplier());
        } else if (curLexem == expr.Tilda) {
            nextLexem();
            return new Inverse(parseMultiplier());
        } else if (curLexem == expr.Abs) {
            nextLexem();
            return new AbsoluteValue(parseMultiplier());
        } else if (curLexem == expr.Num) {
            int number = value;
            nextLexem();
            return new Const(number);
        } else if (curLexem == expr.Variable) {
            String name = String.valueOf(variableName); 
            nextLexem();
            return new Variable(name);
        } else if (curLexem == expr.Open) {
            nextLexem();
            Expression3 answer = parseExpression();
            if (curLexem != expr.Close) {
                throw new WrongBracketsSequenceException("Cannot find pair to open bracket");
            }
            nextLexem();
            return answer;                                                           
        }
        throw new ParseErrorException("Parse error at symbol " + index + ": " + expression.charAt(index));
    }

    private static Expression3 parseSummand() throws SyntaxErrorException {
        Expression3 answer = parseMultiplier();
        while (curLexem == expr.Mul || curLexem == expr.Div || curLexem == expr.Power) {
            expr c = curLexem;
            nextLexem();
            if (c == expr.Mul) {
                answer = new Multiply(answer, parseMultiplier());
            } else if (c == expr.Power) {
                answer = new Power(	answer, parseMultiplier());
            } else {
                answer = new Divide(answer, parseMultiplier());
            }
        }
        return answer;
    }

    private static Expression3 parseExpression() throws SyntaxErrorException {
        Expression3 answer = parseSummand();
        while (curLexem == expr.Plus || curLexem == expr.Minus) {
            expr c = curLexem;
            nextLexem();
            if (c == expr.Plus) {
                answer = new Add(answer, parseSummand());
            } else {
                answer = new Subtract(answer, parseSummand());
            }
        }
        return answer;
    }

    public static Expression3 parse(String s) throws SyntaxErrorException { 
        if (s.equals("")) {
            throw new EmptyExpressionException("Cannot parse empty expression");
        }
        expression = s;
        index = 0;
        nextLexem();
        Expression3 answer = parseExpression();
        if (index != expression.length()) {
            throw new ParseErrorException("Parse error at symbol " + index + ": " + expression.charAt(index));
        }
        return answer;
    }


    private static void test(String s, int x, int y, int z) {
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
    }

    public static void main(String[] args) {
        /*String expression = "";
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
        } */
        test("-(2147483648)", 3, 1, 1);
    }
}
    
