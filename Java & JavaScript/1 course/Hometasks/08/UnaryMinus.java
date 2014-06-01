public class UnaryMinus<T extends MyNumber<T>> extends UnaryOperation<T> {
    public UnaryMinus(Expression3<T> expr) {
        super(expr);
    }

    public T unaryOperation(T x) {
        return x.unaryMinus();
    }
}
