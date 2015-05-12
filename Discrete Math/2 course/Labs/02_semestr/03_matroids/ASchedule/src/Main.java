import java.util.*;
import java.io.*;

public class Main {
    FastScanner in;
    PrintWriter out;

    private class Task implements Comparable<Task> {
        int day, weight;

        public Task(int day, int weight) {
            this.day = day;
            this.weight = weight;
        }

        public int compareTo(Task o) {
            if (day != o.day) {
                return day - o.day;
            }
            return o.weight - weight;
        }
    }

    public void solve() throws IOException {
        int n = in.nextInt();
        Task[] tasks = new Task[n];
        for (int i = 0; i < n; i++) {
            tasks[i] = new Task(in.nextInt(), in.nextInt());
        }
        Arrays.sort(tasks, (o1, o2) -> o1.compareTo(o2));
        TreeSet<Integer> taskQueue = new TreeSet<>();
        int nowDay = 0;
        long answer = 0;
        for (int i = 0; i < n; i++) {
            taskQueue.add(tasks[i].weight);
            if (nowDay >= tasks[i].day) {
                int weight = taskQueue.pollFirst();
                answer += weight;
            } else {
                nowDay++;
            }
        }
        out.println(answer);
    }

    public void run() {
        try {
            in = new FastScanner(new File("schedule.in"));
            out = new PrintWriter(new File("schedule.out"));

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