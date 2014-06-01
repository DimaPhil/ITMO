#include <cstdio>
#include <algorithm>
#include <ctime>

using namespace std;

int main()
{
  srand(time(NULL));
  freopen("bwt.in", "w", stdout);
  for (int i = 0; i < 1000; i++)
    printf("%c", char(rand() % 26 + 'a'));
    //printf("a");
    
}