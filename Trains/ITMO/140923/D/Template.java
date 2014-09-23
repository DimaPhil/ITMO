
import java.util.*;
import java.io.*;
import java.math.*;
 
public class Template {
    Scanner in;
    PrintWriter out;
 
    static final int N = 1002;
    static BigInteger temp, r, r1, r2, a1;     
    static BigInteger[] a = new BigInteger[N];
    static BigInteger[] b = new BigInteger[N];
 
    public void solve() throws IOException {
        int n = in.nextInt();
        int[] p = new int[n];
        for (int i = 0; i < n; ++i) {
            p[i] = in.nextInt();
        }
                                                  
        a[n - 1] = BigInteger.valueOf(1);
        b[n - 1] = BigInteger.valueOf(p[n - 1]);
 
        for (int i = n - 2; i >= 0; --i) {
            /*a[i] = (sb.add(sa.negate()));
            r = BigInteger.valueOf(p[i]);
            temp = r.gcd(sa);
            r = r.divide(temp);
            a[i] = a[i].divide(temp);
            b[i] = sb.multiply(r);
             
            temp = sb.multiply(b[i]);
            sa = sa.multiply(b[i]).add(a[i].multiply(sb));
            sb = temp;
             
            temp = sa.gcd(sb);
            sa = sa.divide(temp);
            sb = sb.divide(temp);  */
 
            temp = BigInteger.valueOf(p[i + 1] - 1);
            r = b[i + 1].gcd(temp);
            a[i] = temp.divide(r).multiply(a[i + 1]);
            b[i] = b[i + 1].divide(r);
 
 
            temp = BigInteger.valueOf(p[i]);
            r = a[i].gcd(temp);
            a[i] = a[i].divide(r);
            b[i] = b[i].multiply(temp.divide(r)); 
        }
         
        for (int i = 0; i < n; ++i) {                         
            out.println(a[i].toString() + "/" + b[i].toString());
        } 
        out.close();
    }
 
    public void run() {
        try {
            in = new Scanner(System.in);
            out = new PrintWriter(System.out);
 
            solve();
 
            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
 
    /*class FastScanner {
        BufferedReader br;
        StringTokenizer st;
 
        FastScanner() {
            try {
                br = new BufferedReader(System.in);
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
    }         */
 
    public static void main(String[] arg) {
        new Template().run();
    }
}