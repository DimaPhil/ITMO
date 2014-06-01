public class Subtract extends BinaryOperation {
    public Subtract(Expression3 first, Expression3 second) {
        super(first, second);
    }

    public int binaryOperation(int x, int y) throws OverflowException {
        if ((x > 0 && y < 0 && -y > Integer.MAX_VALUE - x) ||
            (x < 0 && y > 0) && -y < Integer.MIN_VALUE - x) {
            throw new OverflowException("Oveflow");
        }
        return x - y;
    }
}