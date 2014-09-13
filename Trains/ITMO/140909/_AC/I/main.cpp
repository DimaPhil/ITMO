#define TASKNAME "shadow"

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

struct event {
    int x, type;
    event() {x = type = 0;}
    event(int x, int type) : x(x), type(type) {}
};

inline bool operator < (const event &a, const event &b) { return a.x < b.x || (a.x == b.x && a.type < b.type);}

const int maxn = 3e5 + 10;

int n;
int x[maxn], h[maxn];
int W, H;

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
      scanf("%d%d", &x[i], &h[i]);
  scanf("%d%d", &W, &H);
  set <int> s;
  for (int i = 0; i < n; i++)
      s.insert(x[i]);
  set <int> pts;
  for (int i = 0; i < n; i++) {
      set<int>::iterator it = s.upper_bound(x[i]);
      if (it != s.end()) {
          int xx = *it;
          if (xx < x[i] + W)
              continue;
      }
      pts.insert(x[i] + W);
  }
  for (int i = 0; i < n; i++) {
      if (h[i] >= H) {
          int right = x[i] + h[i] - H;
          set <int>::iterator it = pts.lower_bound(x[i]);
          if (it != pts.end() && *it <= right) {
              puts("YES");
              return 0;
          }
      }
  }
  puts("NO");
  return 0;
}
