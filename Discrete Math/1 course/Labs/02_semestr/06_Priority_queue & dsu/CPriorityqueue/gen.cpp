#include <cstdio>
#include <set>
#include <algorithm>
#include <vector>
#include <ctime>
#include <map>
#include <iostream>

using namespace std;

const int maxq = 20;

long long rdtsc() {
    long long tmp;
    asm("rdtsc" : "=A"(tmp));
    return tmp;
}

inline int myrand() {
	return abs((rand() << 15) ^ rand());
}

int main() {
  freopen("priorityqueue.in", "w", stdout);
  srand(rdtsc());

  int n = myrand() % maxq + 1;
  map <int, bool> have;
  vector <int> num(n + 10);
  set <int> qs;
  set <int> nums;
  map <int, int> get;

  for (int i = 0; i < n; i++) {
    int type = myrand() % 3;
    while (type == 1 && !nums.size())
      type = myrand() % 3;
    if (!type) {
      int value = myrand();
      //while (have[value])
      //  value = myrand();
      //have[value] = 1;
      printf("push %d\n", value);
      num[i + 1] = value;
      qs.insert(i + 1);
      get[value] = i + 1;
      nums.insert(value);
    }

    if (type == 1) {
      int index = myrand() % (int)qs.size();
      set <int>::iterator iter = qs.begin();
      for (int it = 0; it < index; it++)
        iter++;
      int QS = *iter;

      //have.erase(num[QS]);
      int GET = get[num[QS]];
      get.erase(num[QS]);
      nums.erase(num[QS]);
      int value = myrand();
      while (have[value])
        value = myrand();
      //have[value] = 1;
      //num[QS] = value;
      nums.insert(value);
      get[value] = GET;
      printf("decrease-key %d %d\n", QS, value);
    }

    if (type == 2) {
      printf("extract-min\n");
      if (nums.size() == 0)
        continue;
      int x = *nums.begin();
      nums.erase(nums.begin());
      //have.erase(x);
      qs.erase(get[x]);
      get.erase(x);
    }
  }
  return 0;
}