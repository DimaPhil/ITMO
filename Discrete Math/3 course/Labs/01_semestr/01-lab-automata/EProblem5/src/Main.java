
import java.util.*;
import java.io.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    private final static int alphabet = 26;
    private final static int MODULO = (int)1e9 + 7;
    private int[][] dp;

    public class Edge {
        public int from;
        public int to;
        public char c;

        public Edge() {
        }

        public Edge(int from, int to, char c) {
            this.from = from;
            this.to = to;
            this.c = c;
        }
    }

    public class DNA {
        int n;
        int k;
        boolean[] terminal;
        int[][] go;
        int[][] dp;

        public DNA(HashSet<HashSet<Integer>> result, HashSet<Integer> s,
                   HashMap<HashSet<Integer>, Boolean> terminal, HashMap<HashSet<Integer>, HashSet<Integer>>[] go) {

        }

        public DNA(boolean[] terminal, int[][] go) {
            this.n = terminal.length;
            this.terminal = terminal;
            this.go = go;
        }

        int calcWords(int l) {
            dp = new int[l + 1][n];
            dp[0][0] = 1;
            for (int i = 0; i < l; i++) {
                for (int v = 0; v < n; v++) {
                    for (int c = 0; c < alphabet; c++) {
                        if (go[v][c] == -1) {
                            continue;
                        }
                        int u = go[v][c];
                        dp[i + 1][u] += dp[i][v];
                        if (dp[i + 1][u] >= MODULO) {
                            dp[i + 1][u] -= MODULO;
                        }
                    }
                }
            }

            int ans = 0;
            for (int i = 0; i < n; i++) {
                ans += terminal[i] ? dp[l][i] : 0;
                if (ans >= MODULO) {
                    ans -= MODULO;
                }
            }
            return ans;
        }
    }

    public void solve() throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        int l = in.nextInt();
        boolean[] terminal = new boolean[n];
        for (int i = 0; i < k; i++) {
            int state = in.nextInt();
            terminal[state - 1] = true;
        }
        HashSet<Integer>[][] go = new HashSet[n][alphabet];
        for (int i = 0; i < n; i++) {
            for (int c = 0; c < alphabet; c++) {
                go[i][c] = new HashSet<>();
            }
        }
        for (int i = 0; i < m; i++) {
            int v = in.nextInt() - 1;
            int u = in.nextInt() - 1;
            char c = in.next().charAt(0);
            go[v][c - 'a'].add(u);
        }

        ArrayList<HashSet<Integer>> queue = new ArrayList<>();
        queue.add(new HashSet<>(Collections.singletonList(0)));
        HashMap<HashSet<Integer>, Integer> result = new HashMap<>();
        result.put(queue.get(0), 0);
        for (int i = 0; i < queue.size(); i++) {
            HashSet<Integer> state = queue.get(i);
            for (int c = 0; c < alphabet; c++) {
                HashSet<Integer> newState = new HashSet<>();
                for (int value : state) {
                    newState.addAll(go[value][c]);
                }
                if (!result.containsKey(newState)) {
                    result.put(newState, result.size());
                    queue.add(newState);
                }
            }
        }

        boolean[] newTerminal = new boolean[queue.size()];
        int[][] newGo = new int[queue.size()][alphabet];
        for (int i = 0; i < queue.size(); i++) {
            HashSet<Integer> state = queue.get(i);
            for (int c = 0; c < alphabet; c++) {
                HashSet<Integer> newState = new HashSet<>();
                for (int value : state) {
                    newState.addAll(go[value][c]);
                }
                newGo[i][c] = result.get(newState);
            }
            for (int value : state) {
                newTerminal[i] |= terminal[value];
            }
        }
        DNA dna = new DNA(newTerminal, newGo);
        out.println(dna.calcWords(l));
    }

    public void run() {
        try {
            in = new FastScanner(new File("problem5.in"));
            out = new PrintWriter(new File("problem5.out"));

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

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] arg) {
        new Main().run();
    }
}