public abstract class BinaryOperation<T extends MyNumber<T>> implements Expression3<T> {
    protected Expression3<T> a, b;

    public BinaryOperation(Expression3<T> a, Expression3<T> b) {
        this.a = a;
        this.b = b;
    }

    @Override
    public T evaluate(T x, T y, T z) throws MyArithmeticException {
        return binaryOperation(a.evaluate(x, y, z), b.evaluate(x, y, z));
    }

    protected abstract T binaryOperation(T x, T y) throws MyArithmeticException;
}                                                                