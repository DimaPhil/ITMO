import java.util.*;
import java.io.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    private static final int alphabet = 26;

    public boolean check(int start, ArrayList<String>[] rules, String word, int position) {
        if (position == word.length()) {
            return start == 0;
        }
        for (String rule : rules[start]) {
            if (rule.charAt(0) != word.charAt(position)) {
                continue;
            }
            if (check(rule.length() == 1 ? 0 : rule.charAt(1) - 'A', rules, word, position + 1)) {
                return true;
            }
        }
        return false;
    }

    public void solve() throws IOException {
        int n = in.nextInt();
        int start = in.next().charAt(0) - 'A';
        ArrayList<String>[] rules = new ArrayList[alphabet];
        for (int i = 0; i < alphabet; i++) {
            rules[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            char notTerm = in.next().charAt(0);
            in.next();
            String applyed = in.next();
            rules[notTerm - 'A'].add(applyed);
        }
        int m = in.nextInt();
        for (int i = 0; i < m; i++) {
            String word = in.next();
            out.println(check(start, rules, word, 0) ? "yes" : "no");
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File("automaton.in"));
            out = new PrintWriter(new File("automaton.out"));

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