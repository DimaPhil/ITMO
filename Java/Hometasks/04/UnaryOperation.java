public abstract class UnaryOperation implements Expression3 {
    protected Expression3 a;

    public UnaryOperation(Expression3 a) {
        this.a = a;
    }

    @Override
    public double evaluate(double x, double y, double z) {
        return unaryOperation(a.evaluate(x, y, z));
    }

    protected abstract double unaryOperation(double x);
}                                                                