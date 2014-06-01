#include <cstdio>
#include <algorithm>

using namespace std;

long long rdtsc() {
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}

const int maxr = 10000;
const int maxn = 200000;

int main() {
  srand(rdtsc());
  freopen("crypto.in", "w", stdout);
  //int r = rand() % maxr + 1;
  //int n = rand() % maxn + 1;
  //int m = rand() % maxn + 1;
  int r = maxr;
  int n = maxn;
  int m = maxn;
  printf("%d %d %d\n", r, n, m);
  for (int i = 0; i < n; i++, printf("\n")) {
    for (int j = 0; j < 2; j++, printf("\n"))
      for (int k = 0; k < 2; k++) {
        printf("%d ", rand());
      }
  }
  for (int i = 0; i < m; i++) {
    int l = rand() % n + 1;
    int r = rand() % n + 1;
    if (l > r)
      swap(l, r);
    printf("%d %d\n", l, r);
  }
}