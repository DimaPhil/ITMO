#include <cstdio>
#include <ctime>
#include <algorithm>

using namespace std;

int main() {
  freopen("parking.in", "w", stdout);
  srand(time(NULL));
  int n = rand() % 5 + 1;
  printf("%d\n", n);
  for (int i = 0; i < n; i++)  {
    int x = rand() % n + 1;
    printf("%d%c", x, " \n"[i == n - 1]);
  }
}