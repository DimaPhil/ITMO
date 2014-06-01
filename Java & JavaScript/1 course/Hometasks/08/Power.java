public class Power<T extends MyNumber<T>> extends BinaryOperation<T> {
    public Power(Expression3<T> first, Expression3<T> second) {
        super(first, second);
    }

    public T binaryOperation(T x, T y) throws InvalidArgumentException {
        return x.power(y);
    }
}
