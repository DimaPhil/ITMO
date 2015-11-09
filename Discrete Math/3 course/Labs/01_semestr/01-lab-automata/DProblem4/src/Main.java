
import java.util.*;
import java.io.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    private final static int alphabet = 26;
    private final static int MODULO = (int)1e9 + 7;
    private int[][] dp;

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
        int[][] go = new int[n][alphabet];
        for (int i = 0; i < go.length; i++) {
            for (int j = 0; j < go[i].length; j++) {
                go[i][j] = -1;
            }
        }
        for (int i = 0; i < m; i++) {
            int v = in.nextInt() - 1;
            int u = in.nextInt() - 1;
            char c = in.next().charAt(0);
            go[v][c - 'a'] = u;
        }

        dp = new int[l + 1][n];
        dp[0][0] = 1;
        for (int i = 0; i < l; i++) {
            for (int v = 0; v < n; v++) {
                for (int c = 0; c < 26; c++) {
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
        out.println(ans);
    }

    public void run() {
        try {
            in = new FastScanner(new File("problem4.in"));
            out = new PrintWriter(new File("problem4.out"));

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