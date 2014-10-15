#define TASKNAME "chords"

#include <cstdio>
#include <iostream>

#include <cmath>
#include <algorithm>
#include <functional>

#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>

#include <ctime>
#include <cassert>

#include <map>
#include <set>
#include <vector>
 
#define EPS 1e-9
#define INF int(1e9)
#define INFLONG (long long)(1e18)
#define sqr(a) ((a) * (a))
#define abs(a) (((a) < 0) ? -(a) : (a))
#define sz(a) (int)a.size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define fst first
#define snd second
#define y1 osrughosduvgarligybakrybrogvba
#define y0 aosfigdalrowgyalsouvgrlvygalri
#define mp make_pair
#define pb push_back
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

#ifdef WIN32
  #define I64d "%I64d"
#else
  #define I64d "%lld"
#endif
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <bool> vb;
typedef vector <vb> vvb;
typedef vector <ll> vl;
typedef vector <vl> vvl; 
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <int, ll> pil;
typedef vector <pii> vpii;

int n;

inline void update(vi &d, int v, int x)
{
  for (int a = v; a <= n; a = a | (a + 1))
    d[a] += x;
}

inline int get_ans(vi &d, int v)
{
  if (v <= 0)
    return 0;
  int s = 0;
  for (int a = v; a > 0; a = (a & (a + 1)) - 1)
    s += d[a];
  return s;
}

inline int get_ans(vi &d, int l, int r)
{
  if (l > r)
    return 0;
  return get_ans(d, r) - get_ans(d, l - 1);
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d", &n);
  vi a(n << 1);
  vi get(n + 1), cnt(n + 1), last(n << 1);
  int counter = 1;
  for (int i = 0; i < (n << 1); i++)
  {
    scanf("%d", &a[i]);
    last[i] = a[i];
    if (++cnt[a[i]] == 1)
      a[i] = counter, get[last[i]] = counter++;
    else
      a[i] = get[last[i]];
  }
  for (int i = 1; i <= n; i++)
    cnt[i] = 0;
  vi d(n + 1, 0), ans(n + 1);
  for (int i = 0; i < (n << 1); i++)
  {
    if (++cnt[a[i]] == 1)
      update(d, a[i], 1);
    else
    {
      ans[last[i]] = get_ans(d, a[i] + 1, n);
      update(d, a[i], -1);
    }  
  }

  for (int i = 1; i <= n; i++)
    get[i] = cnt[i] = 0;
  counter = 1;
  for (int i = (n << 1) - 1; i >= 0; i--)
  {
    if (++cnt[last[i]] == 1)
      a[i] = counter, get[last[i]] = counter++;
    else
      a[i] = get[last[i]];
  }
  for (int i = 1; i <= n; i++)
    d[i] = cnt[i] = 0;
  for (int i = (n << 1) - 1; i >= 0; i--)
  {
    if (++cnt[a[i]] == 1)
      update(d, a[i], 1);
    else
    {
      ans[last[i]] += get_ans(d, a[i] + 1, n);
      update(d, a[i], -1);
    }  
  }
  for (int i = 1; i <= n; i++)
    printf("%d\n", ans[i]);
  return 0; 
}
