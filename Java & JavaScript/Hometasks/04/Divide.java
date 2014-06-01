public class Divide extends BinaryOperation {
    public Divide(Expression3 first, Expression3 second) {
        super(first, second);
    }

    public double binaryOperation(double x, double y) {
        return x / y;
    }
}