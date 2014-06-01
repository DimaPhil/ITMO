public class Log extends UnaryOperation {
    public Log(Expression3 expr) {
        super(expr);
    }

    public int unaryOperation(int x) throws InvalidArgumentException {
        if (x <= 0) {
            throw new InvalidArgumentException("Invalid argument");
        }
        int lb = 0;
        while (x > 1) {
            x >>= 1;
            lb++;
        }
        return lb;
    }
}
