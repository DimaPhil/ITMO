public class Add<T extends MyNumber<T>> extends BinaryOperation<T> {
    public Add(Expression3<T> first, Expression3<T> second) {
        super(first, second);
    }

    public T binaryOperation(T x, T y) {
        return x.add(y);
    }
}