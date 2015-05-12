import java.util.*;
import java.io.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    public void solve() throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] k = new int[m];
        boolean haveZero = false;
        HashSet<ArrayList<Integer>> elements = new HashSet<>();
        ArrayList<Integer>[] es = new ArrayList[m];
        for (int i = 0; i < m; i++) {
            es[i] = new ArrayList<>();
            k[i] = in.nextInt();
            haveZero |= k[i] == 0;
            for (int j = 0; j < k[i]; j++) {
                int x = in.nextInt();
                es[i].add(x);
            }
            Collections.sort(es[i]);
            elements.add(es[i]);
        }
        boolean okInside = true;
        for (int i = 0; i < m && okInside; i++) {
            int size = k[i];
            for (int mask = 0; mask < (1 << size); mask++) {
                ArrayList<Integer> sub = new ArrayList<>();
                for (int j = 0; j < size; j++) {
                    if ((mask & (1 << j)) > 0) {
                        sub.add(es[i].get(j));
                    }
                }
                if (!elements.contains(sub)) {
                    okInside = false;
                    break;
                }
            }
        }
        boolean okAdd = true;
        for (int i = 0; i < m && okAdd; i++) {
            for (int j = 0; j < m && okAdd; j++) {
                if (es[i].size() <= es[j].size()) {
                    continue;
                }
                ArrayList<Integer> b = (ArrayList<Integer>)es[j].clone();
                ArrayList<Integer> diff = new ArrayList<>();
                int p1 = 0;
                int p2 = 0;
                while (p1 < k[i] && p2 < k[j]) {
                    if (es[i].get(p1).equals(es[j].get(p2))) {
                        p1++;
                        p2++;
                    } else if (es[i].get(p1) < es[j].get(p2)) {
                        diff.add(es[i].get(p1));
                        p1++;
                    } else {
                        p2++;
                    }
                }
                while (p1 < k[i]) {
                    diff.add(es[i].get(p1));
                    p1++;
                }
                boolean found = false;
                for (int it = 0; it < diff.size(); it++) {
                    b.add(diff.get(it));
                    Collections.sort(b);
                    if (elements.contains(b)) {
                        found = true;
                        break;
                    }
                    b.remove(diff.get(it));
                }
                if (!found) {
                    okAdd = false;
                }
            }
        }
        out.println((haveZero && okAdd && okInside) ? "YES" : "NO");
    }

    public void run() {
        try {
            in = new FastScanner(new File("check.in"));
            out = new PrintWriter(new File("check.out"));

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