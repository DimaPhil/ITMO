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

const int maxn = 1010;
const int maxq = maxn * maxn;

int xa, ya, xb, yb;
int n;
int sx[maxn], sy[maxn], fx[maxn], fy[maxn];
int t[maxn];
vpii go[maxn][maxn];
vi ts[maxn][maxn];
int q[maxq];
int get[maxn][maxn];

int sqr(int x) {
    return x * x;
}

double sqr(double x) {
    return x * x;
}

int main()
{
  #ifdef LocalHost
    freopen(TASKNAME".in", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
  #endif
  scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
  scanf("%d", &n);

  vpii pts;

  pts.pb(mp(xa, ya));
  pts.pb(mp(xb, yb));
  for (int i = 0; i < n; i++) {
      scanf("%d%d%d%d%d", &sx[i], &sy[i], &fx[i], &fy[i], &t[i]);
      pts.pb(mp(sx[i], sy[i]));
      pts.pb(mp(fx[i], fy[i]));
      go[sx[i]][sy[i]].pb(mp(fx[i], fy[i]));
      ts[sx[i]][sy[i]].pb(t[i]);
  }
  sort(all(pts));
  int pSize = unique(all(pts)) - pts.begin();

  int idx = find(pts.begin(), pts.begin() + pSize, mp(xa, ya)) - pts.begin();
  int idxFinish = find(pts.begin(), pts.begin() + pSize, mp(xb, yb)) - pts.begin();
  for (int i = 0; i < n; i++) {
      get[fx[i]][fy[i]] = find(pts.begin(), pts.begin() + pSize, mp(fx[i], fy[i])) - pts.begin();
  }

  int start = 0, end = 0;
  q[end++] = idx;
  vector <double> d(pSize, 1e18);
  d[idx] = 0;
  while (start != end) {
      int cur = q[start++];
      if (start == maxq)
          start = 0;
      for (int i = 0; i < pSize; i++) {
          double len = sqrt(sqr(pts[cur].fst - pts[i].fst) + sqr(pts[cur].snd - pts[i].snd));
          if (d[i] - EPS > d[cur] + len)  {
              d[i] = d[cur] + len;
              q[end++] = i;
              if (end == maxq)
                  end = 0;
          }        
      }
      for (int i = 0; i < sz(go[pts[cur].fst][pts[cur].snd]); i++) {
          pii u = go[pts[cur].fst][pts[cur].snd][i];
          int ttime = ts[pts[cur].fst][pts[cur].snd][i];
          int idx = get[u.fst][u.snd];
          if (d[idx] > d[cur] + ttime) {
              d[idx] = d[cur] + ttime;
              q[end++] = idx;
              if (end == maxq)
                  end = 0;
          }
      }
  }
  printf("%.10lf\n", d[idxFinish]);
  return 0;     
}
