public class UnaryMinus extends UnaryOperation {
    public UnaryMinus(Expression3 expr) {
        super(expr);
    }

    public int unaryOperation(int x) {
        return -x;
    }
}
