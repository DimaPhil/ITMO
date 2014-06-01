public abstract class BinaryOperation implements Expression3 {
    protected Expression3 a, b;

    public BinaryOperation(Expression3 a, Expression3 b) {
        this.a = a;
        this.b = b;
    }

    @Override
    public double evaluate(double x, double y, double z) {
        return binaryOperation(a.evaluate(x, y, z), b.evaluate(x, y, z));
    }

    protected abstract double binaryOperation(double x, double y);
}                                                                