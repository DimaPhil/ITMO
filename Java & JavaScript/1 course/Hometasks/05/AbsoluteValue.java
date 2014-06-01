public class AbsoluteValue extends UnaryOperation {
    public AbsoluteValue(Expression3 expr) {
        super(expr);
    }

    public int unaryOperation(int x) {
        return Math.abs(x);
    }
}
