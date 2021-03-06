#define TASKNAME "text"

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

const int maxn = 3e5 + 10;

int n;
int p[maxn];
int sz[maxn];
int a[maxn];
int pos;

void go(int v) {
    while (a[v] > 1) {
        a[v] -= sz[pos];
        p[pos] = v;
        go(pos++);
    }
}

int main()
{
  #ifdef LocalHost
    freopen(TASKNAME".in", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
  #endif
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
      scanf("%d", &sz[i]), a[i] = sz[i];
  pos = 1;
  go(0);
  for (int i = 1; i < n; i++)
      printf("%d%c", p[i] + 1, " \n"[i == n - 1]);
  return 0;
}
