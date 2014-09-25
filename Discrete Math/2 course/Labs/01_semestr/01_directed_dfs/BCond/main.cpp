#define TASKNAME "cond"

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

const int maxn = 2e5 + 10;

int n, m;
vi topsort;
vi gr[maxn], grRev[maxn];
bool was[maxn];
int component[maxn];

void dfs(int v) {
    was[v] = 1;
    for (int i = 0; i < sz(gr[v]); i++)
        if (!was[gr[v][i]])
            dfs(gr[v][i]);
    topsort.pb(v);
}

void dfsRev(int v, int componentNumber) {
    was[v] = 1;
    component[v] = componentNumber;
    for (int i = 0; i < sz(grRev[v]); i++)
        if (!was[grRev[v][i]])
            dfsRev(grRev[v][i], componentNumber);
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      --a, --b;
      gr[a].pb(b);
      grRev[b].pb(a);
  } 

  for (int i = 0; i < n; i++)
      if (!was[i])
          dfs(i);
  reverse(all(topsort));
  for (int i = 0; i < n; i++)
      was[i] = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++)
      if (!was[topsort[i]])
          dfsRev(topsort[i], cnt++);
  printf("%d\n", cnt);
  for (int i = 0; i < n; i++)
      printf("%d%c", component[i] + 1, " \n"[i == n - 1]);
  return 0;
}
                 