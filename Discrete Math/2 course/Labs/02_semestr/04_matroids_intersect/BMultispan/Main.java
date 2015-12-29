import java.io.*;
import java.util.*;
import java.math.*;

public class multispan_ab implements Runnable {

    final int MAXN = 100;
    final int MAXM = 5000;

    private void solve() throws IOException {
        int n = assertBounds(1, in.nextInt(), MAXN);
        int m = assertBounds(0, in.nextInt(), MAXM);
        
        e = new Edge[m];
        
        DS ds = new DS(n);
        for (int i = 0; i < m; ++i) {
            int a = assertBounds(1, in.nextInt(), n) - 1;
            int b = assertBounds(1, in.nextInt(), n) - 1;
            myAssert(a != b);
            e[i] = makeEdge(a, b, i);           
            ds.union(a, b);
        }
        
        for (int i = 1; i < n; ++i) {
            myAssert(ds.root(i) == ds.root(i - 1));
        }
        
        w = new int[m];
        p = new int[m];
        aw = new int[m];
        Arrays.fill(aw, -1);
        queue = new MQ(m);
        int l = 0;
        int r = m / (n - 1) + 1;
        while (r - l > 1) {
            int k = (l + r) / 2;
            System.arraycopy(aw, 0, w, 0, m);
            SpanTree[] s = new SpanTree[k];
            for (int i = 0; i < s.length; ++i) {
                s[i] = new SpanTree(n);
            }
            
            for (int i = 0; i < m; ++i) {
                if (w[i] >= 0) {
                    s[w[i]].add(e[i]);
                }
            }
            
            int q = l * (n - 1);
            loop:
            for (; q < k * (n - 1);++q) {
                queue.flush();
                for (int i = 0; i < m; ++i) {
                    if (w[i] >= 0) continue;
                    p[i] = -1;
                    for (int j = 0; j < k; ++j) {
                        parent = i;
                        if (!s[j].inCycle(e[i])) {
                            s[j].add(e[i]);
                            w[i] = j;
                            continue loop;
                        }
                    }
                }
                
                while (!queue.isEmpty()) {
                    Edge a = queue.poll();
                    for (int j = 0; j < k; ++j) {
                        parent = a.n;
                        if (!s[j].inCycle(a)) {
                            s[j].add(a);
                            int i = a.n;
                            int f = j;
                            while (true) {
                                int t = w[i];
                                w[i] = f;
                                if (t < 0) break;
                                s[t].remove(e[i]);
                                s[t].add(e[p[i]]);
                                f = t;
                                i = p[i];
                            }
                            continue loop;
                        }
                    }
                }
                break;
            }
            
            if (q == k * (n - 1)) {
                l = k;
                aw = w.clone();
            } else {
                r = k;
            }
        }
        
        out.println(l);
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < m; ++j) {
                if (w[j] == i) {
                    out.print((j + 1) + " ");
                }
            }
            out.println();
        }
        
    }

    int[] aw;
    
    Edge[] e;
    int[] w;
    int[] p;
    MQ queue;
    int parent;
    
    
    class MQ {
        int[] q;
        int[] u;
        int col, head, tail;
        
        public MQ(int m) {
            q = new int[m];
            u = new int[m];
            col = 0;
            flush();
        }
        
        void flush() {
            head = 0;
            tail = 0;
            ++col;
        }
        
        void push(Edge e) {
            if (u[e.n] != col) {
                q[tail] = e.n;
                p[e.n] = parent;
                u[e.n] = col;
                ++tail;
            }
        }
        
        Edge poll() {
            if (head == tail) return null;
            Edge ans = e[q[head]];
            ++head;
            return ans;
        }
        
        boolean isEmpty() {
            return head == tail;
        }
    }
    
    
    Edge makeEdge(int a, int b, int n) {
        Edge e = new Edge(a, b, n);
        Edge re = new Edge(b, a, n);
        e.r = re;
        re.r = e;
        return e;
    }
    
    class Edge {
        int a, b, n;
        
        Edge r;
        
        public Edge(int a, int b, int n) {
            this.a = a;
            this.b = b;
            this.n = n;
        }
        
        @Override
        public String toString() {
            return (n + 1) + "";
        }
    }
    
    class SpanTree {

        ArrayList<Edge>[] g;
        int[] u;
        int col;
        
        
        public SpanTree(int n) {
            g = new ArrayList[n];
            for (int i = 0; i < n; ++i) {
                g[i] = new ArrayList<Edge>();
            }
            u = new int[n];
            col = 1;
        }
        
        void add(Edge e) {
            g[e.a].add(e);
            g[e.r.a].add(e.r);
        }
    
        void remove(Edge e) {
            g[e.a].remove(e);
            g[e.r.a].remove(e.r);
        }
        
        boolean dfs(int i, int t) {
            u[i] = col;
            if (t == i) {
                return true;
            }
            for (Edge a : g[i]) {
                if (u[a.b] != col && dfs(a.b, t)) {
                    queue.push(a);
                    return true;
                }
            }
            return false;
        }
        
        boolean inCycle(Edge e) {
            ++col;
            return dfs(e.a, e.b);
        }
    }

    class DS {
        int[] p;

        public DS(int n) {
            p = new int[n];
            init();
        }

        public void init() {
            for (int i = 0; i < p.length; ++i) {
                p[i] = i;
            }
        }

        int root(int i) {
            if (p[i] != i)
                p[i] = root(p[i]);
            return p[i];
        }

        void union(int i, int j) {
            i = root(i);
            j = root(j);
            p[i] = j;
        }
    }

    final String FILE_NAME = "multispan";

    SimpleScanner in;
    PrintWriter out;

    @Override
    public void run() {
        try {
            in = new SimpleScanner(new FileReader(FILE_NAME + ".in"));
            out = new PrintWriter(FILE_NAME + ".out");
            solve();
            out.close();
        } catch (Throwable e) {
            e.printStackTrace();
            System.exit(-1);
        }
    }

    public static void main(String[] args) {
        new Thread(new multispan_ab()).start();
    }

    void myAssert(boolean e) {
        if (!e) {
            throw new Error("assertion failed");
        }
    }

    int assertBounds(int l, int m, int r) {
        myAssert(l <= m && m <= r);
        return m;
    }

    class SimpleScanner extends BufferedReader {

        private StringTokenizer st;
        private boolean eof;

        public SimpleScanner(Reader a) {
            super(a);
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(readLine());
                } catch (Exception e) {
                    eof = true;
                    return "";
                }
            }
            return st.nextToken();
        }

        boolean seekEof() {
            String s = next();
            if ("".equals(s) && eof)
                return true;
            st = new StringTokenizer(s + " " + st.toString());
            return false;
        }

        private String cnv(String s) {
            if (s.length() == 0)
                return "0";
            return s;
        }

        int nextInt() {
            return Integer.parseInt(cnv(next()));
        }

        double nextDouble() {
            return Double.parseDouble(cnv(next()));
        }

        long nextLong() {
            return Long.parseLong(cnv(next()));
        }
    }
}