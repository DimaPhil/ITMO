#define TASKNAME "nextperm"

#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 100;

int n, a[maxn], la[maxn];

int main()
{
  freopen(TASKNAME".in", "r", stdin);
  freopen("stress.out", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]), la[i] = a[i];
  if (!prev_permutation(a, a + n))
  {
    for (int i = 0; i < n; i++)
      printf("0%c", " \n"[i == n - 1]);
  }
  else
  {
    for (int i = 0; i < n; i++)
      printf("%d%c", a[i], " \n"[i == n - 1]);
  }

  for (int i = 0; i < n; i++)
    a[i] = la[i];
  if (!next_permutation(a, a + n))
  {
    for (int i = 0; i < n; i++)
      printf("0%c", " \n"[i == n - 1]);
  }
  else
  {
    for (int i = 0; i < n; i++)
      printf("%d%c", a[i], " \n"[i == n - 1]);
  }
}