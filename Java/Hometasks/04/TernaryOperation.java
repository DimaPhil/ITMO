public abstract class TernaryOperation implements Expression3 {
    protected Expression3 condition, a, b;

    public TernaryOperation(Expression3 condition, Expression3 a, Expression3 b) {
        this.condition = condition;
        this.a = a;
        this.b = b;
    }

    @Override
    public double evaluate(double x, double y, double z) {
        return ternaryOperation(condition.evaluate(x, y, z), a.evaluate(x, y, z), b.evaluate(x, y, z));
    }

    protected abstract double ternaryOperation(double x, double y, double z);
}                                                                