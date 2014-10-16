#define TASKNAME "negcycle"

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
const ll INFLONG = (ll)7e18;

const int MAX_IT = 500;

vector < vector <pii> > gr;

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int n;
  scanf("%d", &n);
  gr.resize(n);
  for (int i = 0; i < n; i++)
  for (int j = 0; j < n; j++) {
      int x;
      scanf("%d", &x);
      if (x != INF)
          gr[i].pb(mp(j, x));
  }

  for (int s = 0; s < n; s++) {
      vll d(n, INFLONG);
      d[s] = 0;
      vi p(n, -1);
      vb better(n, false);
      for (int it = 0; it < MAX_IT; it++) {
          vll nd(n);
          for (int i = 0; i < n; i++)
              nd[i] = d[i], better[i] = false;

          for (int i = 0; i < n; i++) {
              for (auto &e : gr[i]) {
                  int u = e.fst;
                  if (d[i] != INFLONG && d[u] > d[i] + e.snd) {
                      better[u] = true;
                      nd[u] = d[i] + e.snd;
                      p[u] = i;
                  }
              }
          }

          for (int i = 0; i < n; i++)
              d[i] = nd[i];
      }

      int v = -1;
      for (int i = 0; i < n; i++)
          if (better[i])
              v = i;
      if (v != -1) {
          printf("YES\n");
          for (int i = 0; i < n; i++)
              v = p[v];

          vi path;
          int v0 = v;
          
          path.pb(v);
          v = p[v];
          while (v != v0) {
              path.pb(v);   
              v = p[v];
          }
          reverse(all(path));
          printf("%d\n", sz(path) + 1);
          for (auto &v : path)
              printf("%d ", v + 1);
          printf("%d\n", path[0] + 1);
          return 0;
      }          
  }
  printf("NO\n");
  return 0;
}
