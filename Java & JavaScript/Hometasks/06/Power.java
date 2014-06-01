public class Power extends BinaryOperation {
    public Power(Expression3 first, Expression3 second) {
        super(first, second);
    }

    public int binaryOperation(int x, int y) throws OverflowException, InvalidArgumentException {
        if (y < 0) {
            throw new InvalidArgumentException("Invalid argument");
        }
        if (x == 0 || x == 1) {
            return x;
        }
        if (x == -1) {
            return y % 2 == 1 ? -1 : 1;
        }
        int ans = 1;
        while (y --> 0) {
            if ((ans * x) / x != ans) {
                throw new OverflowException("Overflow");
            }
            ans *= x;
        }
        return ans;
    }
}
