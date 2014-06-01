#include <cstdio>
#include <ctime>
#include <algorithm>

using namespace std;

int main()
{
  srand(time(NULL));
  freopen("num2perm.in", "w", stdout);
  int n = 4;
  long long maxk = 1;
  for (int i = 1; i <= n; i++)
    maxk *= i;
  long long k = ((long long)rand() * rand()) % maxk;
  printf("%d %I64d\n", n, k);
}