import java.util.*;
import java.io.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    class Pair implements Comparable<Pair> {
        int first, second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(Pair o) {
            return o.first - first;
        }
    }

    public boolean dfs(int v, ArrayList<Integer>[] graph, int[] mt, boolean[] used) {
        if (used[v]) {
            return false;
        }
        used[v] = true;
        for (int u : graph[v]) {
            if (mt[u] == -1 || dfs(mt[u], graph, mt, used)) {
                mt[u] = v;
                return true;
            }
        }
        return false;
    }

    public void solve() throws IOException {
        int n = in.nextInt();
        int[] w = new int[n];
        for (int i = 0; i < n; i++) {
            w[i] = in.nextInt();
        }
        int[] size = new int[n];
        ArrayList<Integer>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
            size[i] = in.nextInt();
            for (int j = 0; j < size[i]; j++) {
                graph[i].add(in.nextInt() - 1);
            }
        }
        Pair[] p = new Pair[n];
        for (int i = 0; i < n; i++) {
            p[i] = new Pair(w[i], i);
        }
        Arrays.sort(p);
        int[] mt = new int[n];
        for (int i = 0; i < n; i++) {
            mt[i] = -1;
        }
        boolean[] used = new boolean[n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(used, false);
            dfs(p[i].second, graph, mt, used);
        }
        int[] answer = new int[n];
        for (int i = 0; i < n; i++) {
            if (mt[i] != -1) {
                answer[mt[i]] = i + 1;
            }
        }
        for (int i = 0; i < n; i++) {
            out.print(answer[i] + " ");
        }
        out.println();
    }

    public void run() {
        try {
            in = new FastScanner(new File("matching.in"));
            out = new PrintWriter(new File("matching.out"));

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