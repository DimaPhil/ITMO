public class Subtract extends BinaryOperation {
    public Subtract(Expression3 first, Expression3 second) {
        super(first, second);
    }

    public double binaryOperation(double x, double y) {
        return x - y;
    }
}