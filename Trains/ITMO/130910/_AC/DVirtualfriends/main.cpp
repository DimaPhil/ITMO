#define TASKNAME "virtualfriends"
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

const int maxn = 2e5 + 100;

int t, n;
map <string, int> g;
int cnt;
int size[maxn], p[maxn];

inline int get(string &s)
{
  if (g.find(s) == g.end())
    g[s] = cnt++;
  return g[s];
}

inline int getr(int x)
{
  if (x == p[x])
    return x;
  return p[x] = getr(p[x]);
}

inline int unite(int a, int b)
{
  a = getr(a);
  b = getr(b);
  if (a == b)
    return size[a];
  int ans = size[a] + size[b];
  if (rand() & 1)
    p[a] = b, size[b] += size[a];
  else
    p[b] = a, size[a] += size[b];
  return ans;
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  srand(time(NULL));
  cin >> t;
  for (int tt = 0; tt < t; tt++)
  {
    cin >> n;
    g.clear();
    cnt = 0;
    for (int i = 0; i < n * 2; i++)
      p[i] = i, size[i] = 1;
    for (int i = 0; i < n; i++)
    {
      string s1, s2;
      cin >> s1 >> s2;
      int n1 = get(s1), n2 = get(s2);
      printf("%d\n", unite(n1, n2));
    }
  }
  return 0;
}

