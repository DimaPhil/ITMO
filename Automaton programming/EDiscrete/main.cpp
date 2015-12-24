#include <bits/stdc++.h>

const int maxn = 10;
const int maxlen = 10000;
const int alphabet = 26;

int len[maxlen];
int go[maxn][2];
char in[maxlen + 1], out[maxlen + 1];
double f[2][maxn][alphabet];

int main() {
  freopen("discrete.in", "r", stdin);
  freopen("discrete.out", "w", stdout);
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    int from, to;
    scanf("%d%d", &from, &to);
    --from;
    --to;
    go[i][0] = from;
    go[i][1] = to;
  }
  for (int it = 0; it < m; it++) {
    scanf("%d%s%s", &len[it], in, out);
    int state = 0;
    double add = 1.0 / len[it];
    for (int i = 0; i < len[it]; i++) {
      int inc = in[i] - '0';
      int outc = out[i] - 'a';
      f[inc][state][outc] += add;
      state = go[state][inc];
    }
  }
  for (int state = 0; state < n; state++) {
    char fc = std::max_element(f[0][state], f[0][state] + alphabet) - f[0][state] + 'a';
    char sc = std::max_element(f[1][state], f[1][state] + alphabet) - f[1][state] + 'a';
    printf("%c %c\n", fc, sc);
  }
  return 0;
}