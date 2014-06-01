public class ExpressionParser {
    enum expr {
      Num, Variable, Plus, Minus, Tilda, Abs,
      Mul, Div, Open, Close, End;
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

    private static void parseNumber() {
        value = 0;
        while (index < expression.length() && isDigit(expression.charAt(index))) {
            value = value * 10 + (expression.charAt(index) - '0');
            index++;
        }
    }

    private static void nextLexem() {
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
        }
        index++;
    }                

    private static Expression3 parseMultiplier() {
        if (curLexem == expr.Minus) {
            nextLexem();
            return new UnaryMinus(parseMultiplier());
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
            assert curLexem == expr.Close;
            nextLexem();
            return answer;
        } else {
            assert false;
        }
        return null;
    }

    private static Expression3 parseSummand() {
        Expression3 answer = parseMultiplier();
        while (curLexem == expr.Mul || curLexem == expr.Div) {
            expr c = curLexem;
            nextLexem();
            if (c == expr.Mul) {
                answer = new Multiply(answer, parseMultiplier());
            } else {
                answer = new Divide(answer, parseMultiplier());
            }
        }
        return answer;
    }

    private static Expression3 parseExpression() {
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

    public static Expression3 parse(String s) { 
        expression = s;
        index = 0;
        nextLexem();
        return parseExpression();
    }

    public static void main(String[] args) {
        Expression3 actual = parse("2048");
        System.out.println("Ans = " + actual.evaluate(0, 0, 0));
    }
}
    
