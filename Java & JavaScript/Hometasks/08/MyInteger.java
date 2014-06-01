public class MyInteger extends MyNumber<MyInteger> {
    private Integer number;

    public MyInteger(Integer number) {
        this.number = number;
    }
    public Integer getValue() {
        return number;
    }

    /* Functions */

    protected MyInteger abs() {
        return new MyInteger(Math.abs(number));
    }

    protected MyInteger add(MyInteger b) {
        return new MyInteger(number + b.getValue());
    }

    protected MyInteger divide(MyInteger b) throws DBZException {
        if (b.getValue() == 0) {
            throw new DBZException("Division by zero");
        }
        return new MyInteger(number / b.getValue());
    }

    protected MyInteger inverse() {
        return new MyInteger(~number);
    }

    protected MyInteger log() throws InvalidArgumentException {
        if (number <= 0) {
            throw new InvalidArgumentException("Invalid argument: log cannot be calced if exression is less than zero");
        }
        int lb = 0;
        int x = number;
        while (x > 1) {
          x >>= 1;
          lb++;
        }
        return new MyInteger(lb);
    }

    protected MyInteger multiply(MyInteger b) {
        return new MyInteger(number * b.getValue());
    }

    protected MyInteger power(MyInteger b) throws InvalidArgumentException {
        if (b.getValue() < 0) {
            throw new InvalidArgumentException("Invalid argument: power cannot be less than zero");
        }
        if (number == 0 || number == 1) {
            return new MyInteger(number);
        }
        if (number == -1) {
            return new MyInteger(b.getValue() % 2 == 0 ? 1 : -1);
        }

        int ans = 1;
        int pow = b.getValue();
        while (pow --> 0) {
            ans *= number;
        }
        return new MyInteger(ans);
    }

    protected MyInteger subtract(MyInteger b) {
        return new MyInteger(number - b.getValue());
    }

    protected MyInteger unaryMinus() {
        return new MyInteger(-number);
    }

    protected MyInteger parse(String s) {
        return new MyInteger(Integer.parseInt(s));
    }
}