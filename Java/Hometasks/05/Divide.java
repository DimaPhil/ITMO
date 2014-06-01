public class Divide extends BinaryOperation {
    public Divide(Expression3 first, Expression3 second) {
        super(first, second);
    }

    public int binaryOperation(int x, int y) {
        return x / y;
    }
}