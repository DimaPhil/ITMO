public class UnaryMinus extends UnaryOperation {
    public UnaryMinus(Expression3 expr) {
        super(expr);
    }

    public int unaryOperation(int x) throws OverflowException {
        if (x == Integer.MIN_VALUE) {
            throw new OverflowException("Overflow");
        }
        return -x;
    }
}
