#define TASKNAME "g"
 
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
  #define LLD "%I64d"
#else
  #define LLD "%lld"
#endif
  
using namespace std;
  
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <bool> vb;
typedef vector <vb> vvb;
typedef vector <ll> vll;
typedef vector <vll> vvll; 
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <int, ll> pil;
typedef vector <pii> vpii;
 
int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int n;
  scanf("%d", &n);
  vi a(n), b(n), d(n);
  for (int i = 0; i < n; i++)
    scanf("%d%d", &a[i], &b[i]), d[i] = a[i] - b[i];
  map <int, int> cnt;
  int s = 0;
  for (int i = 0; i < n; i++)
  {
    s += d[i];
    ++cnt[s];
  }               
  int ans = n - 1;
  for (map <int, int>::iterator it = cnt.begin(); it != cnt.end(); it++)
    ans = min(ans, n - it->snd);
  printf("%d\n", ans);
  return 0;
}