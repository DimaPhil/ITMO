public class Multiply extends BinaryOperation {
    public Multiply(Expression3 first, Expression3 second) {
        super(first, second);
    }

    public int binaryOperation(int x, int y) throws OverflowException {
        if (x == 0 || y == 0) {
            return 0;
        }
        if ((x * y) / y != x) {
            throw new OverflowException("Overflow");
        }
        return x * y;
    }
}