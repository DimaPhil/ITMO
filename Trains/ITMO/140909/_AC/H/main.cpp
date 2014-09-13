#define TASKNAME "scarecrow"

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

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int n, k;
  scanf("%d%d", &n, &k);
  vi a(n);
  for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
  vvi x(k);
  for (int i = 0; i < k; i++) {
      for (int j = i; j < n; j += k)
          x[i].pb(a[j]);
      sort(all(x[i]));
  }
  sort(all(a));
  vvi y(k);
  for (int i = 0; i < k; i++) {
      for (int j = i; j < n; j += k)
          y[i].pb(a[j]);
      sort(all(y[i]));
  }
  bool ok = 1;
  for (int i = 0; i < k; i++)
      for (int j = 0; j < sz(x[i]); j++)
          ok &= x[i][j] == y[i][j];
  puts(ok ? "YES" : "NO");
  return 0;
}
