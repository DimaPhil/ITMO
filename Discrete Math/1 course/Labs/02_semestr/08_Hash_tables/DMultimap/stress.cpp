#define TASKNAME "multimap" 
 
#include <cstdio>
#include <string>
#include <set>
#include <iostream>
#include <vector>
#include <map>
#include <cassert>
 
#define pb push_back
#define sz(a) (int)a.size()
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
 
using namespace std;
 
typedef long long ll;
 
int main() {
  freopen(TASKNAME".in", "r", stdin);
  freopen("stress.out", "w", stdout);
  char s[20];
  string x, y;
  map <string, set <string> > m;
  while (scanf("%s", s) >= 1) {
    if (s[0] == 'p') {
      cin >> x >> y;
      m[x].insert(y);
    }
    if (s[0] == 'd') {
      if (s[6] == 'a') {
        cin >> x;
        m[x].clear();
      } else {
        cin >> x >> y;
        m[x].erase(y);
      }
    }
    if (s[0] == 'g') {
      cin >> x;
      if (!sz(m[x])) {
        printf("0\n");
        continue;
      }
      printf("%d ", sz(m[x]));
      int cnt = 0;
      for (set<string>::iterator it = m[x].begin(); it != m[x].end(); it++, cnt++)
        printf("%s%c", (*it).c_str(), " \n"[cnt == sz(m[x]) - 1]);
    }                                                       
  }
  return 0;
}       