import com.sun.jmx.remote.internal.ArrayQueue;

import java.util.*;
import java.io.*;

public class ARainbow {
    FastScanner in;
    PrintWriter out;

    class DSU {
        private HashMap<Vertex, Vertex> parents = new HashMap<>();
        private HashMap<Vertex, Integer> rank = new HashMap<>();

        public void add(Vertex city) {
            parents.put(city, city);
            rank.put(city, 0);
        }

        public Vertex get(Vertex city) {
            Vertex root = parents.get(city);
            if (root == city) {
                return root;
            } else {
                root = get(root);
            }
            parents.put(city, root);
            return root;
        }

        public void unite(Vertex x, Vertex y) {
            x = get(x);
            y = get(y);
            if (rank.get(x) < rank.get(y)) {
                Vertex tmp = x;
                x = y;
                y = tmp;
            }
            parents.put(y, x);
            if (rank.get(x).equals(rank.get(y))) {
                rank.put(x, rank.get(x) + 1);
            }
        }
    }

    class Vertex {
        public boolean used;
        public Vertex prev;
        public Path from;
        public ArrayList<Edge> edges;

        public Vertex() {
            used = false;
            prev = null;
            from = null;
            edges = new ArrayList<>();
        }
    }

    class Node {
        public boolean taken;

        public Node() {
            taken = false;
        }
    }

    class Path {
        public Vertex from;
        public Vertex to;
        public Node vertex;
        public boolean taken;
        public Path prev;
        public boolean visited;
        public int index;

        public Path() {
            visited = false;
            from = null;
            to = null;
            vertex = null;
            taken = false;
            prev = null;
        }
    }

    class Edge {
        public Vertex to;
        public Path path;

        public Edge(Vertex to, Path path) {
            this.to = to;
            this.path = path;
        }
    }


    Vertex[] vertexes;
    Path[] paths;
    Map<Integer, Node> weights = new HashMap<>();

    private ArrayList<Path> findCycles(Path start) {
        LinkedList<Vertex> queue = new LinkedList<>();

        for (Vertex vertex : vertexes) {
            vertex.used = false;
            vertex.prev = null;
            vertex.from = null;
        }

        queue.add(start.from);
        start.from.used = true;

        while (!start.to.used && !queue.isEmpty()) {
            Vertex top = queue.poll();
            top.edges.stream().filter(edge -> edge.path.taken).forEach(edge -> {
                Vertex next = edge.to;
                if (!next.used) {
                    next.used = true;
                    next.prev = top;
                    next.from = edge.path;
                    queue.add(next);
                }
            });
        }

        if (!start.to.used) {
            return null;
        }

        ArrayList<Path> result = new ArrayList<>();
        Vertex last = start.to;
        while (last.prev != null) {
            result.add(last.from);
            last = last.prev;
        }
        return result;
    }

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();

        paths = new Path[m];
        vertexes = new Vertex[n];

        for (int i = 0; i < vertexes.length; i++) {
            vertexes[i] = new Vertex();
        }

        for (int i = 0; i < paths.length; ++i) {
            paths[i] = new Path();
            paths[i].from = vertexes[in.nextInt() - 1];
            paths[i].to = vertexes[in.nextInt() - 1];
            int weight = in.nextInt() - 1;
            if (!weights.containsKey(weight)) {
                weights.put(weight, new Node());
            }
            paths[i].vertex = weights.get(weight);
            paths[i].index = i + 1;
        }

        for (Path path : paths) {
            path.from.edges.add(new Edge(path.to, path));
            path.to.edges.add(new Edge(path.from, path));
        }

        DSU dsu = new DSU();
        for (Vertex vertex : vertexes)
            dsu.add(vertex);
        for (Path path : paths) {
            if (path.vertex.taken) {
                continue;
            }
            if (dsu.get(path.from) == dsu.get(path.to)) {
                continue;
            }
            path.taken = true;
            path.vertex.taken = true;
            dsu.unite(path.from, path.to);
        }

        while (true) {
            LinkedList<Path> queue = new LinkedList<>();
            for (Path path : paths) {
                if (!path.vertex.taken) {
                    path.prev = null;
                    path.visited = true;
                    queue.add(path);
                } else {
                    path.visited = false;
                }
            }

            Path end = null;
            while (!queue.isEmpty()) {
                Path top = queue.poll();
                if (top.taken) {
                    for (Path next : paths) {
                        if (!next.visited && next != top && next.vertex == top.vertex) {
                            next.visited = true;
                            next.prev = top;
                            queue.add(next);
                        }
                    }
                } else {
                    ArrayList<Path> cycles = findCycles(top);
                    if (cycles == null) {
                        end = top;
                        break;
                    }
                    cycles.stream().filter(next -> !next.visited).forEach(next -> {
                        next.visited = true;
                        next.prev = top;
                        queue.add(next);
                    });
                }
            }

            if (end == null) {
                break;
            }
            while (end != null) {
                end.taken = !end.taken;
                end.vertex.taken = true;
                end = end.prev;
            }
        }

        int result = 0;
        for (Path path : paths) {
            if (path.taken) {
                ++result;
            }
        }
        out.println(result);
        for (Path path : paths) {
            if (path.taken) {
                out.print(path.index + " ");
            }
        }
        out.println();
    }

    public void run() {
        try {
            in = new FastScanner(new File("rainbow.in"));
            out = new PrintWriter(new File("rainbow.out"));

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
        new ARainbow().run();
    }
}