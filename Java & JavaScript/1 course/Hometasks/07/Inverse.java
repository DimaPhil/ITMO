public class Inverse extends UnaryOperation {
    public Inverse(Expression3 expr) {
        super(expr);
    }

    public int unaryOperation(int x) {
        return ~x;
    }
}
