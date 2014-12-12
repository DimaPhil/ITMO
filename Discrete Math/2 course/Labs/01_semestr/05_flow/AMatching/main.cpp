#define TASKNAME "matching"

#include <bits/stdc++.h>
 
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define sz(a) (int)a.size()
#define fst first
#define snd second
#define y1 osrughosduvgarligybakrybrogvba
#define y0 aosfigdalrowgyalsouvgrlvygalri                               
#define mp make_pair
#define pb push_back
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <bool> vb;
typedef vector <ll> vll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <int, ll> pil;
typedef vector <pii> vpii;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

template <typename T>
T sqr(T x) {
    return x * x;
}

template <typename T>
T abs(T x) {
    return x > 0 ? x : -x;
}

const double EPS = 1e-9;
const int INF = 1e9;
const ll INFLONG = (ll)1e18;

struct Graph {
    vvi graph;
    int n, k, m;
    vb used;
    vi getPair;

    Graph() {
        graph.clear();
        n = k = m = 0;
        used.clear();
    }

    Graph(int n, int k, int m) {
        this->n = n;
        this->k = k;
        this->m = m;
        graph.resize(n);
        getPair.resize(k);
        used.resize(n);
    }

    void adde(int v, int u) {
        graph[v].push_back(u);
    }

    void read() {
        scanf("%d%d%d", &n, &k, &m);
        *this = Graph(n, k, m);
        for (int i = 0; i < m; i++) {
            int v, u;
            scanf("%d%d", &v, &u);
            --v, --u;
            adde(v, u);
        }
    }

    bool dfs(int v) {
        if (used[v])
            return false;
        used[v] = true;
        for (auto &e : graph[v]) {
            if (getPair[e] == -1 || dfs(getPair[e])) {
                getPair[e] = v;
                return true;
            }
        }
        return false;
    }

    int findMatching() {
        for (int i = 0; i < k; i++)
            getPair[i] = -1;
        for (int v = 0; v < n; v++) {
            for (int i = 0; i < n; i++)
                used[i] = false;
            dfs(v);
        }
        int answer = 0;
        for (int i = 0; i < k; i++)
            answer += getPair[i] != -1;
        return answer;
    }
};

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  Graph graph;
  graph.read();
  printf("%d\n", graph.findMatching());
  return 0;
}
