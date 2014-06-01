public abstract class UnaryOperation implements Expression3 {
    protected Expression3 a;

    public UnaryOperation(Expression3 a) {
        this.a = a;
    }

    @Override
    public int evaluate(int x, int y, int z) throws MyArithmeticException {
        return unaryOperation(a.evaluate(x, y, z));
    }

    protected abstract int unaryOperation(int x) throws MyArithmeticException;
}                                                                