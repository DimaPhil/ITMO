import java.util.*;
import java.io.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    private static final int alphabet = 27;
    private static final int bigAlphabet = alphabet * 2 + 1;

    private class Pair {
        public int f;
        public int s;

        Pair() {
            f = 0;
            s = 0;
        }

        Pair(int f, int s) {
            this.f = f;
            this.s = s;
        }
    }

    private int encodeChar(char c) {
        if (Character.isLowerCase(c)) {
            return c - 'a' + 1;
        }
        return c - 'A' + alphabet;
    }

    private int encodeChar(String s, int position) {
        if (position < s.length()) {
            return encodeChar(s.charAt(position));
        }
        return 0;
    }

    int nowPtr = bigAlphabet;
    boolean[][][] dp;
    boolean[][][] memory;
    String word;
    ArrayList<Pair>[] graph;

    boolean go(int c, int left, int right) {
        if (right - left == -1) {
            int fixedR = right;
            if (fixedR == -1) {
                fixedR = word.length();
            }
            if (memory[c][left][fixedR]) {
                return dp[c][left][fixedR];
            }
            memory[c][left][fixedR] = true;
            for (int i = 0; i < graph[c].size(); i++) {
                int from = graph[c].get(i).f;
                int to = graph[c].get(i).s;
                if (from == 0 && to == 0) {
                    dp[c][left][fixedR] = true;
                } else if (alphabet <= Math.min(from, to)) {
                    dp[c][left][fixedR] = dp[c][left][fixedR] || (go(to, left, right) && go(from, left, right));
                }
            }
            return dp[c][left][fixedR];
        }
        if (memory[c][left][right]) {
            return dp[c][left][right];
        }
        memory[c][left][right] = true;
        for (int i = 0; i < graph[c].size(); i++) {
            int from = graph[c].get(i).f;
            int to = graph[c].get(i).s;
            if (alphabet <= Math.min(from, to)) {
                for (int middle = left - 1; middle <= right; middle++) {
                    dp[c][left][right] = dp[c][left][right] || (go(to, middle + 1, right) && go(from, left, middle));
                }
            } else if (alphabet <= from) {
                if (to == 0) {
                    dp[c][left][right] = dp[c][left][right] || go(from, left, right);
                } else if (word.charAt(right) - 'a' + 1 == to) {
                    dp[c][left][right] = dp[c][left][right] || go(from, left, right - 1);
                }
            } else if (alphabet <= to) {
                if (from == 0) {
                    dp[c][left][right] = dp[c][left][right] || go(to, left, right);
                } else if (word.charAt(left) - 'a' + 1 == from) {
                    dp[c][left][right] = dp[c][left][right] || go(to, left + 1, right);
                }
            } else {
                if (from != 0 && to != 0) {
                    dp[c][left][right] = dp[c][left][right] || (left == right - 1 && word.charAt(left) - 'a' + 1 == from &&
                            word.charAt(right) - 'a' + 1 == to);
                } else if (from != 0) {
                    dp[c][left][right] = dp[c][left][right] || (left == right && word.charAt(left) - 'a' + 1 == from);
                }
            }
        }
        return dp[c][left][right];
    }

    public void solve() throws IOException {
        int n = in.nextInt();
        int start = in.nextLine().charAt(1) - 'A' + alphabet;
        final int MAX_SIZE = 650;
        graph = new ArrayList[MAX_SIZE];
        for (int i = 0; i < MAX_SIZE; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int it = 0; it < n; it++) {
            int from = in.next().charAt(0) - 'A' + alphabet;
            String applied = in.nextLine();
            if (applied.length() <= 4) {
                applied = "";
            } else {
                applied = applied.substring(4);
            }
            if (applied.length() <= 2) {
                graph[from].add(new Pair(encodeChar(applied, 0), encodeChar(applied, 1)));
            } else {
                for (int i = 0; i < applied.length() - 2; i++) {
                    graph[from].add(new Pair(encodeChar(applied, i), nowPtr));
                    from = nowPtr++;
                }
                graph[from].add(new Pair(encodeChar(applied, applied.length() - 2),
                                         encodeChar(applied, applied.length() - 1))
                );
            }
        }

        word = in.next();
        dp = new boolean[nowPtr + 1][word.length() + 1][word.length() + 1];
        memory = new boolean[nowPtr + 1][word.length() + 1][word.length() + 1];
        out.println(go(start, 0, word.length() - 1) ? "yes" : "no");
    }

    public void run() {
        try {
            in = new FastScanner(new File("cf.in"));
            out = new PrintWriter(new File("cf.out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        String nextLine() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken("\n");
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] arg) {
        new Main().run();
    }
}