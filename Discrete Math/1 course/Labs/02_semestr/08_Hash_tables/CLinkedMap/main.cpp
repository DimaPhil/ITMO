#define TASKNAME "linkedmap" 
 
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

struct element;
typedef element *pelement;

struct element
{
  static pelement Null;
  pelement next, prev;
  string value;

  element() : next(this), prev(this) {}
  element(string value) : next(Null), prev(Null), value(value) {}
};

pelement element::Null = new element();

pelement tail = element::Null;

inline void eraseElement(pelement &e) {
  if (e == tail) {
    e->prev->next = element::Null;
    tail = e->prev;
    e = element::Null;
  } 
  pelement tmp = e->prev;
  if (e->prev != element::Null)
    e->prev->next = e->next;
  if (e->next != element::Null)
    e->next->prev = tmp;
  e = element::Null;
}

struct HashTable {
  ll value;
  string name;
  pelement link;

  HashTable() {value = 0, name = "", link = element::Null;}
  HashTable(ll value, const string &name, pelement link) : value(value), name(name), link(link) {}
};
 
HashTable table[maxn];
 
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
  while (table[i].value != maxn + 1 && table[i].value != x)
    if (++i == maxn)
      i = 0;
  return i;
} 
 
inline void insertElement(ll x, const string &s) {
  int i = getPos(x);
  if (table[i].value != maxn + 1) {
    table[i].value = x;
    table[i].name = s;
    table[i].link->value = s;
    return;
  }
  pelement last = new element(s);
  tail->next = last;
  last->prev = tail;
  tail = last;

  table[i] = HashTable(x, s, tail);
}
 
inline void deleteElement(ll x) {
  int i = getPos(x);
  if (table[i].value == maxn + 1)
    return;
  eraseElement(table[i].link);
  table[i] = HashTable(maxn + 1, "", element::Null);
}
 
inline string getElement(ll x) {
  int i = getPos(x);
  if (table[i].value == maxn + 1)
    return "none";
  return table[i].name;
}

inline string prevElement(ll x) {
  int i = getPos(x);
  if (table[i].value == maxn + 1)
    return "none";
  pelement e = table[i].link;
  if (e->prev == element::Null)
    return "none";
  return e->prev->value; 
}

inline string nextElement(ll x) {
  int i = getPos(x);
  if (table[i].value == maxn + 1)
    return "none";
  pelement e = table[i].link;
  if (e->next == element::Null)
    return "none";
  return e->next->value; 
}
 
int main() {
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  char s[10];
  string x, y;
  for (int i = 0; i < maxn; i++)
    table[i] = HashTable(maxn + 1, "", element::Null);
  while (scanf("%s", s) >= 1) {
    if (s[0] == 'p' && s[1] == 'u') {
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
    if (s[0] == 'p' && s[1] == 'r') {
      cin >> x;
      printf("%s\n", prevElement(hash(x)).c_str());
    }
    if (s[0] == 'n') {
      cin >> x;
      printf("%s\n", nextElement(hash(x)).c_str());
    }
  }
  return 0;
}       