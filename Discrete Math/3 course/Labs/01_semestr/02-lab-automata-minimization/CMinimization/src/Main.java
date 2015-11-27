
import java.util.*;
import java.io.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    private final static int alphabet = 26;

    class Automaton {
        int n, m, k;
        boolean[] isTerminal;
        int[][] go;
        ArrayList<Integer>[][] goRev;
        boolean[][] marked;
        boolean[] reachable;

        Automaton() {
        }

        Automaton(int n) {
            this.n = n;
            m = 0;
            k = 0;
            isTerminal = new boolean[n + 1];
            go = new int[n + 1][alphabet];
            for (int i = 0; i <= n; i++)
                for (int c = 0; c < alphabet; c++)
                    go[i][c] = 0;
            goRev = new ArrayList[n + 1][alphabet];
            marked = new boolean[n + 1][n + 1];
            reachable = new boolean[n + 1];
        }

        public void read() {
            n = in.nextInt();
            m = in.nextInt();
            k = in.nextInt();
            isTerminal = new boolean[n + 1];
            for (int i = 0; i < k; i++) {
                int x = in.nextInt();
                isTerminal[x] = true;
            }
            go = new int[n + 1][alphabet];
            goRev = new ArrayList[n + 1][alphabet];
            reachable = new boolean[n + 1];
            marked = new boolean[n + 1][n + 1];
            for (int i = 0; i <= n; i++) {
                goRev[i] = new ArrayList[alphabet];
                for (int j = 0; j < alphabet; j++) {
                    goRev[i][j] = new ArrayList<>();
                    go[i][j] = 0;
                }
            }
            for (int i = 0; i < m; i++) {
                int a = in.nextInt();
                int b = in.nextInt();
                char c = in.next().charAt(0);
                go[a][c - 'a'] = b;
            }
            n++;
            for (int i = 0; i < n; i++) {
                for (int c = 0; c < alphabet; c++) {
                    goRev[go[i][c]][c].add(i);
                }
            }
        }

        void print() {
            out.println(n + " " + m + " " + k);
            for (int i = 1; i <= n; i++) {
                if (isTerminal[i]) {
                    out.print(i + " ");
                }
            }
            out.println();
            for (int i = 1; i <= n; i++) {
                for (int c = 0; c < alphabet; c++) {
                    int g = go[i][c];
                    if (g != 0) {
                        String s = "";
                        s += (char)(c + 'a');
                        out.println(i + " " + g + " " + s);
                    }
                }
            }
        }

        class Pair {
            int first;
            int second;

            Pair(int first, int second) {
                this.first = first;
                this.second = second;
            }
        }

        public void markReachable(int v) {
            reachable[v] = true;
            for (int c = 0; c < alphabet; c++) {
                int u = go[v][c];
                if (!reachable[u]) {
                    markReachable(u);
                }
            }
        }

        public void addEdge(int v, int u, int c) {
            if (go[v][c] == 0) {
                m++;
            }
            go[v][c] = u;
        }

        public void addTerminal(int v) {
            if (!isTerminal[v]) {
                k++;
            }
            isTerminal[v] = true;
        }

        public Automaton buildFromClasses(int[] cs, int classes) {
            Automaton result = new Automaton(classes);
            for (int i = 1; i < n; i++) {
                if (isTerminal[i]) {
                    result.addTerminal(cs[i]);
                }
                for (int c = 0; c < alphabet; c++) {
                    int g = go[i][c];
                    if (g != 0 && cs[i] > 0 && cs[g] > 0) {
                        result.addEdge(cs[i], cs[g], c);
                    }
                }
            }
            return result;
        }

        public Automaton getMinimize() {
            markReachable(1);
            Queue<Pair> queue = new ArrayDeque<>();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (!marked[i][j] && isTerminal[i] != isTerminal[j]) {
                        marked[i][j] = true;
                        marked[j][i] = true;
                        queue.add(new Pair(i, j));
                    }
                }
            }
            while (!queue.isEmpty()) {
                Pair pa = queue.poll();
                int u = pa.first;
                int v = pa.second;
                for (int c = 0; c < alphabet; c++) {
                    if (goRev[u][c].isEmpty()) {
                        continue;
                    }
                    for (int r : goRev[u][c]) {
                        if (goRev[v][c].isEmpty()) {
                            continue;
                        }
                        (goRev[v][c]).stream().filter(s -> !marked[r][s]).forEach(s -> {
                            marked[r][s] = true;
                            marked[s][r] = true;
                            queue.add(new Pair(r, s));
                        });
                    }
                }
            }
            int[] cs = new int[n + 1];
            Arrays.fill(cs, -1);
            for (int i = 0; i < n; i++) {
                if (!marked[0][i]) {
                    cs[i] = 0;
                }
            }
            int classes = 0;
            for (int i = 1; i < n; i++) {
                if (reachable[i]) {
                    if (cs[i] == -1) {
                        classes++;
                        cs[i] = classes;
                        for (int j = i + 1; j < n; j++) {
                            if (!marked[i][j]) {
                                cs[j] = classes;
                            }
                        }
                    }
                }
            }
            return buildFromClasses(cs, classes);
        }
    }

    public void solve() throws IOException {
        long start = System.currentTimeMillis();
        Automaton p = new Automaton();
        p.read();
        p.getMinimize().print();
        System.out.println(System.currentTimeMillis() - start);
    }

    public void run() {
        try {
            in = new FastScanner(new File("minimization.in"));
            out = new PrintWriter(new File("minimization.out"));

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