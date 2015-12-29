import java.io.*;
import java.util.*;

public class BMultispan {
    FastScanner in;
    PrintWriter out;

    class Edge {
        int from, to, id;
        Edge backEdge;

        public Edge(int from, int to, int id) {
            this.from = from;
            this.to = to;
            this.id = id;
        }
    }

    class MyFeatureQueue {
        int[] elements;
        int[] colors;
        int head;
        int tail;
        int nowColor;

        public MyFeatureQueue(int m) {
            elements = new int[m];
            colors = new int[m];
            head = 0;
            tail = 0;
            nowColor = 1;
        }

        void reset() {
            head = 0;
            tail = 0;
            nowColor++;
        }

        void push(Edge e) {
            if (colors[e.id] != nowColor) {
                elements[tail++] = e.id;
                p[e.id] = globalParent;
                colors[e.id] = nowColor;
            }
        }

        Edge poll() {
            if (head == tail) {
                return null;
            }
            return edges[elements[head++]];
        }

        boolean isEmpty() {
            return head == tail;
        }
    }

    class SpanningTree {
        ArrayList<Edge>[] graph;
        int[] colors;
        int nowColor;

        public SpanningTree(int n) {
            graph = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                graph[i] = new ArrayList<Edge>();
            }
            colors = new int[n];
            nowColor = 1;
        }

        void addEdge(Edge e) {
            graph[e.from].add(e);
            graph[e.backEdge.from].add(e.backEdge);
        }

        void removeEdge(Edge e) {
            graph[e.from].remove(e);
            graph[e.backEdge.from].remove(e.backEdge);
        }

        boolean dfs(int v, int finish) {
            colors[v] = nowColor;
            if (finish == v) {
                return true;
            }
            for (Edge edge : graph[v]) {
                if (colors[edge.to] != nowColor && dfs(edge.to, finish)) {
                    queue.push(edge);
                    return true;
                }
            }
            return false;
        }

        boolean inCycle(Edge e) {
            nowColor++;
            return dfs(e.from, e.to);
        }
    }

    int[] p;
    int globalParent;
    Edge[] edges;
    MyFeatureQueue queue;

    Edge addEdge(int from, int to, int id) {
        Edge edge = new Edge(from, to, id);
        Edge reverseEdge = new Edge(to, from, id);
        edge.backEdge = reverseEdge;
        reverseEdge.backEdge = edge;
        return edge;
    }

    private void solve() throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();

        edges = new Edge[m];
        for (int i = 0; i < m; i++) {
            int v = in.nextInt() - 1;
            int u = in.nextInt() - 1;
            edges[i] = addEdge(v, u, i);
        }

        int[] treeId0 = new int[m];
        int[] treeId = new int[m];
        p = new int[m];
        for (int i = 0; i < m; i++) {
            treeId0[i] = -1;
        }
        queue = new MyFeatureQueue(m);
        int left = 0;
        int right = 2 * m + 1;
        while (left < right - 1) {
            int middle = (left + right) >> 1;
            for (int i = 0; i < m; i++) {
                treeId[i] = treeId0[i];
            }
            SpanningTree[] trees = new SpanningTree[middle];
            for (int i = 0; i < trees.length; i++) {
                trees[i] = new SpanningTree(n);
            }

            for (int i = 0; i < m; i++) {
                if (treeId[i] >= 0) {
                    trees[treeId[i]].addEdge(edges[i]);
                }
            }

            int start = left * (n - 1);
            for (; start < middle * (n - 1); start++) {
                queue.reset();
                boolean found = false;
                for (int i = 0; i < m; i++) {
                    if (treeId[i] >= 0) {
                        continue;
                    }
                    p[i] = -1;
                    for (int j = 0; j < middle; j++) {
                        globalParent = i;
                        if (!trees[j].inCycle(edges[i])) {
                            trees[j].addEdge(edges[i]);
                            treeId[i] = j;
                            found = true;
                            break;
                        }
                    }
                    if (found) {
                        break;
                    }
                }
                if (found) {
                    continue;
                }

                while (!queue.isEmpty()) {
                    Edge top = queue.poll();
                    for (int j = 0; j < middle; j++) {
                        globalParent = top.id;
                        if (!trees[j].inCycle(top)) {
                            trees[j].addEdge(top);
                            int nowId = top.id;
                            int foundTreeId = j;
                            while (true) {
                                int localTreeId = treeId[nowId];
                                treeId[nowId] = foundTreeId;
                                if (localTreeId < 0) {
                                    break;
                                }
                                trees[localTreeId].removeEdge(edges[nowId]);
                                trees[localTreeId].addEdge(edges[p[nowId]]);
                                foundTreeId = localTreeId;
                                nowId = p[nowId];
                            }
                            found = true;
                            break;
                        }
                    }
                    if (found) {
                        break;
                    }
                }
                if (found) {
                    continue;
                }
                break;
            }

            if (start == middle * (n - 1)) {
                left = middle;
                for (int i = 0; i < m; i++) {
                    treeId0[i] = treeId[i];
                }
            } else {
                right = middle;
            }
        }

        out.println(left);
        for (int i = 0; i < left; i++) {
            for (int j = 0; j < m; j++) {
                if (treeId[j] == i) {
                    out.print((j + 1) + " ");
                }
            }
            out.println();
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("multispan.in"));
            out = new PrintWriter(new File("multispan.out"));

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
        new BMultispan().run();
    }
}