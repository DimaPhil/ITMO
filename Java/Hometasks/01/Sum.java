public class Sum {
    static int add(String input) {
        String[] tmp = input.trim().split("\\s+");
        int add = 0;
        for (int i = 0; i < tmp.length; i++) {
            if (tmp[i].length() > 0) {
                add += Integer.parseInt(tmp[i]);
            }
        }
        return add;
    }    

    public static void main(String[] args) {
        int sum = 0;
        for (int i = 0; i < args.length; i++) {
            sum += add(args[i]);
        }
        System.out.println(sum);
    } 
}