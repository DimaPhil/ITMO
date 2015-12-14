#include <bits/stdc++.h>

int send_query(const std::string &query) {
  std::cout << query << '\n';
  fflush(stdout);
  int answer;
  scanf("%d", &answer);
  if (answer == (int)query.size()) {
    exit(0);
  }
  return answer;
}

int main() {
  int n;
  scanf("%d", &n);
  std::string query;
  for (int i = 0; i < n; i++) {
    query += '1';
  }
  int ones = send_query(query);
  int zeros = n - ones;
  std::string ans;
  for (int i = 0; i < n; i++) {
    std::string query;
    for (int j = 0; j < n; j++) {
      query += (j == i ? '1' : '0');
    }
    int equal = send_query(query);
    if (equal == zeros + 1) {
      ans += '1';
    } else {
      ans += '0';
    }
  }
  send_query(ans);
  return 0;
} 