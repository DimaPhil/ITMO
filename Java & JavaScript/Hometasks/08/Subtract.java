public class Subtract<T extends MyNumber<T>> extends BinaryOperation<T> {
    public Subtract(Expression3<T> first, Expression3<T> second) {
        super(first, second);
    }

    public T binaryOperation(T x, T y) {
        return x.subtract(y);
    }
}