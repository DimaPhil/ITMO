#include <cstdio>
#include <algorithm>
#include <ctime>
#include <set>

using namespace std;

typedef long long ll;

ll rdtsc() {
  ll tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}

const int maxn = 10;

int getRand() {
  return rand() % 20 - 10;
}

int main() {
  srand(rdtsc());
  freopen("bstsimple.in", "w", stdout);
  int q = maxn;
  set <int> s;
  for (int i = 0; i < q; i++) {
    int type = rand() % 5;
    if (type == 0) {
      int x = getRand();
      s.insert(x);
      printf("insert %d\n", x);
    }
    if (type == 1) {
      if (!s.size()) {
        printf("delete %d\n", getRand());
        continue;
      } 
      int k = rand() % (int)s.size();
      set <int>::iterator it = s.begin();
      for (int I = 0; I < k; I++)
        ++it;
      int x = *it;
      s.erase(x);
      printf("delete %d\n", x);
    }
    if (type == 2)
      printf("exists %d\n", getRand());
    if (type == 3)
      printf("next %d\n", getRand());
    if (type == 4)
      printf("prev %d\n", getRand());
  }
}