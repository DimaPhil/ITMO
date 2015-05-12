import java.util.*;
import java.io.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    public boolean bit(int mask, int bit) {
        return (mask & (1 << bit)) > 0;
    }

    public void solve() throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] w = new int[n];
        for (int i = 0; i < n; i++) {
            w[i] = in.nextInt();
        }
        int[] size = new int[m];
        int[] mask = new int[m];
        boolean[] ok = new boolean[1 << n];
        Arrays.fill(ok, true);
        ArrayList<Integer>[] es = new ArrayList[m];
        for (int i = 0; i < m; i++) {
            size[i] = in.nextInt();
            es[i] = new ArrayList<>();
            for (int j = 0; j < size[i]; j++) {
                int x = in.nextInt();
                x--;
                mask[i] ^= (1 << x);
                es[i].add(x);
            }
            ok[mask[i]] = false;
        }
        long answer = 0;
        for (int msk = 0; msk < (1 << n); msk++) {
            if (ok[msk]) {
                long sum = 0;
                for (int i = 0; i < n; i++) {
                    if (bit(msk, i)) {
                        sum += w[i];
                    }
                }
                answer = Math.max(answer, sum);
            } else {
                for (int i = 0; i < n; i++) {
                    if (!bit(msk, i)) {
                        ok[msk | (1 << i)] = false;
                    }
                }
            }
        }
        out.println(answer);
    }

    public void run() {
        try {
            in = new FastScanner(new File("cycles.in"));
            out = new PrintWriter(new File("cycles.out"));

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