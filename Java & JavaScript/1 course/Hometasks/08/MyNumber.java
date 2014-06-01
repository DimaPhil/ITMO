public abstract class MyNumber<T> {
    protected abstract T abs();
    protected abstract T add(T b);
    protected abstract T divide(T b) throws DBZException;
    protected abstract T inverse();
    protected abstract T log() throws InvalidArgumentException;
    protected abstract T multiply(T b);
    protected abstract T power(T b) throws InvalidArgumentException;
    protected abstract T subtract(T b);
    protected abstract T unaryMinus();
    protected abstract T parse(String s);
    protected abstract T sinus();
}
