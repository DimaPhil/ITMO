public interface Expression3<T extends MyNumber<T>> {
    T evaluate(T x, T y, T z) throws MyArithmeticException;
}