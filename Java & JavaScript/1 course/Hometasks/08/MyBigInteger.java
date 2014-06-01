import java.math.*;

public class MyBigInteger extends MyNumber<MyBigInteger> {
    private BigInteger number;

    public MyBigInteger(BigInteger number) {
        this.number = number;
    }
    public BigInteger getValue() {
        return number;
    }

    /* Functions */

    protected MyBigInteger abs() {
        return new MyBigInteger(number.abs());
    }

    protected MyBigInteger add(MyBigInteger b) {
        return new MyBigInteger(number.add(b.getValue()));
    }

    protected MyBigInteger divide(MyBigInteger b) throws DBZException {
        if (b.getValue().compareTo(BigInteger.ZERO) == 0) {
            throw new DBZException("Division by zero");
        }
        return new MyBigInteger(number.divide(b.getValue()));
    }

    protected MyBigInteger inverse() {
        return new MyBigInteger(BigInteger.ZERO);
    }

    protected MyBigInteger log() throws InvalidArgumentException {
        if (number.compareTo(BigInteger.ZERO) <= 0) {
            throw new InvalidArgumentException("Invalid argument: log cannot be calced if exression is less than zero");
        }
        return new MyBigInteger(BigInteger.ZERO);
    }

    protected MyBigInteger multiply(MyBigInteger b) {
        return new MyBigInteger(number.multiply(b.getValue()));
    }

    protected MyBigInteger power(MyBigInteger b) throws InvalidArgumentException {
        if (b.getValue().compareTo(BigInteger.ZERO) == -1) {
            throw new InvalidArgumentException("Invalid argument: power cannot be less than zero");
        }
        if (number == BigInteger.ZERO || number == BigInteger.ONE) {
            return new MyBigInteger(number);
        }
        if (number == BigInteger.ONE.negate()) {
            return new MyBigInteger(b.getValue().mod(BigInteger.valueOf(2)) == BigInteger.ZERO ? BigInteger.ONE : BigInteger.ONE.negate());
        }

        BigInteger ans = BigInteger.ONE;
        BigInteger pow = b.getValue();
        while (pow.compareTo(BigInteger.ZERO) == 1) {
            ans = ans.multiply(number);
            pow = pow.subtract(BigInteger.ONE);
        }
        return new MyBigInteger(ans);
    }

    protected MyBigInteger subtract(MyBigInteger b) {
        return new MyBigInteger(number.subtract(b.getValue()));
    }

    protected MyBigInteger unaryMinus() {
        return new MyBigInteger(number.negate());
    }

    protected MyBigInteger parse(String s) {
        return new MyBigInteger(new BigInteger(s));
    }
}