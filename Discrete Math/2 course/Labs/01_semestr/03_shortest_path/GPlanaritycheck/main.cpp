#define TASKNAME "planaritycheck"

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

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int tests;
  scanf("%d", &tests);
  char s[100];
  while (tests--) {
      scanf("%s", s);
      int len = strlen(s);
      int n = -1;
      for (n = 1; n <= 6; n++)
          if (n * (n - 1) / 2 == len)
              break;
      assert(1 <= n && n <= 6);
      
      int pos = 0;
      vector <vb> gr(n + 10, vb(n + 10, false));
      for (int i = 0; i < n; i++)
      for (int j = 0; j < i; j++)
          gr[i][j] = gr[j][i] = s[pos++] - '0';
      
      bool ok = true;
      if (n == 6) {
          vi p(6);
          for (int i = 0; i < 6; i++)
              p[i] = i;
          sort(all(p));
          do {
              bool fail = false;
              for (int i = 0; i < 3; i++)
              for (int j = 3; j < 6; j++)
                  if (!gr[p[i]][p[j]])
                      fail = true;
              if (!fail)
                  ok = false;
          } while (next_permutation(all(p)));
      }
      
      if (n >= 5) {
          if (n == 6) {
             for (int i = 0; i < 6; i++)
             for (int v = 0; v < 6; v++)
             for (int u = v + 1; u < 6; u++)
                 if (gr[i][v] && gr[i][u]) {
                     gr[i][u] = gr[u][i] = false;
                     gr[i][v] = gr[v][i] = false;
                     bool lastgr = gr[v][u];
                     gr[v][u] = gr[u][v] = true;
                     
                     bool fail = false;
                     for (int ii = 0; ii < 6; ii++)
                     for (int jj = ii + 1; jj < 6; jj++)
                         if (ii != i && jj != i && !gr[ii][jj])
                             fail = true;
                     if (!fail)
                         ok = false;
                         
                     gr[i][u] = gr[u][i] = true;
                     gr[i][v] = gr[v][i] = true;
                     gr[v][u] = gr[u][v] = lastgr;
                 }
          }

          vi p(6);
          for (int i = 0; i < 6; i++)
              p[i] = i;
          sort(all(p));
          do {
              bool fail = false;
              for (int i = 0; i < 5; i++)
              for (int j = i + 1; j < 5; j++)
                  if (!gr[p[i]][p[j]])
                      fail = true;
              if (!fail)
                  ok = false;
          } while (next_permutation(all(p)));
      }
      printf("%s\n", ok ? "YES" : "NO");
  }
  return 0;
}
