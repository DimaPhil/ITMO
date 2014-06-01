public class Add extends BinaryOperation {
    public Add(Expression3 first, Expression3 second) {
        super(first, second);
    }

    public int binaryOperation(int x, int y) {
        return x + y;
    }
}