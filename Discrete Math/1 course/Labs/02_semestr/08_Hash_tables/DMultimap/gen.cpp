#include <cstdio>
#include <ctime>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main() {
  srand(time(NULL));
  freopen("multimap.in", "w", stdout);
  int n = rand() % 10;
  map <int, vector <int> > m;
  for (int i = 0; i < n; i++) {
    int t = rand() % 3;
    if ((t == 1 || t == 2) && m.size() == 0)
      t = 0;
    if (t == 0) {
      int x = rand() % 100;
      int y = rand() % 5;
      m[y].push_back(x);
      printf("put %c %d\n", 'a' + y, x);
    }
    if (t == 1) {
      printf("delete ");
      int x = rand() % (int)m.size();
      map <int, vector <int> > ::iterator IT = m.begin();
      for (int xx = 0; xx < x; xx++)
        ++IT;
      vector <int> a = IT->second;
      int it = a[rand() % (int)a.size()];
      printf("%c %d\n", IT->first + 'a', it);
    }
    if (t == 2) {
      int x = rand() % (int)m.size();
      map <int, vector <int> > ::iterator IT = m.begin();
      for (int xx = 0; xx < x; xx++)
        ++IT;
      printf("deleteall %c\n", IT->first + 'a');
    }
    int x = rand() % (int)m.size();
    map <int, vector <int> > ::iterator IT = m.begin();
    for (int xx = 0; xx < x; xx++)
      ++IT;
    printf("get %c\n", IT->first + 'a');
  }
  return 0;
}                         