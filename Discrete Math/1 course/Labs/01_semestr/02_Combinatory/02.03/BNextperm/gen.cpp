#include <cstdio>
#include <ctime>
#include <algorithm>

using namespace std;

int main()
{
  freopen("nextperm.in", "w", stdout);
  srand(time(NULL));
  int maxn = 1e5;
  int n = rand() % maxn + 1;
  printf("%d\n", n);
  int a[n];
  for (int i = 0; i < n; i++)
    a[i] = i + 1;
  random_shuffle(a, a + n);
  for (int i = 0; i < n; i++)
    printf("%d%c", a[i], " \n"[i == n - 1]);             
}