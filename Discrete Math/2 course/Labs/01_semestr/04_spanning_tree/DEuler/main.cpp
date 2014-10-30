#define TASKNAME "euler"

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

const int maxn = 1010;

int n;
vi gr[maxn];
int bad_e[maxn][maxn], cnt[maxn][maxn];
int deg[maxn];
vi ans;

void dfs(int v) {
    for (int i = 0; i < sz(gr[v]); i++) {
        int u = gr[v][i];
        if (bad_e[v][u] < cnt[v][u]) {
            ++bad_e[v][u];
            ++bad_e[u][v];
            --deg[v];
            --deg[u];
            dfs(u);
        }
    }
    ans.pb(v);
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
      int k;
      scanf("%d", &k);
      deg[i] = k;
      for (int j = 0; j < k; j++) {
          int x;
          scanf("%d", &x);
          --x;
          gr[i].pb(x);
          ++cnt[i][x];
      }
  }
  vi cntv;
  for (int i = 0; i < n; i++)
      if (deg[i] % 2 == 1)
          cntv.pb(i);
  if (sz(cntv) != 0 && sz(cntv) != 2) {
      puts("-1");
      return 0;
  }
  ans.clear();
  int v = sz(cntv) ? cntv[0] : 0;
  dfs(v);
  printf("%d\n", sz(ans) - 1);
  for (int i = 0; i < sz(ans); i++) {
      printf("%d%c", ans[i] + 1, " \n"[i == sz(ans) - 1]);
  }
  return 0;
}
