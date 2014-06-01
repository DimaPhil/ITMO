public class BinarySearch {

    //pre: n > 0, a[0] < x
    static int lastLess(int[] a, int n, int x) {
        int l = 0, r = n;
        //0 <= l < r - 1 <= n - 1, a[l] < x, (r == n || a[r] >= x)
        while (l < r - 1) {
            //0 <= l < r - 1 <= n - 1, a[l] < x, (r == n || a[r] >= x)
            int m = (l + r) / 2;
            //0 <= l < m < r <= n, a[l] < x, (r == n || a[r] >= x)
            if (a[m] < x) {
                l = m;
                //0 <= l < r <= n, a[l] < x, (r == n || a[r] >= x)
            } else {
                r = m;
                //0 <= l < r < n, a[l] < x, a[r] >= x
            }
            //0 <= l < r <= n, a[l] < x, (r == n || a[r] >= x)
        }
        //0 <= l = r - 1 <= n - 1, a[l] < x, (r == n || a[r] >= x)
        return l;
    }
    //post: result = [0, n - 1], a[result] < x, (result + 1 == n || a[result + 1] >= x)

    //pre: n > 0
    static int binarySearch(int[] a, int n, int x)
    {
        //n > 0
        if (a[0] >= x) {
            //result = 0, a[result] >= x, result = 0
            return 0;
        }

        int l = lastLess(a, n, x);
        //l = [0, n - 1], a[l] < x, (l + 1 == n || a[l + 1] >= x)
        if (l + 1 == n) {
            //result = -1, no such index
            return -1;
        } else {
            //result = [0, n - 1], a[result] >= x, a[result - 1] < x
            return l + 1;
        }
        //(result == -1, no such index i that a[i] >= x) || (result = [0, n - 1], a[result] >= x, (result == 0 || a[result - 1] < x))
    }   
    //post: (result == -1, no such index i that a[i] >= x) || (result = [0, n - 1], a[result] >= x, (result == 0 || a[result - 1] < x))

    public static void main(String[] args) {
        int n = args.length - 1;
        int x = Integer.parseInt(args[0]);
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(args[i + 1]);
        }

        int idx = -1;
        if (n > 0) {
            //n > 0
            idx = binarySearch(a, n, x);
            //n > 0, (idx == -1, no such index) || (idx = [0..n - 1], a[idx] >= x, (idx == 0 || a[idx - 1] < x))
        } else {
            //n == 0, idx == -1, no such index
        }
        //(idx == -1, no such index) || (idx = [0..n - 1], a[idx] >= x, (idx == 0 || a[idx - 1] < x))
        if (idx == -1) {
            System.out.println("No such index");
        } else {
            System.out.println(idx);
        }
    } 
}