public class Log<T extends MyNumber<T>> extends UnaryOperation<T> {
    public Log(Expression3<T> expr) {
        super(expr);
    }

    public T unaryOperation(T x) throws InvalidArgumentException {
        return x.log();
    }
}
