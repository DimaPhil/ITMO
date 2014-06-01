#define TASKNAME "choose"
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
vvi ans;
vi now;
vb was;

inline void go(int pos, int last, int taken)
{
  if (taken == k)
  {
    ans.pb(now);
    return;
  }
  if (pos == n)
    return;
  for (int i = last + 1; i < n; i++)
    if (!was[i])
    {
      was[i] = 1;
      now[pos] = i;
      go(pos + 1, i, taken + 1);
      was[i] = 0;
    }
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d%d", &n, &k);
  now.resize(k);
  was.resize(n);
  for (int i = 0; i < n; i++)
    was[i] = 0;
  go(0, -1, 0);
  //printf("%d\n", sz(ans));
  for (int i = 0; i < sz(ans); i++)
    for (int j = 0; j < sz(ans[i]); j++)
      printf("%d%c", ans[i][j] + 1, " \n"[j == sz(ans[i]) - 1]);
  return 0;
}
