public class UnaryMinus extends UnaryOperation {
    public UnaryMinus(Expression3 expr) {
        super(expr);
    }

    public double unaryOperation(double x) {
        return -x;
    }
}
