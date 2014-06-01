#define TASKNAME "parking"
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

int n;
bool empty[maxn];

inline int next(int x) {
  return x + 1 == n ? 0 : x + 1;
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen("stress.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    empty[i] = 1;

  int x;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    --x;
    while (!empty[x])
      x = next(x);
    empty[x] = 0;
    printf("%d%c", x + 1, " \n"[i == n - 1]);
  }
  return 0;
}

