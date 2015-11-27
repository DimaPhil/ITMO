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

        public void read() {
            n = in.nextInt();
            m = in.nextInt();
            k = in.nextInt();
            isTerminal = new boolean[n];
            for (int i = 0; i < k; i++) {
                int x = in.nextInt();
                isTerminal[x - 1] = true;
            }
            go = new int[n][26];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < 26; j++) {
                    go[i][j] = -1;
                }
            }
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;
                char c = in.next().charAt(0);
                go[a][c - 'a'] = b;
            }
        }
    }

    class Pair implements Comparable<Pair> {
        int first;
        int second;

        Pair() {}
        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(Pair p) {
            if (p.first != first) {
                return first - p.first;
            }
            return second - p.second;
        }
    }

    boolean checkEquivalence(Automaton p, Automaton q, int sp, int su) {
        Queue<Pair> queue = new LinkedList<>();
        TreeSet<Pair> usedPairs = new TreeSet<>();
        queue.add(new Pair(sp, su));
        usedPairs.add(new Pair(sp, su));
        while (!queue.isEmpty()) {
            Pair current = queue.poll();
            int v = current.first;
            int u = current.second;
            boolean isTerminalV = (v != -1 && p.isTerminal[v]);
            boolean isTerminalU = (u != -1 && q.isTerminal[u]);
            if (isTerminalV != isTerminalU) {
                return false;
            }
            for (int c = 0; c < 26; c++) {
                int nv = -1;
                if (v != -1) {
                    nv = p.go[v][c];
                }
                int nu = -1;
                if (u != -1) {
                    nu = q.go[u][c];
                }
                if (!usedPairs.contains(new Pair(nv, nu))) {
                    queue.add(new Pair(nv, nu));
                    usedPairs.add(new Pair(nv, nu));
                }
            }
        }
        return true;
    }

    public void solve() throws IOException {
        Automaton p = new Automaton();
        Automaton q = new Automaton();
        p.read();
        q.read();
        out.println(checkEquivalence(p, q, 0, 0) ? "YES" : "NO");
    }

    public void run() {
        try {
            in = new FastScanner(new File("equivalence.in"));
            out = new PrintWriter(new File("equivalence.out"));

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