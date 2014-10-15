#define TASKNAME "starship"
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

const int maxn = 1e7 + 100;
const ll modF = 1 << 7;
const ll modC = 1ll << 31;

int n, a, b;
ll F;
int f[maxn], c[maxn];
int L[maxn], R[maxn];
vi ids[1 << 16];

inline int mmod(ll x, ll mod)
{
  return (x % mod + mod) % mod;
}

inline bool Less(int a, int b)
{
  return R[a] < R[b];
}                 

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d%I64d", &n, &F);
  scanf("%d%d%d%d", &f[1], &c[1], &a, &b);
  f[1] = mmod(f[1], modF);
  c[1] = mmod(c[1], modC);

  ll all = f[1];
  ll allc = (ll)c[1] * f[1];
  for (int i = 2; i <= n; i++)
  {
    f[i] = mmod((ll)f[i - 1] * a + b, modF);
    c[i] = mmod((ll)c[i - 1] * a + b, modC);
    all += f[i];
    allc += (ll)c[i] * f[i];
  }
  if (all <= F)
  {
    printf("%I64d\n", allc);
    return 0;
  }

  for (int i = 1; i <= n; i++)
  {
    L[i] = c[i] >> 16;
    R[i] = c[i] - (L[i] << 16);
  }
  vi p;
  vi was(1 << 16, 0);
  for (int i = 1; i <= n; i++)
  {
    ids[L[i]].pb(i);
    was[L[i]]++;
  }
  vi Ls;
  for (int i = 0; i < (1 << 16); i++)
    for (int j = 0; j < was[i]; j++)
      Ls.pb(i);             
  vvi w(1 << 16, vi());
  for (int it = 0; it < sz(Ls); it++)
  {
    for (int j = 0; j < (1 << 16); j++)
      w[j].clear();
    int i = Ls[it];
    for (int j = 0; j < sz(ids[i]); j++)
      w[R[ids[i][j]]].pb(ids[i][j]);
    vi Rs;                    
    for (int j = 0; j < (1 << 16); j++)
      for (int k = 0; k < sz(w[j]); k++)
        Rs.pb(w[j][k]);
    sort(all(Rs), Less);
    for (int j = 0; j < sz(Rs); j++)
      p.pb(Rs[j]);
  }
  ll nowf = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++)
    if (nowf + f[p[i]] <= F)
      nowf += f[p[i]], ans += (ll)c[p[i]] * f[p[i]];
    else
    {
      ans += (ll)c[p[i]] * (F - nowf);
      break;
    }
  printf("%I64d\n", ans);
  return 0;
}

