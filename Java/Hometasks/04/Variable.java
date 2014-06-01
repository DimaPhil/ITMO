public class Variable implements Expression3 {
    private final String name; 
    
    public Variable(String name) {
        this.name = name;
    }

    public double evaluate(double x, double y, double z) {
        if (name.equals("x")) {
            return x;
        }
        if (name.equals("y")) {
            return y;
        }
        if (name.equals("z")) {
            return z;
        }
        return 0.0;
    }
}
