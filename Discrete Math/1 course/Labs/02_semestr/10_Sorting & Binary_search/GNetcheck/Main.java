
import java.io.*;
import java.util.*;
 
public class Main implements Runnable {
    private void solve() throws IOException {
        int n = nextInt(), m = nextInt(), k = nextInt();
        int[][] is = new int[k][], js = new int[k][];
        int[] size = new int[k];
        for (int i = 0; i < k; i++) {
            size[i] = nextInt();
            is[i] = new int[size[i]];
            js[i] = new int[size[i]];
            for (int j = 0; j < size[i]; j++) {
                is[i][j] = nextInt();
                js[i][j] = nextInt();
                --is[i][j];
                --js[i][j];
                if (is[i][j] > js[i][j]) {
                    int tmp = is[i][j];
                    is[i][j] = js[i][j];
                    js[i][j] = tmp;
                }
            }
        }
 
        boolean fail = false;
        for (int msk = 0; msk < (1 << n); msk++) {
            int[] bs = new int[n];
            for (int i = 0; i < n; i++)
                bs[i] = (msk >> i) & 1;
            for (int i = 0; i < k; i++)
                for (int j = 0; j < size[i]; j++)
                    if (bs[is[i][j]] > bs[js[i][j]]) {
                        int tmp = bs[is[i][j]];
                        bs[is[i][j]] = bs[js[i][j]];
                        bs[js[i][j]] = tmp;
                    }
 
            boolean ok = true;
            for (int i = 0; i < n - 1; i++)
                ok &= (bs[i] <= bs[i + 1]);
            fail |= !ok;
        }
        println(fail == false ? "Yes" : "No");                    
    }
     
    public static void main(String[] args) {
        new Main().run();
    }
     
    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;
     
    public void run() {
        try {
            String file = "";
            file = "netcheck";
            if (file.equals("console")) {
                reader = new BufferedReader(new InputStreamReader(System.in));
                writer = new PrintWriter(System.out);
            } else if (file.equals("")) {
                reader = new BufferedReader(new FileReader(new File("input.txt")));
                writer = new PrintWriter(new File("output.txt"));
            } else {
                reader = new BufferedReader(new FileReader(new File(file + ".in")));
                writer = new PrintWriter(new File(file + ".out"));
            }
            solve();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(239);
        }
    }
     
    void halt() {
        writer.close();
        System.exit(0);
    }
     
    void print(Object... objects) {
        for (int i = 0; i < objects.length; i++) {
            if (i != 0) writer.print(' ');
            writer.print(objects[i]);
        }
    }
     
    void println(Object... objects) {
        print(objects);
        writer.println();
    }
     
    String nextLine() throws IOException {
        return reader.readLine();
    }
     
    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens())
            tokenizer = new StringTokenizer(nextLine());
        return tokenizer.nextToken();
    }
     
    int nextInt() throws NumberFormatException, IOException {
        return Integer.parseInt(nextToken());
    }
     
    long nextLong() throws NumberFormatException, IOException {
        return Long.parseLong(nextToken());
    }
     
    double nextDouble() throws NumberFormatException, IOException {
        return Double.parseDouble(nextToken());
    }
}