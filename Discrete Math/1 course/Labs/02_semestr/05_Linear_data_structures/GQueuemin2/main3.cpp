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
  inline element(int value) : next(Null), value(value), minPref(INF) {}
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

pelement tmp;

inline int popA()
{
  int ans = topA->value;
  tmp = topA->next;
  delete topA;
  topA = tmp;
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
  tmp = topB->next;
  delete topB;
  topB = tmp;
  return ans;
}

inline int getMin()
{
  int A = (topA == element::Null ? INF : topA->minPref);
  int B = (topB == element::Null ? INF : topB->minPref);
  return min(A, B);
}

int n, m, k;
ll a, b, c;
int x[maxk];

inline ll mmod(ll x)
{
  return x < 0 ? x + mod : x;
}     

inline int f(ll x)
{
  if (x < 0)
    x += (1ll << 62), x += (1ll << 62);
  ll carry = x & M;
  return carry <= INF ? carry : carry - mod;
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen("stress.out", "w", stdout);
  scanf("%d%d%d", &n, &m, &k);
  scanf("%I64d%I64d%I64d", &a, &b, &c);
  topA = topB = element::Null;

  for (int i = 0; i < k; i++)
    scanf("%d", &x[i]);

  ll ans = 0;
  int start = -1;

  int ppv = -1, pv = -1;
  if (k < m)
  {
    start = m;
    for (int i = 0; i < k; i++)
      pushA(x[i]);
    int ppx = x[k - 2];
    int px = x[k - 1];
    for (int i = k; i < m; i++)
    {
      int value = f(a * ppx + b * px + c);
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
    int value = f(a * ppv + b * pv + c);
    popB();
    pushA(value);
    ppv = pv;
    pv = value;
    ans += getMin();
  }

  printf("%I64d\n", ans);
  eprintf("%.5lf\n", double(clock()) / CLOCKS_PER_SEC);
  return 0;
}

