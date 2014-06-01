public class Multiply extends BinaryOperation {
    public Multiply(Expression3 first, Expression3 second) {
        super(first, second);
    }

    public int binaryOperation(int x, int y) {
        return x * y;
    }
}