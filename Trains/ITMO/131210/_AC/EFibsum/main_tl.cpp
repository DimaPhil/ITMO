#define TASKNAME "fibsum"
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

const int maxsize = 15;

ll l, r;
int k, mod;

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  int test_cases;
  scanf("%d", &test_cases);
  while (test_cases --> 0)
  {
    scanf("%d", &k);
    vi F;
    F.resize(k);
    for (int i = 0; i < k; i++)
      scanf("%d", &F[i]);
    scanf("%I64d%I64d%d", &l, &r, &mod);
    F.resize(r + 1);
    mod = 10000000;
    for (int i = k; i <= r; i++)
      for (int j = 1; j <= k; j++)
        F[i] += F[i - j];
    int s = 0;
    for (int i = l; i <= r; i++)
      s += F[i];
    printf("%d\n", s);
  }
  return 0;
}


