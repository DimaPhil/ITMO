public class Variable<T extends MyNumber<T>> implements Expression3<T> {
    private final String name; 
    
    public Variable(String name) {
        this.name = name;
    }

    public T evaluate(T x, T y, T z) {
        if (name.equals("x")) {
            return x;
        }
        if (name.equals("y")) {
            return y;
        }
        if (name.equals("z")) {
            return z;
        }
        throw new AssertionError("Something went wrong :(");
    }
}
