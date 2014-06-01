public class Divide extends BinaryOperation {
    public Divide(Expression3 first, Expression3 second) {
        super(first, second);
    }

    public int binaryOperation(int x, int y) throws DBZException, OverflowException {
        if (x == Integer.MIN_VALUE && y == -1) {
            throw new OverflowException("Overflow");
        }
        if (y == 0) {
            throw new DBZException("Division by zero");
        }
        return x / y;
    }
}