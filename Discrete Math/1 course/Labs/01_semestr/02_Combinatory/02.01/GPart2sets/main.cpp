#define TASKNAME "part2sets"
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
 
int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d%d", &n, &k);
  to_add.resize(k);
  was.resize(n);
  go(0, 0, 0);
  //printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++, printf("\n"))
    for (int j = 0; j < k; j++)
      for (int it = 0; it < sz(ans[i][j]); it++)
        printf("%d%c", ans[i][j][it], " \n"[it == sz(ans[i][j]) - 1]);
  //eprintf("%.5lf\n", double(clock()) / CLOCKS_PER_SEC);
  return 0;
}
