#define TASKNAME "priorityqueue"
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

const int maxn = 4e6 + 10;

int n;
int a[maxn];
int qs[maxn];
int pos[maxn];
int xx[maxn];
           
inline bool isGoodLeft(int v) {
  return (v << 1) > n || a[v] <= a[v << 1];
}

inline bool isGoodRight(int v) {
  return (v << 1) + 1 > n || a[v] <= a[(v << 1) + 1];
}

inline bool isGood(int v) {
  return isGoodLeft(v) && isGoodRight(v);
}

inline void siftUp(int v) {
  if (v > 1 && !isGood(v >> 1)) {
    swap(a[v], a[v >> 1]);
    pos[qs[v]] = v >> 1;
    pos[qs[v >> 1]] = v;
    swap(qs[v], qs[v >> 1]);
    siftUp(v >> 1);
  }
}

inline void siftDown(int v) {
  if (!isGood(v)) {
    int value = a[v << 1];
    if ((v << 1) + 1 <= n)
      value = min(value, a[(v << 1) + 1]);
    if (value == a[v << 1]) {
      swap(a[v << 1], a[v]);
      pos[qs[v << 1]] = v;
      pos[qs[v]] = v << 1;
      swap(qs[v << 1], qs[v]);
      siftDown(v << 1);
    }
    else {
      swap(a[(v << 1) + 1], a[v]);
      pos[qs[(v << 1) + 1]] = v;
      pos[qs[v]] = (v << 1) + 1;
      swap(qs[(v << 1) + 1], qs[v]);
      siftDown((v << 1) + 1);
    }
  }
}

inline void printQueue(int v) {
  printf("%d - %d %d %d\n", v, a[v], qs[v], pos[qs[v]]);
  if ((v << 1) <= n)
    printQueue(v << 1);
  if ((v << 1) + 1 <= n)
    printQueue((v << 1) + 1);
}

inline void push(int x) {
  ++n;
  a[n] = x;
  siftUp(n);
}

inline int extractMin() {
  int ans = a[1];
  swap(a[1], a[n]);
  pos[qs[1]] = n;
  pos[qs[n]] = 1;
  swap(qs[1], qs[n]);
  --n;
  if (n)
    siftDown(1);
  return ans;
}

char s[20];

int main() {
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  n = 0;
  int q = 0;
  while (scanf("%s", s) >= 1) {
    ++q;
    if (s[0] == 'p') {
      scanf("%d", &xx[q]);
      qs[n + 1] = q;
      pos[q] = n + 1;
      push(xx[q]);
    }
    if (s[0] == 'e') {
      if (!n)
        puts("*");
      else
        printf("%d\n", extractMin());
    }
    if (s[0] == 'd') {
      int y;
      scanf("%d%d", &xx[q], &y);
      int v = pos[xx[q]];
      if (a[v] >= y) {
        a[v] = y;
        siftUp(v);
      } else {
        a[v] = y;
        siftDown(v);
      }
    }               
    //printQueue(1);
    //printf("\n");
  }
  return 0;
}

