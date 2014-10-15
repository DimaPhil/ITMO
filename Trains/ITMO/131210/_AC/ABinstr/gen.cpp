#include <cstdio>
#include <cstring>

int main()
{
  for (int n = 1; n <= 10; n++)
  {
    printf("%d: ", n);
    int ans = 0;
    for (int msk = 0; msk < (1 << n); msk++)
    {
      char s[20];
      for (int i = 0; i < n; i++)
        s[i] = (msk & (1 << i)) > 0;
      bool f = 1;
      for (int i = 0; i < n - 1; i++)
      {
        bool ok = 1;
        int p1 = 0, p2 = n - i - 1;
        while (p1 <= i)
        {
          if (s[p1] != s[p2])
            ok = 0;
          ++p1, ++p2;
        }
        if (ok)
        {
          f = 0;
          break;
        }  
      }
      if (f)
        ++ans;
    }
    printf("%d\n", ans);
  }
}