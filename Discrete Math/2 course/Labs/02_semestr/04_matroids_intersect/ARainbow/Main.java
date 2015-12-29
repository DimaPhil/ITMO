import java.util.*;
import java.io.PrintWriter;

public class highways_petr {
    class DisjointSet<T>
    {
        Map<T,T> parents = new HashMap<T,T>();
        Random random = new Random();

        public void add(T obj) {
            parents.put(obj, obj);
        }

        public T getRoot(T obj) {
            T root = parents.get(obj);
            if (root == obj)
                return root;
            else
                root = getRoot(root);
            parents.put(obj, root);
            return root;
        }

        public void unite(T obj1, T obj2) {
            obj1 = getRoot(obj1);
            obj2 = getRoot(obj2);
            if (random.nextBoolean())
                parents.put(obj1, obj2);
            else
                parents.put(obj2, obj1);
        }
    }

    class City {
        boolean visited;
        City previous;
        Highway reachedBy;
        List<Edge> edges;

        public City() {
            visited = false;
            previous = null;
            reachedBy = null;
            edges = new LinkedList<Edge>();
        }
    }

    class Company {
        boolean taken;

        public Company() {
            taken = false;
        }
    }

    class Highway {
        City city1;
        City city2;
        Company company;
        boolean taken;
        Highway previous;
        boolean visited;
        int index;

        public Highway() {
            visited = false;
            city1 = null;
            city2 = null;
            company = null;
            taken = false;
            previous = null;
        }
    }

    class Edge {
        City dest;
        Highway highway;

        public Edge(City dest, Highway highway) {
            this.dest = dest;
            this.highway = highway;
        }
    }


    City[] cities;
    Highway[] highways;
    Map<Integer, Company> companies;

    void readInput() {
        Scanner scanner = new Scanner(System.in);

        int nCities = scanner.nextInt();
        int nHighways = scanner.nextInt();

        highways = new Highway[nHighways];
        cities = new City[nCities];

        for (int i = 0; i < cities.length; i++) {
            cities[i] = new City();
        }

        companies = new HashMap<Integer, Company>();

        for (int i = 0; i < highways.length; ++i) {
            highways[i] = new Highway();
            highways[i].city1 = cities[scanner.nextInt() - 1];
            highways[i].city2 = cities[scanner.nextInt() - 1];
            int companyID = scanner.nextInt() - 1;
            if (!companies.containsKey(companyID))
                companies.put(companyID, new Company());
            highways[i].company = companies.get(companyID);
            highways[i].index = i + 1;
        }

        for (Highway highway : highways) {
            highway.city1.edges.add(new Edge(highway.city2, highway));
            highway.city2.edges.add(new Edge(highway.city1, highway));
        }
    }

    void solve() {
        quickStart();
        while (true) {
            Queue<Highway> queue = new LinkedList<Highway>();

            for (Highway cur : highways) {
                if (!cur.company.taken) {
                    cur.previous = null;
                    cur.visited = true;
                    queue.add(cur);
                } else
                    cur.visited = false;
            }

            Highway finish = null;

            while (!queue.isEmpty()) {
                Highway cur = queue.poll();

                if (cur.taken) {
                    for (Highway next : highways) {
                        if (!next.visited && next != cur && next.company == cur.company) {
                            next.visited = true;
                            next.previous = cur;
                            queue.add(next);
                        }
                    }
                }
                else
                {
                    List<Highway> nexts = findCycling(cur);

                    if (nexts == null) {
                        finish = cur;
                        break;
                    }

                    for (Highway next : nexts) {
                        if (!next.visited) {
                            next.visited = true;
                            next.previous = cur;
                            queue.add(next);
                        }
                    }
                }
            }

            if (finish == null)
                break;

            while (finish != null) {
                finish.taken = !finish.taken;
                finish.company.taken = true;
                finish = finish.previous;
            }
        }
    }

    private void quickStart() {
        DisjointSet<City> dsu = new DisjointSet<City>();
        for (City city : cities)
            dsu.add(city);
        int count = 0;
        for (Highway highway : highways) {
            if (highway.company.taken)
                continue;
            if (dsu.getRoot(highway.city1) == dsu.getRoot(highway.city2))
                continue;
            highway.taken = true;
            highway.company.taken = true;
            dsu.unite(highway.city1, highway.city2);
            count++;
        }
    }

    List<Highway> findCycling(Highway start) {
        Queue<City> queue = new LinkedList<City>();

        for (City city : cities) {
            city.visited = false;
            city.previous = null;
            city.reachedBy = null;
        }

        queue.add(start.city1);
        start.city1.visited = true;

        while (!start.city2.visited && !queue.isEmpty()) {
            City cur = queue.poll();

            for (Edge edge : cur.edges)
                if (edge.highway.taken) {
                    City next = edge.dest;
                    if (!next.visited) {
                        next.visited = true;
                        next.previous = cur;
                        next.reachedBy = edge.highway;
                        queue.add(next);
                    }
                }
        }

        if (!start.city2.visited)
            return null;

        List<Highway> result = new LinkedList<Highway>();

        City last = start.city2;

        while (last.previous != null) {
            result.add(last.reachedBy);
            last = last.previous;
        }

        return result;
    }

    void printOutput() {
        int result = 0;

        for (Highway highway : highways)
            if (highway.taken)
                ++result;

        PrintWriter printWriter = new PrintWriter(System.out);

        printWriter.println(result);

        boolean first = true;
        for (Highway highway : highways)
            if (highway.taken) {
                if (first)
                    first = false;
                else
                    printWriter.print(' ');

                printWriter.print(highway.index);
            }

        printWriter.println();
        printWriter.close();
    }

    void run() {
        readInput();
        solve();
        printOutput();
    }

    public static void main(String[] args) {
        new highways_petr().run();
    }
}