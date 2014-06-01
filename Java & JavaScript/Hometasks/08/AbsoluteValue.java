public class AbsoluteValue<T extends MyNumber<T>> extends UnaryOperation<T> {
    public AbsoluteValue(Expression3<T> expr) {
        super(expr);
    }

    public T unaryOperation(T x) {
        return x.abs();
    }
}
