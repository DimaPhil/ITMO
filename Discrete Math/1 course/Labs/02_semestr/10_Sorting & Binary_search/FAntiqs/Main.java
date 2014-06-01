
import java.io.*;
import java.util.*;
 
public class Main implements Runnable {
    private void solve() throws IOException {
        int n = nextInt();
        int p[] = new int[n];  
        for (int i = 0; i < n; i++)
            p[i] = i + 1;
        for (int i = 0; i < n; i++) {
            int tmp = p[i];
            p[i] = p[i >> 1];
            p[i >> 1] = tmp;
        }
        for (int i = 0; i < n; i++)
          print(p[i] + " ");
        println();
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
            file = "antiqs";
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