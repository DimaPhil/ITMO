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

    boolean[] wasp;
    boolean[] wasq;

    boolean checkEquals(Automaton p, Automaton q, int v, int u) {
        if (wasp[v] && wasq[u]) {
            return true;
        }
        if (wasp[v] ^ wasq[u]) {
            return false;
        }
        if (p.isTerminal[v] != q.isTerminal[u]) {
            return false;
        }
        wasp[v] = true;
        wasq[u] = true;
        boolean result = true;
        for (int c = 0; c < alphabet; c++) {
            int pv = p.go[v][c];
            int qu = q.go[u][c];
            if ((pv == -1) ^ (qu == -1)) {
                return false;
            }
            if (pv == -1) {
                continue;
            }

            result &= checkEquals(p, q, pv, qu);
        }
        return result;
    }

    public void solve() throws IOException {
        Automaton p = new Automaton();
        Automaton q = new Automaton();
        p.read();
        q.read();
        wasp = new boolean[p.n];
        wasq = new boolean[q.n];
        out.println(checkEquals(p, q, 0, 0) ? "YES" : "NO");
    }

    public void run() {
        try {
            in = new FastScanner(new File("isomorphism.in"));
            out = new PrintWriter(new File("isomorphism.out"));

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