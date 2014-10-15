#define TASKNAME "c"

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

const int maxn = 5e7 + 10;

int a[maxn];

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  a[1] = 1;
  a[2] = 2;
  int idx = 2;
  int cnt = 1;
  int num = 2;
  for (int i = 3; i <= maxn; i++)
  {
    if (cnt)
      a[i] = num, --cnt;
    else
    {
      ++idx;
      cnt = a[idx];
      ++num;
      a[i] = num;
      --cnt;
    }
    //printf("%d%c", a[i], " \n"[i == maxn]);
  }
  ll n;
  scanf("%I64d", &n);
  ll now_num = 1;
  num = 1;
  ll pos = 0;
  for (int i = 1; i <= maxn; i++)
  {
    if (pos + (ll)a[i] * num >= n) 
    {
      ll dif = n - pos;
      ll x = (dif + num - 1) / num;
      printf("%I64d\n", now_num + x - 1);
      //eprintf("%.5lf\n", double(clock()) / CLOCKS_PER_SEC);
      return 0;
    }
    pos += (ll)a[i] * num;
    now_num += a[i];
    num++;
  }
  return 0;
}
