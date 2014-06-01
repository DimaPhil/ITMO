#define TASKNAME "multimap"
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

const int p = 41;
const int size = 512;
const int maxlen = 100;

struct HashTable {
  string kx, ky;

  HashTable() {kx = ky = "";}
  HashTable(string &kx, string &ky) : kx(kx), ky(ky) {}
};

int hash(string &s) {
  int hash = 0;
  for (int i = 0; i < sz(s); i++)
    hash = (hash * p + s[i]) & (size - 1);
  return hash;
}

vector <HashTable> table[size][size];

int getPos(string &a, string &b) {
  int pa = hash(a);
  int pb = hash(b);
  for (int i = 0; i < sz(table[pa][pb]); i++)
    if (table[pa][pb][i].kx == a && table[pa][pb][i].ky == b)
      return i;
  return -1;
}

char type[maxlen], x[maxlen], y[maxlen];
string X, Y;

void deleteAll(string &x) {
  int px = hash(x);
  for (int i = 0; i < size; i++) {
    int Sz = sz(table[px][i]);
    for (int j = 0; j < Sz; j++) {
      if (table[px][i][j].kx == x) {
        swap(table[px][i][j].kx, table[px][i][Sz - 1].kx);
        swap(table[px][i][j].ky, table[px][i][Sz - 1].ky);
        table[px][i].pop_back();
        --j;
        --Sz;
      }
    }
  }
}

void deleteEl(string &x, string &y) {
  int px = hash(x);
  int py = hash(y);
  int pos = getPos(x, y);
  if (pos == -1)
    return;
  int Sz = sz(table[px][py]);
  swap(table[px][py][pos].kx, table[px][py][Sz - 1].kx);
  swap(table[px][py][pos].ky, table[px][py][Sz - 1].ky);
  table[px][py].pop_back();
}

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  while (scanf("%s", type) >= 1) {
    if (type[0] == 'p') {
      scanf("%s%s", x, y);
      X = x, Y = y;
      int pos = getPos(X, Y);
      int px = hash(X);
      int py = hash(Y);
      if (pos == -1)
        table[px][py].pb(HashTable(X, Y));
      else
        table[px][py][pos].ky = Y;
    }
    else
    if (type[0] == 'd' && type[6] == 'a') {
      scanf("%s", x);
      X = x;
      deleteAll(X);
    }
    else
    if (type[0] == 'd') {
      scanf("%s%s", x, y);
      X = x, Y = y;
      deleteEl(X, Y);
    }
    else
    if (type[0] == 'g') {
      scanf("%s", x);
      X = x;
      vector <string> ans;
      int px = hash(X);
      for (int i = 0; i < size; i++)
        for (int j = 0; j < sz(table[px][i]); j++)
          if (table[px][i][j].kx == X)
            ans.pb(table[px][i][j].ky);
      if (!sz(ans)) {
        printf("0\n");
        continue;
      }
      printf("%d ", sz(ans));
      for (int i = 0; i < sz(ans); i++)
        printf("%s%c", ans[i].c_str(), " \n"[i == sz(ans) - 1]);
    }
  }                 
  return 0;
}

