#include <bits/stdc++.h>

const int alphabet = 26;
const int maxn = 500;
const int maxk = 500000;

int go[maxn][2];
char cs[maxn];
char need[maxk + 1];
std::vector<int> goRev[maxn];

int main() {
  freopen("start.in", "r", stdin);
  freopen("start.out", "w", stdout);
  int k, n;
  scanf("%d%d", &k, &n);
  for (int i = 0; i < n; i++) {
    int from, to;
    char c;
    scanf("%d%d %c", &from, &to, &c);
    --from;
    --to;
    go[i][0] = from;
    go[i][1] = to;
    goRev[from].push_back(i);
    goRev[to].push_back(i);
    cs[i] = c;
  }
  scanf("%s", need);
  std::vector<bool> used(n, true);
  for (int i = k - 1; i >= 0; i--) {
    std::vector<bool> newUsed(n, false);
    for (int j = 0; j < n; j++) {
      if (!used[j] || cs[j] != need[i]) {
        continue;
      }
      for (size_t it = 0; it < goRev[j].size(); it++) {
        newUsed[goRev[j][it]] = true;
      }
    }
    used = newUsed;
  }
  std::vector<int> answer;
  for (int i = 0; i < n; i++) {
    if (used[i]) {
      answer.push_back(i + 1);
    }
  }
  printf("%d ", (int)answer.size());
  for (size_t i = 0; i < answer.size(); i++) {
    printf("%d%c", answer[i], " \n"[i + 1 == answer.size()]);
  }
  return 0;
}