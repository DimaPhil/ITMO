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

struct element;
typedef element *pelement;

struct element
{
  static pelement Null;
  pelement next;
  int value, minPref;

  element() : next(this) {}
  element(int value) : next(Null), value(value), minPref(INF) {}
};

pelement element::Null = new element();

pelement topA, topB;

inline void pushA(int x)
{
  pelement elem = new element(x);
  elem->next = topA;
  if (topA != element::Null)
    elem->minPref = min(x, topA->minPref);
  else
    elem->minPref = x;
  topA = elem;
}

inline void pushB(int x)
{
  pelement elem = new element(x);
  elem->next = topB;
  if (topB != element::Null)
    elem->minPref = min(x, topB->minPref);
  else
    elem->minPref = x;
  topB = elem;
}

inline int popA()
{
  int ans = topA->value;
  topA = topA->next;
  return ans;
}

inline int popB()
{
  if (topB == element::Null)
  {
    while (topA != element::Null)
    {
      int x = popA();
      pushB(x);
    }
  }

  int ans = topB->value;
  topB = topB->next;
  return ans;
}

inline int getMin()
{
  return min(topA->minPref, topB->minPref);
}

int n, m, k;
ll a, b, c;
int x[maxk];

inline ll mmod(ll x)
{
  return x < 0 ? x + mod : x;
}     

inline ll f(ll x)
{
  assert(x >= 0);
  ll carry = x & M;
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
  topA = topB = element::Null;
  a = mmod(a);
  b = mmod(b);
  c = mmod(c);

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
    ll ppx = mmod(x[k - 2]);
    ll px = mmod(x[k - 1]);
    for (int i = k; i < m; i++)
    {
      ll value = f(a * ppx + b * px + c);
      pushA(value);
      ppx = px;
      px = mmod(value);
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
    ppv = mmod(x[k - 2]);
    pv = mmod(x[k - 1]);
  }

  for (int i = start; i < n; i++)
  {
    //assert(ppv >= 0);
    //assert(pv >= 0);
    //assert(a >= 0 && b >= 0 && c >= 0);
    ull X = (ull)a * ppv;
    X &= M;
    ull Y = (ull)b * pv;
    Y &= M;
    X += Y + c;
    X &= M;
    ll value = f(a * ppv + b * pv + c);
    //assert(value >= -INF - 1 && value <= INF);
    popB();
    pushA(value);
    ppv = pv;
    pv = mmod(value);
    ans += getMin();
  }

  printf("%I64d\n", ans);
  return 0;
}

