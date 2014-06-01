#include <cstdio>
#include <set>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
  freopen("bstsimple.in", "r", stdin);
  freopen("stress.out", "w", stdout);
  set <int> s;
  char str[20];
  int x;
  while (scanf("%s%d", str, &x) >= 1) {
    if (!strcmp(str, "insert"))
      s.insert(x);
    if (!strcmp(str, "delete"))
      s.erase(x);
    if (!strcmp(str, "exists"))
      printf("%s\n", s.find(x) != s.end() ? "true" : "false");
    if (!strcmp(str, "next")) {
      set <int>::iterator it = s.upper_bound(x);
      if (it == s.end())
        printf("none\n");
      else
        printf("%d\n", *it);
    }
    if (!strcmp(str, "prev")) {
      set <int>::iterator it = s.upper_bound(x);
      if (it == s.begin()) {
        printf("none\n");
      } else {
        --it;
        printf("%d\n", *it);
      }
    }
  }
  return 0;
}