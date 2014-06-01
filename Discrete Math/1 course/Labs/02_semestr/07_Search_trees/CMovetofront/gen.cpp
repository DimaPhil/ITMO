#include <cstdio>
#include <ctime>
#include <algorithm>

using namespace std;

typedef long long ll;

ll rdtsc() {
  ll tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}

int main() {
  freopen("movetofront.in", "w", stdout);
  srand(rdtsc());

  int n = rand() % 100000 + 1;
  int m = rand() % 100000 + 1;
  printf("%d %d\n", n, m);
  for (int i = 0; i < m; i++) {
    int l = rand() % n + 1;
    int r = rand() % n + 1;
    if (l > r)
      swap(l, r);
    printf("%d %d\n", l, r);
  }
}