#define TASKNAME "post"

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

const int maxn = 510;
const int maxalph = 30;
const int maxq = maxn * maxn * 10;

int n, m;
char a[maxn][maxn];
vpii positions[maxalph];
int d[maxalph][maxn][maxn];
int dist[maxalph][maxalph];
pii q[maxq];     
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
      scanf("%s", a[i]);
      for (int j = 0; j < m; j++)
          if (isalpha(a[i][j]))
              positions[a[i][j] - 'a'].pb(mp(i, j));
  }

  for (int c = 0; c < maxalph; c++)
      for (int t = c + 1; t < maxalph; t++)
          dist[c][t] = dist[t][c] = INF;
  for (int c = 0; c < maxalph; c++) {
      for (int i = 0; i < n; i++)  
      for (int j = 0; j < m; j++)
          d[c][i][j] = INF;
      int start = 0, end = 0;
      for (int it = 0; it < sz(positions[c]); it++)
          q[end++] = positions[c][it], d[c][positions[c][it].fst][positions[c][it].snd] = 0;
      while (start != end) {
          pii cur = q[start++];
          if (start == maxq)
              start = 0;
          int x = cur.fst;
          int y = cur.snd;
          for (int it = 0; it < 4; it++) {
              int nx = x + dx[it];
              int ny = y + dy[it];
              if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                  continue;
              if (d[c][nx][ny] > d[c][x][y] + 1) {
                  d[c][nx][ny] = d[c][x][y] + 1;
                  q[end++] = mp(nx, ny);
                  if (end == maxq)
                      end = 0;
                  if (isalpha(a[nx][ny])) {
                      dist[c][a[nx][ny] - 'a'] = min(dist[c][a[nx][ny] - 'a'], d[c][nx][ny] + 1);
                  }
              }                 
          }                              
      } 
  }

  for (int k = 0; k < maxalph; k++)
  for (int i = 0; i < maxalph; i++)
  for (int j = 0; j < maxalph; j++)
      dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  eprintf("%d %d %d\n", dist[0][0], dist[0][1], dist[1][1]);

  int q;
  scanf("%d", &q);
  for (int it = 0; it < q; it++) {
      int x1, y1, x2, y2;
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      --x1, --y1, --x2, --y2;
      int bestAns = abs(x1 - x2) + abs(y1 - y2);
      for (int c = 0; c < maxalph; c++)
      for (int t = 0; t < maxalph; t++)
          if (dist[c][t] != INF)
              bestAns = min(bestAns, dist[c][t] + d[c][x1][y1] + d[t][x2][y2] + 1);
      printf("%d%c", bestAns, " \n"[it == q - 1]);
  }
  return 0;
}
                                           