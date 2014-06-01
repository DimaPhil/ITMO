#define TASKNAME "queue1"
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

int size, elements;
int start, end;
vector <int> q;

inline int next(int x, int n)
{
  if (x + 1 == n)
    return 0;
  return x + 1;
}

inline void doBigger()
{
  vector <int> nq(size);
  int p = 0, cnt = 0;
  for (int i = start; i != end; i = next(i, size))
    nq[p++] = q[i], ++cnt;

  q.resize(size << 1);
  for (int i = 0; i < size; i++)
    q[i] = nq[i];
  start = 0, end = cnt;
  size <<= 1;    
}

inline void doSmaller()
{
  vector <int> nq((size >> 1) + 1);
  int p = 0, cnt = 0;
  for (int i = start; i != end; i = next(i, size))
    nq[p++] = q[i], ++cnt;
  int nsize = max((size >> 1) + 1, 2);
  q.resize(nsize);
  for (int i = 0; i < cnt; i++)
    q[i] = nq[i];
  start = 0, end = cnt;
  size = nsize;
} 

inline void push(int x)
{
  if (next(end, size) == start)
    doBigger();
  ++elements;
  q[end] = x;
  end = next(end, size);
}

inline int pop()
{
  int ans = q[start];
  start = next(start, size);
  --elements;
  if (elements * 2 < size)
    doSmaller();
  return ans;
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  start = 0, end = 0;
  size = 2;
  q.resize(size);
  int n;
  char c;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf(" %c", &c);
    if (c == '+')
    {
      int x;
      scanf("%d", &x);
      push(x);
    }
    else
      printf("%d\n", pop());
  }
  return 0;
}

