#include <cstdio>
#include <ctime>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 10;
const int maxk = 1000;

long long rdtsc()
{
  long long tmp;
  asm("rdtsc" : "=A"(tmp));
  return tmp;
}

inline int genRand()
{
  if (rand() & 1)
    return rand();
  return -rand();
}

int main()
{
  freopen("queuemin2.in", "w", stdout);
  srand(rdtsc());

  int n = maxn;
  int m = rand() % maxn + 1;
  int k = rand() % maxk + 1;
  if (k < 2)
    k = 2;

  printf("%d %d %d\n", n, m, k);
  int a = genRand();
  int b = genRand();
  int c = genRand();
  printf("%d %d %d\n", a, b, c);

  for (int i = 0; i < k; i++)
    printf("%d%c", genRand(), " \n"[i == k - 1]);
}