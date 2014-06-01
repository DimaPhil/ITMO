public class SingletonSum {
    static boolean isHex(String s) {
        return s.startsWith("0x") || s.startsWith("0X");
    }

    static long parseNumber(String s) {
        int radix = 10;
        if (isHex(s)) {
            s = s.substring(2);
            radix = 16;
        }
        return Long.parseLong(s, radix);
    }

    static long parseArgumentAndPush(String[] elements) {
        long add = 0;
        for (int i = 0; i < elements.length; i++) {
            if (elements[i].length() == 0) {
                continue;
            }
            long x = parseNumber(elements[i]);
            add += x;
            ArrayQueueSingleton.push(x);
        }
        return add;
    }
 
    public static void main(String[] args) {
        long sum = 0;
        for (int i = 0; i < args.length; i++) {
            String[] elements = args[i].split("\\s+");
            sum += parseArgumentAndPush(elements);
        }
        System.out.println(sum);
        while (!ArrayQueueSingleton.isEmpty())
            System.out.println(ArrayQueueSingleton.pop());
    }
}