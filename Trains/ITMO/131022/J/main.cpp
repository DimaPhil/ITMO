#define TASKNAME "text"

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <cstring>
#include <string>

#define EPS (1e-9)
#define INF (1e9)
#define INFLONG ((long long)(1e18))
#define sqr(a) ((a) * (a))
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define sz(a) (int)a.size()
#define fst first
#define snd second
#define y1 ldkj
#define y0 sdal
#define mp make_pair
#define pb push_back
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <bool> vb;
typedef vector <vi> vvi;
typedef vector <vll> vvll;
typedef vector <vb> vvb;
typedef pair <int, int> pii;
typedef vector <pii> vpii;

int n;
map <ll, int> d;
int best_ans = INF;
vvi a, need;
char s[10];
ll need_hash;
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

inline ll code(vvi &a, int x, int y)
{
  int ans = 0;
  int now = 0;
  for (int i = 0; i < sz(a); i++)
    for (int j = 0; j < sz(a[i]); j++)
      ans += a[i][j] * (1ll << now), now++;
  return ans * n * n + x * n + y;
}

inline void go(vvi &a, int x, int y, int turns)
{
  if (turns >= best_ans)
    return;
  ll hash = code(a, x, y);
  if (d.find(hash) != d.end() && d[hash] <= turns)
    return;
  d[hash] = turns;
  if (hash == need_hash)
  {
    best_ans = turns;
    return;
  }
  vvi na(n, vi(n, 0));
  for (int it = 0; it < 8; it++)
  {
    int nx = x + dx[it];
    int ny = y + dy[it];
    if (nx < 0 || nx >= n || ny < 0 || ny >= n || a[nx][ny])
      continue;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
      {
        if (i == nx && j == ny)
          continue;
        int cnt = 0;
        for (int it2 = 0; it2 < 8; it2++)
        {
          int X = i + dx[it2];
          int Y = j + dy[it2];
          if (X < 0 || X >= n || Y < 0 || Y >= n)
            continue;
          cnt += (a[X][Y] || (nx == X && ny == Y));
        }
        na[i][j] = 0;
        if (a[i][j] && cnt >= 2 && cnt <= 3)
          na[i][j] = 1;
        if (!a[i][j] && cnt == 3)
          na[i][j] = 1;
      }
    go(na, nx, ny, turns + 1);
  }
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  while (scanf("%d", &n) >= 1)
  {
    if (!n)
      return 0;
    a.resize(n);
    need.resize(n);
    int mx = -1, my = -1;
    for (int i = 0; i < n; i++)
    {
      a[i].resize(n);
      need[i].resize(n);
      for (int j = 0; j < n; j++)
        a[i][j] = need[i][j] = 0;
      scanf("%s", s);
      for (int j = 0; j < n; j++)
      {
        if (s[j] == '@')
        {
          mx = i, my = j;
          a[i][j] = 0;
          continue;
        }  
        a[i][j] = s[j] == '#' ? 1 : 0, need[i][j] = 0;
      }
    }
    assert(mx != -1 && my != -1);
    need_hash = code(need, mx, my);
    best_ans = INF;
    d.clear();
    go(a, mx, my, 0);
    printf("%d\n", best_ans == INF ? -1 : best_ans);
  }
  return 0;
}
