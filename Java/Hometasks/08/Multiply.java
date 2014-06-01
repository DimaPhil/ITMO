public class Multiply<T extends MyNumber<T>> extends BinaryOperation<T> {
    public Multiply(Expression3<T> first, Expression3<T> second) {
        super(first, second);
    }

    public T binaryOperation(T x, T y) {
        return x.multiply(y);
    }
}