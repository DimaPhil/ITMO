#define TASKNAME "multimap" 
 
#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>
 
#define pb push_back
#define sz(a) (int)a.size()
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
 
using namespace std;
 
typedef long long ll;
 
const int maxn = 1e6;
const ll p = 239017;
const ll mod = 1e9 + 7;

struct HashTable {
  ll value;
  string name;

  HashTable() {value = 0, name = "";}
  HashTable(ll value, const string &name) : value(value), name(name) {}
};
 
ll tableX[maxn];
vector <HashTable> tableY[maxn];
int inY[maxn];
 
inline ll mmod(ll x) {
  return (x % mod + mod) % mod;
}
 
inline ll hash(const string &s) {
  ll hash = 0;
  for (int i = 0; i < (int)s.size(); i++)
    hash = mmod(hash * p + s[i]);
  return hash;
}
 
inline int getPos(ll x) {
  int i = (x % maxn + maxn) % maxn;
  while (tableX[i] != maxn + 1 && tableX[i] != x)
    if (++i == maxn)
      i = 0;
  return i;
}

inline int getPosInside(int i, ll x) {
  int ind = (x % sz(tableY[i]) + sz(tableY[i])) % sz(tableY[i]);
  while (tableY[i][ind].value != maxn + 1 && tableY[i][ind].value != x)
    if (++ind == sz(tableY[i]))
      ind = 0;
  return ind;
} 

inline vector <string> get(ll x) {
  int i = getPos(x);
  vector <string> ans;
  for (int it = 0; it < sz(tableY[i]); it++)
    if (tableY[i][it].value != maxn + 1)
      ans.pb(tableY[i][it].name);
  return ans;
}                                 
 
inline void insertElement(ll x, const string &s) {
  int i = getPos(x);
  tableX[i] = x;
  ll y = hash(s);
  int j = getPosInside(i, y);
  if (tableY[i][j].value == maxn + 1)
    ++inY[i];
  tableY[i][j] = HashTable(y, s);
  if (sz(tableY[i]) < 2 * inY[i]) {
    vector <string> tmp = get(x);
    tableY[i].resize(2 * sz(tableY[i]));
    for (int it = 0; it < sz(tableY[i]); it++)
      tableY[i][it] = HashTable(maxn + 1, "");
    inY[i] = 0;
    for (int it = 0; it < sz(tmp); it++)
      insertElement(x, tmp[it]);
  }
}
 
inline void deleteElement(ll x, ll y) {
  int i = getPos(x);
  if (tableX[i] == maxn + 1)
    return;
  int j = getPosInside(i, y);
  if (tableY[i][j].value == maxn + 1)
    return;
  --inY[i];
  if (!inY[i]) {    
    tableX[i] = maxn + 1;
    tableY[i].resize(1);
    tableY[i][0] = HashTable(maxn + 1, "");
    return;
  }
  tableY[i][j] = HashTable(maxn + 1, "");
}

inline void deleteAll(ll x) {
  int i = getPos(x);
  tableX[i] = maxn + 1;
  tableY[i].resize(1);
  tableY[i][0] = HashTable(maxn + 1, "");
  inY[i] = 0;
}
 
int main() {
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  char s[20];
  string x, y;
  for (int i = 0; i < maxn; i++) {
    tableX[i] = maxn + 1;
    tableY[i].resize(1);
    tableY[i][0] = HashTable(maxn + 1, "");
    inY[i] = 0;
  }
  while (scanf("%s", s) >= 1) {
    if (s[0] == 'p') {
      cin >> x >> y;
      insertElement(hash(x), y);
    }
    if (s[0] == 'd') {
      if (s[6] == 'a') {
        cin >> x;
        deleteAll(hash(x));
      } else {
        cin >> x >> y;
        deleteElement(hash(x), hash(y));
      }
    }
    if (s[0] == 'g') {
      cin >> x;
      vector <string> ans = get(hash(x));
      sort(ans.begin(), ans.end());
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