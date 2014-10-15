#define TASKNAME "meeting"
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

const int maxn = 4e5 + 10;
const int maxit = 100;

int n;
double a[maxn];

inline double f(double m)
{
  double s = 0;
  for (int i = 0; i < n; i++) 
  {
    s += min(abs(a[i] - m), 360 - a[i] + m);
    //eprintf("+%.5lf\n", min(abs(a[i] - m), 360 - a[i] + m));
    //eprintf("%.5lf\n", s);
  }
  return s;
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%lf", &a[i]);
  double l = 0;
  double r = 360;
  for (int it = 0; it < maxit; it++)
  {
    int m1 = (2 * l + r) / 3;
    int m2 = (l + 2 * r) / 3;
    if (f(m1) <= f(m2))
      r = m2;
    else
      l = m1;
  } 
  printf("%.10lf\n", l);
  return 0;
}

