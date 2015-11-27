import java.util.*;
import java.io.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    private static final int alphabet = 26;

    boolean[] was;
    ArrayList<String>[] rules = new ArrayList[alphabet];

    void markNotTerms(int v) {
        was[v] = true;
        for (String rule : rules[v]) {
            for (char c : rule.toCharArray()) {
                if (Character.isUpperCase(c) && !was[c - 'A']) {
                    markNotTerms(c - 'A');
                }
            }
        }
    }

    public void solve() throws IOException {
        int n = in.nextInt();
        int start = in.nextLine().charAt(1) - 'A';
        for (int i = 0; i < alphabet; i++) {
            rules[i] = new ArrayList<>();
        }
        boolean[] wasNotTerminal = new boolean[alphabet];
        for (int i = 0; i < n; i++) {
            String newLine = in.nextLine();
            int notTerm = newLine.charAt(0) - 'A';
            wasNotTerminal[notTerm] = true;
            if (newLine.length() < 5) {
                rules[notTerm].add("");
                continue;
            }
            String applied = newLine.substring(5);
            for (char c : applied.toCharArray()) {
                if (Character.isUpperCase(c)) {
                    wasNotTerminal[c - 'A'] = true;
                }
            }
            rules[notTerm].add(applied);
        }
        was = new boolean[alphabet];
        markNotTerms(start);
        boolean[] isOk = new boolean[alphabet];
        for (int c = 0; c < alphabet; c++) {
            boolean ok = false;
            for (String rule : rules[c]) {
                if (rule.toLowerCase().equals(rule)) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                isOk[c] = true;
            }
        }
        while (true) {
            boolean found = false;
            for (int c = 0; c < alphabet; c++) {
                if (!isOk[c]) {
                    for (String applied : rules[c]) {
                        boolean ok = true;
                        for (int i = 0; i < applied.length(); i++) {
                            if (!Character.isUpperCase(applied.charAt(i))) {
                                continue;
                            }
                            ok &= isOk[applied.charAt(i) - 'A'];
                        }
                        if (ok) {
                            isOk[c] = true;
                            found = true;
                            break;
                        }
                    }
                }
            }
            if (!found) {
                break;
            }
        }
        ArrayList<String> answer = new ArrayList<>();
        for (int i = 0; i < alphabet; i++) {
            if (wasNotTerminal[i] && (!was[i] || !isOk[i])) {
                answer.add(String.valueOf((char)('A' + i)));
            }
        }
        for (int i = 0; i < answer.size(); i++) {
            out.print(answer.get(i));
            if (i + 1 < answer.size()) {
                out.print(" ");
            }
        }
        out.println();
    }

    public void run() {
        try {
            in = new FastScanner(new File("useless.in"));
            out = new PrintWriter(new File("useless.out"));

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

        String nextLine() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken("\n");
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] arg) {
        new Main().run();
    }
}