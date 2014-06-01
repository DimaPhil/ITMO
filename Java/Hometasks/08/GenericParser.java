import java.math.*;

public class GenericParser<T extends MyNumber<T>> {
    public static void main(String[] args) {
        try {
            if (args[0].equals("-i")) {
                ExpressionParser parser = new ExpressionParser();
                Expression3<MyInteger> result = parser.parse(args[1], args[0], new MyInteger(0));
                for (int i = -100; i <= 100; i++) {
                    for (int j = -100; j <= 100; j++) {
                        try {
                            System.out.print(result.evaluate(new MyInteger(i), new MyInteger(j), new MyInteger(0)).getValue() + " ");
                        } catch (MyArithmeticException e) {
                            System.out.print("error ");
                        }
                    }
                }
                System.out.println();
            } else if (args[0].equals("-d")) {
                ExpressionParser parser = new ExpressionParser();
                Expression3<MyDouble> result = parser.parse(args[1], args[0], new MyDouble(0.0));
                for (double i = -100; i <= 100; i++) {
                    for (double j = -100; j <= 100; j++) {
                        try {
                            System.out.print(result.evaluate(new MyDouble(i), new MyDouble(j), new MyDouble(0.0)).getValue() + " ");
                        } catch (MyArithmeticException e) {
                            System.out.print("error ");
                        }
                    }
                }
                System.out.println();
            } else if (args[0].equals("-bi")) {
                ExpressionParser parser = new ExpressionParser();
                Expression3<MyBigInteger> result = parser.parse(args[1], args[0], new MyBigInteger(BigInteger.ZERO));
                for (int i = -100; i <= 100; i++) {
                    for (int j = -100; j <= 100; j++) {
                        try {
                            System.out.print(result.evaluate(new MyBigInteger(BigInteger.valueOf(i)), new MyBigInteger(BigInteger.valueOf(j)), new MyBigInteger(BigInteger.ZERO)).getValue() + " ");
                        } catch (MyArithmeticException e) {
                            System.out.print("error ");
                        }
                    }
                }
                System.out.println();
            }
        } catch (SyntaxErrorException e) {
            System.out.println("Bad tests :(");
        }
    }
}