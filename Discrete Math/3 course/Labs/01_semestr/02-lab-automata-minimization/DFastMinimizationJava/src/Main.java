import java.util.*;
import java.io.*;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;

public class Main {
    FastScanner in;
    PrintWriter out;

    private final static int alphabet = 26;

    void markReachable(int v, int[][] go, boolean[] reachable) {
        reachable[v] = true;
        for (int c = 0; c < alphabet; c++) {
            if (!reachable[go[v][c]]) {
                markReachable(go[v][c], go, reachable);
            }
        }
    }

    class Pair<F, S> {
        F first;
        S second;

        Pair(F first, S second) {
            this.first = first;
            this.second = second;
        }
    }

    public int getSize(HashSet<Integer> hs) {
        if (hs == null) {
            return 0;
        }
        return hs.size();
    }

    public void solve() throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        boolean[] isTerminal = new boolean[n + 1];
        int[][] go = new int[n + 1][alphabet];
        ArrayList<Integer>[][] goRev = new ArrayList[n + 1][alphabet];
        for (int i = 0; i <= n; i++) {
            goRev[i] = new ArrayList[alphabet];
            for (int c = 0; c < alphabet; c++) {
                go[i][c] = 0;
                goRev[i][c] = new ArrayList<>();
            }
        }
        boolean[] reachable = new boolean[n + 1];
        for (int i = 0; i < k; i++) {
            isTerminal[in.nextInt()] = true;
        }
        for (int i = 0; i < m; i++) {
            int v = in.nextInt();
            int u = in.nextInt();
            int c = in.next().charAt(0) - 'a';
            go[v][c] = u;
        }
        n++;
        for (int i = 0; i < n; i++) {
            for (int c = 0; c < alphabet; c++) {
                goRev[go[i][c]][c].add(i);
            }
        }

        HashSet<Integer> terminals = new HashSet<>();
        HashSet<Integer> notTerminals = new HashSet<>();
        ArrayList<HashSet<Integer>> states = new ArrayList<>();
        ArrayList<HashSet<Integer>> partition = new ArrayList<>();
        Queue<Pair<Integer, Integer>> queue = new LinkedList<>();

        markReachable(1, go, reachable);
        int[] cs = new int[n + 1];
        int[] css = new int[n + 1];
        Arrays.fill(cs, -1);
        for (int i = 0; i < n; i++) {
            if (isTerminal[i]) {
                terminals.add(i);
                css[i] = 0;
            } else {
                notTerminals.add(i);
                css[i] = 1;
            }
        }
        states.add(terminals);
        states.add(notTerminals);
        partition.add(new HashSet<>(terminals));
        partition.add(new HashSet<>(notTerminals));
        for (int c = 0; c < alphabet; c++) {
            queue.add(new Pair<>(0, c));
            queue.add(new Pair<>(1, c));
        }
        while (!queue.isEmpty()) {
            Pair<Integer, Integer> current = queue.poll();
            int u = current.first;
            int v = current.second;
            HashMap<Integer, ArrayList<Integer>> stateRev = new HashMap<>();
            for (int state : partition.get(u)) {
                for (int rev : goRev[state][v]) {
                    if (!stateRev.containsKey(css[rev])) {
                        stateRev.put(css[rev], new ArrayList<>());
                    }
                    stateRev.get(css[rev]).add(rev);
                }
            }
            for (HashMap.Entry<Integer, ArrayList<Integer>> e : stateRev.entrySet()) {
                if (e.getValue().size() == 0) {
                    continue;
                }
                int i = e.getKey();
                if (stateRev.get(i).size() < getSize(states.get(i))) {
                    states.add(new HashSet<>());
                    int endPos = states.size() - 1;
                    for (int rev : stateRev.get(i)) {
                        states.get(i).remove(rev);
                        states.get(endPos).add(rev);
                    }
                    if (states.get(endPos).size() > states.get(i).size()) {
                        HashSet<Integer> tmp = states.get(endPos);
                        states.set(endPos, states.get(i));
                        states.set(i, tmp);
                    }
                    for (int rev : states.get(endPos)) {
                        css[rev] = endPos;
                    }
                    partition.add(new HashSet<>(states.get(endPos)));
                    for (int c = 0; c < alphabet; c++) {
                        queue.add(new Pair<>(partition.size() - 1, c));
                    }
                }
            }
        }

        int classes = 0;
        for (HashSet<Integer> state : states) {
            if (state.contains(0)) {
                for (int v : state) {
                    cs[v] = 0;
                }
            }
            if (state.contains(1) && cs[1] == -1) {
                ++classes;
                for (int v : state) {
                    cs[v] = 1;
                }
            }
        }
        for (HashSet<Integer> state : states) {
            int v = state.iterator().next();
            if (!reachable[v] || cs[v] != -1) {
                continue;
            }
            ++classes;
            cs[v] = classes;
            for (int vertex : state) {
                cs[vertex] = classes;
            }
        }
        boolean[] newTerminal = new boolean[classes + 1];
        int newK = 0;
        for (int i = 0; i < n; i++) {
            if (isTerminal[i] && cs[i] != -1 && !newTerminal[cs[i]]) {
                newTerminal[cs[i]] = true;
                newK++;
            }
        }
        if (newTerminal[0]) {
            newK--;
        }
        int[][] newGo = new int[classes + 1][alphabet];
        int newM = 0;
        for (int i = 0; i < n; i++) {
            for (int c = 0; c < alphabet; c++) {
                int j = go[i][c];
                if (cs[i] > 0 && cs[j] > 0 && newGo[cs[i]][c] == 0) {
                    newGo[cs[i]][c] = cs[j];
                    newM++;
                }
            }
        }

        out.println(classes + " " + newM + " " + newK);
        for (int i = 1; i <= classes; i++) {
            if (newTerminal[i]) {
                out.print(i + " ");
            }
        }
        out.println();
        for (int i = 1; i <= classes; i++) {
            for (int c = 0; c < alphabet; c++) {
                if (newGo[i][c] != 0) {
                    String s = "";
                    s += (char)('a' + c);
                    out.println(i + " " + newGo[i][c] + " " + s);
                }
            }
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("fastminimization.in"));
            out = new PrintWriter(new File("fastminimization.out"));

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