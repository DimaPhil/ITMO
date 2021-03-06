#define TASKNAME "signal"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <cassert>
#include <functional>
#include <iomanip>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
 
#define sqr(a) ((a) * (a))
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define abs(a) (((a) < 0) ? -(a) : (a))
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

const double EPS = 1e-9;
const int INF = 1e9;
const ll INFLONG = (ll)1e18;

const int maxn = 1e5 + 10;

int n;
vi gr[maxn];
bool was[maxn];
             
int dfs(int v) {
    was[v] = 1;
    vi cs;
    for (int i = 0; i < sz(gr[v]); i++) {
        int u = gr[v][i];
        if (was[u])
            continue;
        cs.pb(dfs(u));
    }
    sort(all(cs), greater<int>());
    int ans = 0;
    for (int i = 0; i < sz(cs); i++)
        ans = max(cs[i] + i + 1, ans);
    return ans;
}
           
int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      --a, --b;
      gr[a].pb(b);
      gr[b].pb(a);
  }
  printf("%d\n", dfs(0));
  return 0;
}
