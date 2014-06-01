#define TASKNAME "map" 
 
#include <cstdio>
#include <string>
#include <iostream>
#include <cassert>
 
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
 
using namespace std;
 
typedef long long ll;
 
const int maxn = 1e6;
const ll p = 239017;
const ll mod = 1e9 + 7;
 
ll table[maxn];
string values[maxn];
 
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
  while (table[i] != maxn + 1 && table[i] != x)
    if (++i == maxn)
      i = 0;
  return i;
} 
 
inline void insertElement(ll x, const string &s) {
  int i = getPos(x);
  table[i] = x;
  values[i] = s;
}
 
inline void deleteElement(ll x) {
  int i = getPos(x);
  table[i] = maxn + 1;
}
 
inline string getElement(ll x) {
  int i = getPos(x);
  if (table[i] == maxn + 1)
    return "none";
  return values[i];
}
 
int main() {
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  char s[10];
  string x, y;
  for (int i = 0; i < maxn; i++)
    table[i] = maxn + 1;
  while (scanf("%s", s) >= 1) {
    if (s[0] == 'p') {
      cin >> x >> y;
      insertElement(hash(x), y);
    }
    if (s[0] == 'd') {
      cin >> x;
      deleteElement(hash(x));
    }
    if (s[0] == 'g') {
      cin >> x;
      printf("%s\n", getElement(hash(x)).c_str());
    }
  }
}       