#define TASKNAME "set" 
 
#include <cstdio>
 
const int maxn = 1e7;
 
int table[maxn];
 
inline int getPos(int x) {
  int i = (x % maxn + maxn) % maxn;
  while (table[i] != maxn + 1 && table[i] != x)
    if (++i == maxn)
      i = 0;
  return i;
} 
 
inline void insertElement(int x) {
  table[getPos(x)] = x;
}
 
inline void deleteElement(int x) {
  table[getPos(x)] = maxn + 1;
}
 
inline bool existsElement(int x) {
  return table[getPos(x)] != maxn + 1;
}
 
int main() {
  freopen(TASKNAME".in", "r", stdin);
  freopen(TASKNAME".out", "w", stdout);
  char s[10];
  int x;
  for (int i = 0; i < maxn; i++)
    table[i] = maxn + 1;
  while (scanf("%s%d", s, &x) >= 1) {
    if (s[0] == 'i')
      insertElement(x);
    if (s[0] == 'd')
      deleteElement(x);
    if (s[0] == 'e')
      printf("%s\n", existsElement(x) ? "true" : "false");
  }
} 