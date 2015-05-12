import java.util.*;
        import java.io.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    private class Edge implements Comparable<Edge> {
        int v, u, id;
        long w;

        Edge(int v, int u, long w, int id) {
            this.v = v;
            this.u = u;
            this.w = w;
            this.id = id;
        }

        @Override
        public int compareTo(Edge o) {
            return w - o.w > 0 ? 1 : (w - o.w == 0 ? 0 : -1);
        }
    }

    private class DSU {
        int n;
        int[] p;
        int[] rank;

        DSU(int n) {
            this.n = n;
            p = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) {
                p[i] = i;
                rank[i] = 0;
            }
        }

        public int get(int x) {
            return p[x] == x ? x : (p[x] = get(p[x]));
        }

        public void unite(int x, int y) {
            x = get(x);
            y = get(y);
            if (x == y) {
                return;
            }
            if (rank[x] < rank[y]) {
                int t = x;
                x = y;
                y = t;
            }
            p[y] = x;
            if (rank[x] == rank[y]) {
                rank[x]++;
            }
        }
    }

    public void solve() throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        ArrayList<Edge> edges = new ArrayList<>();
        long s = in.nextLong();
        for (int i = 0; i < m; i++) {
            int v = in.nextInt();
            int u = in.nextInt();
            v--;
            u--;
            long w = in.nextLong();
            edges.add(new Edge(v, u, w, i));
        }
        Collections.sort(edges);
        Collections.reverse(edges);
        DSU dsu = new DSU(n);
        boolean[] used = new boolean[m];
        for (int i = 0; i < m; i++) {
            int v = edges.get(i).v;
            int u = edges.get(i).u;
            if (dsu.get(v) != dsu.get(u)) {
                dsu.unite(v, u);
                used[i] = true;
            }
        }
        ArrayList<Integer> answer = new ArrayList<>();
        for (int i = m - 1; i >= 0; i--) {
            if (!used[i] && edges.get(i).w <= s) {
                answer.add(edges.get(i).id);
                s -= edges.get(i).w;
            }
        }
        Collections.sort(answer);
        out.println(answer.size());
        for (Integer edgeId : answer) {
            out.print((edgeId + 1) + " ");
        }
        out.println();
    }

    public void run() {
        try {
            in = new FastScanner(new File("destroy.in"));
            out = new PrintWriter(new File("destroy.out"));

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

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] arg) {
        new Main().run();
    }
}