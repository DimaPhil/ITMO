#define TASKNAME "quack"
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
#define INFLONG ((long long)(1e18))
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

const int maxn = 1e5 + 100;
const int maxlen = 50;
const ll p = 239017;
const ll mod = 1e9 + 7;
const int M = (1 << 16) - 1;
const int maxq = 1e6 + 10;

char commands[maxn][maxlen];
char s[maxlen];
int len[maxn];
int size;
map <ll, int> go;
int reg[30];
int start = 0, end = 0;
int q[maxq];

inline ll mmod(ll x)
{
  return (x % mod + mod) % mod;
}

inline void put(int x)
{
  x &= M;
  q[end++] = x;
  if (end == maxq)
    end = 0;
}

inline int get()
{
  int ans = q[start++];
  if (start == maxq)
    start = 0;
  return ans;
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  size = 0;
  while (gets(s))
  {
    len[size] = strlen(s);
    for (int j = 0; j < len[size]; j++)
      commands[size][j] = s[j];
    if (s[0] == ':')
    {
      ll hash = 0;
      for (int j = 1; j < len[size]; j++)
        hash = mmod(hash * p + s[j]);
      go[hash] = size;
    }  
    ++size;
  }

  int now = 0;
  while (now < size)
  {
    char c = commands[now][0];
    char r;
    if (c == 'Q')
      return 0;
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
    {
      int x = get();
      int y = get();
      if (c == '+')
        put(x + y);
      if (c == '-')
        put(x - y);
      if (c == '*')
      {
        ll value = 1ll * x * y;
        value &= ((1ll << 16) - 1);
        put(value);
      }
      if (c == '/')
      {
        if (!y)
          put(0);
        else
          put(x / y);
      }
      if (c == '%')
      {
        if (!y)
          put(0);
        else
          put(x % y);
      }
    }
    if (c == '>')
    {
      int x = get();
      r = commands[now][1];
      reg[r - 'a'] = x;
    }
    if (c == '<')
    {
      r = commands[now][1];
      int x = reg[r - 'a'];
      put(x);        
    }
    if (c == 'P')
    {
      if (len[now] == 1)
      {
        int x = get();
        printf("%d\n", x);
      }
      else
      {
        r = commands[now][1];
        printf("%d\n", reg[r - 'a']);
      }
    }
    if (c == 'C')
    {
      if (len[now] == 1)
      {
        int x = get();
        printf("%c", char(x & 255));
      }
      else
      {
        r = commands[now][1];
        printf("%c", char(reg[r - 'a'] & 255));
      }
    }
    if (c == 'J')
    {
      ll hash = 0;
      for (int j = 1; j < len[now]; j++)
        hash = mmod(hash * p + commands[now][j]);
      now = go[hash];
    }
    if (c == 'Z')
    {
      r = commands[now][1];
      ll hash = 0;
      for (int j = 2; j < len[now]; j++)
        hash = mmod(hash * p + commands[now][j]);
      if (!reg[r - 'a'])
        now = go[hash];
    }
    if (c == 'E')
    {
      char r1 = commands[now][1];
      char r2 = commands[now][2];
      ll hash = 0;
      for (int j = 3; j < len[now]; j++)
        hash = mmod(hash * p + commands[now][j]);
      if (reg[r1 - 'a'] == reg[r2 - 'a'])
        now = go[hash];
    }
    if (c == 'G')
    {
      char r1 = commands[now][1];
      char r2 = commands[now][2];
      ll hash = 0;
      for (int j = 3; j < len[now]; j++)
        hash = mmod(hash * p + commands[now][j]);
      if (reg[r1 - 'a'] > reg[r2 - 'a'])
        now = go[hash];
    }
    if (isdigit(c))
    {
      int x = 0;
      for (int j = 0; j < len[now]; j++)
        x = x * 10 + commands[now][j] - '0';
      put(x);
    }
    ++now;
  }
  return 0;
}

