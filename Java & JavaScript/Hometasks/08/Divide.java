public class Divide<T extends MyNumber<T>> extends BinaryOperation<T> {
    public Divide(Expression3<T> first, Expression3<T> second) {
        super(first, second);
    }

    public T binaryOperation(T x, T y) throws DBZException {
        return x.divide(y);
    }
}