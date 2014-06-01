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

const int maxn = 3e7 + 100;
const int INF = 2147483647;

int n, m, k;
int a, b, c;
int x[maxn];
int sizeA, sizeB;
int minPrefA[maxn], minPrefB[maxn];

inline void pushA(int number)
{
  A[sizeA] = number;
  minPrefA[sizeA] = min(sizeA ? minPrefA[sizeA - 1] : INF, number);
  ++sizeA;
}

inline void pushB(int number)
{
  B[sizeb] = number;
  minPrefB[sizeB] = min(sizeB ? minPrefB[sizeB - 1] : INF, number);
  ++sizeB;
}

inline int popA()
{
  minPrefA[sizeA - 1] = INF;
  --sizeA;
}

inline void popB()
{
  if (!sizeB)
  {
    while (sizeA)
    {
      int x = popA();
      pushB(x);
    }
  }

  minPref[sizeB - 1] = INF;
  --sizeB;
}

inline int getMinA()
{
  return !sizeA ? INF : A[sizeA - 1];
}

inline int getMinB()
{
  return !sizeB ? INF : B[sizeB - 1];
}

inline int getMin()
{
  return min(getMinA(), getMinB());
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  scanf("%d%d%d", &n, &m, &k);
  scanf("%d%d%d", &a, &b, &c);
  for (int i = 0; i < k; i++)
    scanf("%d", &x[i]);

  return 0;
}

