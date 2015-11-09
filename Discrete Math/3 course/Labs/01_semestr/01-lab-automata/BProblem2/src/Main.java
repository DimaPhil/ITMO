import java.util.*;
import java.io.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    final static int alphabet = 26;
    private int[][] memory;

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
        ArrayList<Integer>[][] go = new ArrayList[n][alphabet];
        for (int i = 0; i < go.length; i++) {
            for (int j = 0; j < go[i].length; j++) {
                go[i][j] = new ArrayList<>();
            }
        }
        for (int i = 0; i < m; i++) {
            int v = in.nextInt() - 1;
            int u = in.nextInt() - 1;
            char c = in.next().charAt(0);
            go[v][c - 'a'].add(u);
        }
        memory = new int[word.length()][n];
        for (int i = 0; i < word.length(); i++) {
            for (int j = 0; j < n; j++) {
                memory[i][j] = -1;
            }
        }
        out.println(walk(word, 0, 0, go, terminal) ? "Accepts" : "Rejects");
    }

    private boolean walk(String word, int wordPosition, int automatPosition, ArrayList<Integer>[][] go, boolean[] terminal) {
        if (wordPosition == word.length()) {
            return terminal[automatPosition];
        }
        if (memory[wordPosition][automatPosition] != -1) {
            return memory[wordPosition][automatPosition] == 1;
        }
        memory[wordPosition][automatPosition] = 0;
        int symbol = word.charAt(wordPosition) - 'a';
        for (int newPosition : go[automatPosition][symbol]) {
            boolean result = walk(word, wordPosition + 1, newPosition, go, terminal);
            if (result) {
                memory[wordPosition][automatPosition] = 1;
                return true;
            }
        }
        return false;
    }

    public void run() {
        try {
            in = new FastScanner(new File("problem2.in"));
            out = new PrintWriter(new File("problem2.out"));

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
