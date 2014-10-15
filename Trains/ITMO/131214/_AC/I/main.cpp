#define TASKNAME "i"

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>

#define EPS (1e-9)
#define INF (1e9)
#define INFLONG (1e18)
#define all(a) (a).begin, (a).end()
#define sz(a) (int)a.size()
#define zero(a) memset(a, 0, sizeof(a))
#define sqr(a) ((a) * (a))
#define fst first
#define snd second
#define y1 dfkljaf
#define y0 flksdjf
#define pb push_back
#define mp make_pair
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
typedef pair <ll, ll> pll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;

const int maxn = 2e6 + 10;

int n, m, k;
vi colors[maxn];
int color[maxn];
int p[maxn];

int get(int x)
{
  return p[x] == x ? x : p[x] = get(p[x]);
}

void unite(int x, int y)
{
  x = get(x);
  y = get(y);
  if (x == y)
    return;
  if (rand() & 1)
    p[x] = y;
  else
    p[y] = x;
}     
        
int main()
{
  srand(time(NULL));
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++)
    p[i] = i;
  vi root(k + 1, -1);
  for (int i = 0; i < n; i++)
  {
    int x;
    scanf("%d", &x);
    colors[x].pb(i);
    color[i] = x;
    root[x] = i;
  }
  for (int i = 1; i <= k; i++)
    for (int j = 1; j < sz(colors[i]); j++)
    {
      unite(colors[i][j], colors[i][0]);
      color[get(colors[i][0])] = i;
    }

  for (int i = 0; i < m; i++)
  {
    int from, to;
    scanf("%d%d", &from, &to);
    if (root[from] == -1 || color[get(root[from])] != from)
      continue;
    if (root[to] == -1 || color[get(root[to])] != to)
    {
      root[to] = root[from];
      color[get(root[from])] = to;
      continue;
    }
    unite(root[from], root[to]);
    root[to] = root[from];
    color[get(root[from])] = to;
  }

  for (int i = 0; i < n; i++)         
    printf("%d%c", color[get(i)], " \n"[i == n - 1]);
  return 0;
}
