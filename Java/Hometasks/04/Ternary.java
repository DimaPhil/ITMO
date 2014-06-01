public class Ternary extends TernaryOperation {
    public Ternary(Expression3 first, Expression3 second, Expression3 third) {
        super(first, second, third);
    }

    public double ternaryOperation(double x, double y, double z) {
        if (Math.abs(x) < 1e-9) {
            return y;
        } else {
            return z;
        }
    }
}