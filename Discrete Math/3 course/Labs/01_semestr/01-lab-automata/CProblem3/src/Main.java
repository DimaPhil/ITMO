import java.util.*;
import java.io.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    private final static int alphabet = 26;
    private final static int MODULO = (int)1e9 + 7;
    private int[] dp;
    private int[] was;
    private boolean infiniteAnswer = false;
    private int[] tp;
    private int size = 0;
    private boolean[] canReachTerminal;

    public void solve() throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        boolean[] terminal = new boolean[n];
        for (int i = 0; i < k; i++) {
            int state = in.nextInt();
            terminal[state - 1] = true;
        }
        int[][] go = new int[n][alphabet];
        int[][] goRev = new int[n][alphabet];
        for (int i = 0; i < go.length; i++) {
            for (int j = 0; j < go[i].length; j++) {
                go[i][j] = -1;
                goRev[i][j] = -1;
            }
        }
        for (int i = 0; i < m; i++) {
            int v = in.nextInt() - 1;
            int u = in.nextInt() - 1;
            char c = in.next().charAt(0);
            go[v][c - 'a'] = u;
            goRev[u][c - 'a'] = v;
        }
        was = new int[n];
        tp = new int[n];
        canReachTerminal = new boolean[n];
        for (int i = 0; i < n; i++) {
            canReachTerminal[i] = terminal[i];
        }
        topsort(0, go);
        Arrays.fill(was, 0);
        checkWrong(0, go);
        if (infiniteAnswer) {
            out.println(-1);
            return;
        }
        for (int i = 0; i < size / 2; i++) {
            int tmp = tp[i];
            tp[i] = tp[size - i - 1];
            tp[size - i - 1] = tmp;
        }
        dp = new int[n];
        dp[tp[0]] = 1;
        for (int i = 1; i < size; i++) {
            int v = tp[i];
            dp[v] = 0;
            for (int c = 0; c < alphabet; c++) {
                if (goRev[v][c] == -1) {
                    continue;
                }
                int u = goRev[v][c];
                dp[v] += dp[u];
                if (dp[v] >= MODULO) {
                    dp[v] -= MODULO;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += terminal[i] ? dp[i] : 0;
            if (ans >= MODULO) {
                ans -= MODULO;
            }
        }
        out.println(ans);
    }

    private void topsort(int v, int[][] go) {
        was[v] = 1;
        for (int c = 0; c < alphabet; c++) {
            if (go[v][c] == -1) {
                continue;
            }
            int u = go[v][c];
            if (was[u] == 0) {
                topsort(u, go);
                canReachTerminal[v] |= canReachTerminal[u];
            }
        }
        tp[size++] = v;
        was[v] = 2;
    }

    private void checkWrong(int v, int[][] go) {
        was[v] = 1;
        for (int c = 0; c < alphabet; c++) {
            if (go[v][c] == -1) {
                continue;
            }
            int u = go[v][c];
            if (was[u] == 1 && canReachTerminal[u]) {
                infiniteAnswer = true;
                return;
            }
            if (was[u] == 0) {
                checkWrong(u, go);
            }
        }
        was[v] = 2;
    }

    public void run() {
        try {
            in = new FastScanner(new File("problem3.in"));
            out = new PrintWriter(new File("problem3.out"));

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