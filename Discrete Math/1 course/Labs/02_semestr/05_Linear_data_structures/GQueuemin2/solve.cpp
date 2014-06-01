#define TASKNAME "queuemin2"
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
#define INFLONG ((long long)(1e18))
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
typedef unsigned long long ull;
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
 
const int INF = 2147483647;
const int maxk = 1010;
const ll M = (1ll << 32) - 1;
const ll mod = (1ll << 32);

int n, m, k;
ll a, b, c;
int x[maxk];
vi A;
int minA = INF;
vi minB;
int sizeA, sizeB;
 
inline void pushA(int x)
{
  A[sizeA++] = x;
  minA = min(minA, x);
}
 
inline void pushB(int x)
{
  int prev = !sizeB ? INF : minB[sizeB - 1];
  minB[sizeB++] = min(prev, x);
}
 
inline int popA()
{
  return A[--sizeA];
}
 
inline void popB()
{
  if (!sizeB)
  {
    while (sizeA)
    {
      int x = popA();
      pushB(x);
    }
    minA = INF;
  }
  
  --sizeB;
}
 
inline int getMin()
{
  return min(minA, (!sizeB ? INF : minB[sizeB - 1]));
}
 
inline ll mmod(ll x)
{
  return x < 0 ? x + mod : x;
}     
 
inline int f(ll x)
{
  ll carry = (x % mod + mod) % mod;
  if (carry <= INF)
    return carry;
  return carry - mod;
}
 
int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d%d%d", &n, &m, &k);
  scanf("%I64d%I64d%I64d", &a, &b, &c);
  A.resize(m + 10);
  minB.resize(m + 10);
 
  for (int i = 0; i < k; i++)
    scanf("%d", &x[i]);
 
  ll ans = 0;
  int start = -1;
 
  ll ppv = -1, pv = -1;
  if (k < m)
  {
    start = m;
    for (int i = 0; i < k; i++)
      pushA(x[i]);
    ll ppx = x[k - 2];
    ll px = x[k - 1];
    for (int i = k; i < m; i++)
    {
      ll value = f(a * ppx + b * px + c);
      pushA(value);
      ppx = px;
      px = value;
    }
    ppv = ppx;
    pv = px;
    ans += getMin();
  }
  else
  {
    start = k;
    for (int i = 0; i < m; i++)
      pushA(x[i]);
    ans += getMin();
    for (int i = m; i < k; i++)
    {
      popB();
      pushA(x[i]);
      ans += getMin();
    }
    ppv = x[k - 2];
    pv = x[k - 1];
  }
 
  for (int i = start; i < n; i++)
  {
    ll value = f(a * ppv + b * pv + c);
    popB();
    pushA(value);
    ppv = pv;
    pv = value;
    ans += getMin();
  }
 
  printf("%I64d\n", ans);
  //eprintf("%.5lf\n", double(clock()) / CLOCKS_PER_SEC);
  return 0;
}
