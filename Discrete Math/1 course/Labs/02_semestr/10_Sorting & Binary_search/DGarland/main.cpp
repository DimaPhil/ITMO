#define TASKNAME "garland"
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

int n;
double a;

double calcB(double m) {
  vector <double> hs(n);
  hs[0] = a;
  hs[1] = m;

  bool ok = 1;
  for (int i = 2; i < n; i++) {
    hs[i] = 2 * hs[i - 1] - hs[i - 2] + 2;
    if (hs[i] < -EPS)
      ok = 0;
  }
  if (!ok)
    return 1e18;
  return hs[n - 1];
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  cin >> n >> a;
  double l = 0, r = 1e9;
  for (int it = 0; it < 100; it++) {
    double m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3;
    if (calcB(m1) < calcB(m2))
      r = m2;
    else
      l = m1;
  }       
  printf("%.2lf\n", calcB((l + r) / 2));
  return 0;
}

