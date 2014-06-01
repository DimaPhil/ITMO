public class MyDouble extends MyNumber<MyDouble> {
    private Double number;

    public MyDouble(Double number) {
        this.number = number;
    }
    public Double getValue() {
        return number;
    }

    /* Functions */

    protected MyDouble abs() {
        return new MyDouble(Math.abs(number));
    }

    protected MyDouble add(MyDouble b) {
        return new MyDouble(number + b.getValue());
    }

    protected MyDouble divide(MyDouble b) throws DBZException {
        return new MyDouble(number / b.getValue());
    }

    protected MyDouble inverse() {
        throw new AssertionError("Cannot calc inverse of double value");	
    }

    protected MyDouble log() throws InvalidArgumentException {
        if (number <= 0) {
            throw new InvalidArgumentException("Invalid argument: log cannot be calced if exression is less than zero");
        }
        return new MyDouble(Math.log(number) / Math.log(2));
    }

    protected MyDouble multiply(MyDouble b) {
        return new MyDouble(number * b.getValue());
    }

    protected MyDouble power(MyDouble b) throws InvalidArgumentException {
        if (b.getValue() < 0) {
            throw new InvalidArgumentException("Invalid argument: power cannot be less than zero");
        }

        return new MyDouble(Math.pow(number, b.getValue()));
    }

    protected MyDouble subtract(MyDouble b) {
        return new MyDouble(number - b.getValue());
    }

    protected MyDouble unaryMinus() {
        return new MyDouble(-number);
    }

    protected MyDouble parse(String s) {
        return new MyDouble(Double.parseDouble(s));
    }
}