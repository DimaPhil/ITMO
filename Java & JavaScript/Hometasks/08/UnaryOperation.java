public abstract class UnaryOperation<T extends MyNumber<T>> implements Expression3<T> {
    protected Expression3<T> a;

    public UnaryOperation(Expression3<T> a) {
        this.a = a;
    }

    @Override
    public T evaluate(T x, T y, T z) throws MyArithmeticException {
        return unaryOperation(a.evaluate(x, y, z));
    }

    protected abstract T unaryOperation(T x) throws MyArithmeticException;
}                                                                