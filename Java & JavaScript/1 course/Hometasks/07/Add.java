public class Add extends BinaryOperation {
    public Add(Expression3 first, Expression3 second) {
        super(first, second);
    }

    public int binaryOperation(int x, int y) throws OverflowException {
        if ((x < 0 && y < 0 && y < Integer.MIN_VALUE - x) || 
            (x > 0 && y > 0 && y > Integer.MAX_VALUE - x)) {
            throw new OverflowException("Overflow");
        }
        return x + y;                                   
    }
}