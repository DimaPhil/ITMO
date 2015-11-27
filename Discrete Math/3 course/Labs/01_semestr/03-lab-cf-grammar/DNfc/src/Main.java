import java.util.*;
import java.io.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    private static final int alphabet = 26;
    private static final int MOD = (int)1e9 + 7;

    boolean[] was;
    ArrayList<String>[] rules = new ArrayList[alphabet];

    public void solve() throws IOException {
        int n = in.nextInt();
        int start = in.nextLine().charAt(1) - 'A';
        for (int i = 0; i < alphabet; i++) {
            rules[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            String newLine = in.nextLine();
            int notTerm = newLine.charAt(0) - 'A';
            String applied = newLine.substring(5);
            rules[notTerm].add(applied);
        }
        String word = in.next();
        int[][][] dp = new int[word.length() + 1][word.length() + 1][alphabet];
        for (int len = 1; len <= word.length(); len++) {
            for (int l = 0; l <= word.length() - len; l++) {
                int r = l + len - 1;
                for (int c = 0; c < alphabet; c++) {
                    int answer = 0;
                    for (String rule : rules[c]) {
                        if (rule.length() == 1) {
                            if (l == r && rule.charAt(0) == word.charAt(l)) {
                                answer++;
                            }
                        } else {
                            int add = 0;
                            int leftChar = rule.charAt(0) - 'A';
                            int rightChar = rule.charAt(1) - 'A';
                            for (int i = l + 1; i <= r; i++) {
                                add += ((long) dp[l][i - 1][leftChar] * dp[i][r][rightChar]) % MOD;
                                if (add >= MOD) {
                                    add -= MOD;
                                }
                            }
                            answer += add;
                            if (answer >= MOD) {
                                answer -= MOD;
                            }
                        }
                    }
                    dp[l][r][c] = answer;
                }
            }
        }
        out.println(dp[0][word.length() - 1][start]);
    }

    public void run() {
        try {
            in = new FastScanner(new File("nfc.in"));
            out = new PrintWriter(new File("nfc.out"));

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