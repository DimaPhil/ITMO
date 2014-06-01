public class Variable implements Expression3 {
    private final String name; 
    
    public Variable(String name) {
        this.name = name;
    }

    public int evaluate(int x, int y, int z) {
        if (name.equals("x")) {
            return x;
        }
        if (name.equals("y")) {
            return y;
        }
        if (name.equals("z")) {
            return z;
        }
        return 0;
    }
}
