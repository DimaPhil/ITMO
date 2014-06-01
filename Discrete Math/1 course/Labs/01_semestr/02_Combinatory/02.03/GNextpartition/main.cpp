
#define TASKNAME "nextpartition"
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
 
const int maxn = 3e5 + 100;
 
int n;
vi a;
char s[maxn];
 
int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  gets(s);
  int len = strlen(s);
  s[len++] = '+';
  n = 0;
  int i = 0;
  while (s[i] != '=')
    n *= 10, n += s[i] - '0', ++i;
  ++i;
  int now = 0;
  for (int j = i; j < len; j++)
  {
    if (isdigit(s[j]))
      now *= 10, now += s[j] - '0';
    else
      a.pb(now), now = 0;
  }
 
  if (sz(a) == 1)
  {
    puts("No solution");
    return 0;
  }
 
  int L = sz(a);
  for (int i = L - 1; i >= 1; i--)
  {
    if (a[i] >= a[i - 1] + 2)
    {
      int s = a[i] - 1;
      ++a[i - 1];
      a.pop_back();
      while (s >= 2 * a[i - 1])
        a.pb(a[i - 1]), s -= a[i - 1];
      a.pb(s);
      printf("%d=", n);
      for (int i = 0; i < sz(a); i++)
        printf("%d%c", a[i], "+\n"[i == sz(a) - 1]);
      return 0;
    }
    else
    {
      a[i - 1] += a[i];
      printf("%d=", n);
      for (int i = 0; i < sz(a) - 1; i++)
        printf("%d%c", a[i], "+\n"[i == sz(a) - 2]);
      return 0;
    }
  }
  return 0;
}
