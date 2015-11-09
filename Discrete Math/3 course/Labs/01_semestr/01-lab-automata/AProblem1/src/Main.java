import java.util.*;
import java.io.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    final static int alphabet = 26;

    public void solve() throws IOException {
        String word = in.next();
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
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
        int s = 0;
        for (int i = 0; i < word.length(); i++) {
            int symbol = word.charAt(i) - 'a';
            if (go[s][symbol] == -1) {
                out.println("Rejects");
                return;
            }
            s = go[s][symbol];
        }
        out.println(terminal[s] ? "Accepts" : "Rejects");
    }

    public void run() {
        try {
            in = new FastScanner(new File("problem1.in"));
            out = new PrintWriter(new File("problem1.out"));

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
