import java.lang.reflect.Array;
import java.util.*;
import java.io.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    private static final int alphabet = 26;

    public void solve() throws IOException {
        int n = in.nextInt();
        int start = in.nextLine().charAt(0) - 'A';
        ArrayList<String>[] rules = new ArrayList[alphabet];
        for (int i = 0; i < alphabet; i++) {
            rules[i] = new ArrayList<>();
        }
        boolean[] wasNotTerminal = new boolean[alphabet];
        boolean[] hasEpsilon = new boolean[alphabet];
        for (int i = 0; i < n; i++) {
            String newLine = in.nextLine();
            int notTerm = newLine.charAt(0) - 'A';
            wasNotTerminal[notTerm] = true;
            if (newLine.length() < 5) {
                hasEpsilon[notTerm] = true;
                continue;
            }
            String applied = newLine.substring(5);
            boolean hasSmallLetters = false;
            for (char c : applied.toCharArray()) {
                hasSmallLetters |= Character.isLowerCase(c);
            }
            if (!hasSmallLetters) {
                rules[notTerm].add(applied);
            }
        }
        while (true) {
            boolean found = false;
            for (int c = 0; c < alphabet; c++) {
                if (!hasEpsilon[c]) {
                    for (String applied : rules[c]) {
                        boolean ok = true;
                        for (int i = 0; i < applied.length(); i++) {
                            ok &= hasEpsilon[applied.charAt(i) - 'A'];
                        }
                        if (ok) {
                            hasEpsilon[c] = true;
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
            if (wasNotTerminal[i] && hasEpsilon[i]) {
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
            in = new FastScanner(new File("epsilon.in"));
            out = new PrintWriter(new File("epsilon.out"));

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