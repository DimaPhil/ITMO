#define TASKNAME "parts"
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
 
#define EPS (1e-9)
#define INF (int(1e9))
#define INFLONG (long long)(1e18)
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
#define next dlkjdslfkdj
#define prev dsdflksdfjl
#define hash lkdfjldskfj
#define pi 3.1415926535897932384626433832795
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

int n, k;
vector <vvi> ans;
vi now;
vvi to_add;
vb was;

inline void go(int pos, int type, int taken)
{
  if (pos == n)
  {
    if (!sz(now))
      return;
    to_add[type] = now;
    if (type == k - 1)
    {
      ans.pb(to_add);
      return;
    }
    vi nnow = now;
    now.clear();
    go(0, type + 1, 0);
    now = nnow;
    return;
  }
  if (was[pos])
    go(pos + 1, type, taken);
  else
  {
    was[pos] = 1;
    now.pb(pos + 1);
    go(pos + 1, type, taken + 1);
    was[pos] = 0;
    now.pop_back();
    if (taken && type < k - 1)
      go(pos + 1, type, taken);
  }
}

inline bool Lessv(vi a, vi b)
{
  for (int i = 0; i < min(sz(a), sz(b)); i++)
    if (a[i] != b[i])
      return a[i] < b[i];
  return sz(a) < sz(b);
}

inline bool Less(vvi a, vvi b)
{
  for (int i = 0; i < min(sz(a), sz(b)); i++)
  {
    if (Lessv(a[i], b[i]))
      return 1;
    if (Lessv(b[i], a[i]))
      return 0;
  }
  return sz(a) < sz(b);
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d", &n);
  for (k = 1; k <= n; k++)
  {
    to_add.clear();
    was.clear();
    to_add.resize(k);
    was.resize(n);
    now.clear();

    go(0, 0, 0);
    //printf("%d\n", sz(ans));
    //eprintf("%.5lf\n", double(clock()) / CLOCKS_PER_SEC);
  }
  sort(all(ans), Less);
  for (int i = 1; i < sz(ans); i++, printf("\n"))
  {
    printf("%d %d\n", n, sz(ans[i]));
    for (int j = 0; j < sz(ans[i]); j++)
      for (int it = 0; it < sz(ans[i][j]); it++)
        printf("%d%c", ans[i][j][it], " \n"[it == sz(ans[i][j]) - 1]);
  }
  puts("0 0");
  return 0;
}

