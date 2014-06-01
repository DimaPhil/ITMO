public class Inverse<T extends MyNumber<T>> extends UnaryOperation<T> {
    public Inverse(Expression3<T> expr) {
        super(expr);
    }

    public T unaryOperation(T x) {
        return x.inverse();
    }
}
