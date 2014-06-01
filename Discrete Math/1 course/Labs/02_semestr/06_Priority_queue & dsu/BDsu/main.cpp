#define TASKNAME "dsu"
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

const int maxn = 1e5 + 10;

int n;
char s[10];
int p[maxn], rank[maxn];
int mn[maxn], mx[maxn];
int size[maxn];

inline int get(int x)
{
  if (p[x] != x)
    p[x] = get(p[x]);
  return p[x];
}

inline void unite(int x, int y)
{
  x = get(x);
  y = get(y);
  if (x == y)
    return;
  if (rank[x] > rank[y])
    swap(x, y);
  p[x] = y;
  size[y] += size[x];
  mn[y] = min(mn[y], mn[x]);
  mx[y] = max(mx[y], mx[x]);
  if (rank[x] == rank[y])
    ++rank[y];
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i <= n; i++)
    p[i] = i, rank[i] = 0, mn[i] = i, mx[i] = i, size[i] = 1;
  while (scanf("%s", s) >= 1)
  {
    if (s[0] == 'u')
    {
      int x, y;
      scanf("%d%d", &x, &y);
      unite(x, y);
    }
    else
    {
      int x;
      scanf("%d", &x);
      int root = get(x);
      printf("%d %d %d\n", mn[root], mx[root], size[root]);
    }
  }
  return 0;
}

