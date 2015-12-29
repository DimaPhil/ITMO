import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException {
        int k = in.nextInt();
        int n = in.nextInt();
        int r = in.nextInt();
        ArrayList<Integer>[] graph = new ArrayList[k];
        for (int i = 0; i < k; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < r; i++) {
            int v = in.nextInt();
            int u = in.nextInt();
            char c = in.next().charAt(0);
            v--;
            u--;
            graph[v].add(u);
        }
        BigInteger[][] dp = new BigInteger[n + 1][k + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = BigInteger.ZERO;
            }
        }
        dp[0][0] = BigInteger.ONE;
        for (int it = 0; it < n; it++) {
            for (int i = 0; i < k; i++) {
                for (int v : graph[i]) {
                    dp[it + 1][v] = dp[it + 1][v].add(dp[it][i]);
                }
            }
        }
        out.println(dp[n][0].toString());
    }

    public void run() {
        try {
            in = new FastScanner(new File("input.txt"));
            out = new PrintWriter(new File("output.txt"));

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