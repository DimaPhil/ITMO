public class Multiply extends BinaryOperation {
    public Multiply(Expression3 first, Expression3 second) {
        super(first, second);
    }

    public double binaryOperation(double x, double y) {
        return x * y;
    }
}