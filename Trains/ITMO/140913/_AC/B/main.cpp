#define TASKNAME "text"

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

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

const double EPS = 1e-9;
const int INF = 1e9;
const ll INFLONG = (ll)1e18;

const int maxn = 6e5 + 100;

int n;
ll x;
int a[maxn];
ll pref[maxn];

ll get(int l, int r) {
    return !l ? pref[r] : pref[r] - pref[l - 1];
}
        
int main()
{
  #ifdef LocalHost
    freopen(TASKNAME".in", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
  #endif
  while (scanf("%d"LLD, &n, &x) >= 1) {
      for (int i = 0; i < n; i++)
          scanf("%d", &a[i]), a[i + n] = a[i];
      pref[0] = a[0];                      
      for (int i = 1; i < n * 2; i++)
          pref[i] = pref[i - 1] + a[i];
      int l = 0, r = 0;
      multiset <int> numbers;
      ll maxAns = 0;
      int ansL = -1, ansR = -1;
      while (r < n * 2) {
          while (r < n * 2 && get(l, r) <= x) {
              numbers.insert(a[r]);
              int mn = *numbers.begin();
              int mx = *numbers.rbegin();
              if (mx - mn > maxAns)
                  maxAns = mx - mn, ansL = l, ansR = r;
              ++r;
          }
          multiset <int>::iterator it = numbers.find(a[l]);
          if (it != numbers.end())
              numbers.erase(it);
          ++l;
      }
      printf("%d %d\n", ansL + 1, ansR >= n ? ansR - n + 1 : ansR + 1);
  }
  return 0;
}
