#include <bits/stdc++.h>

const int maxn = 10;
const int maxlen = 10000;
const int alphabet = 26;
const double EPS = 1e-9;
const int INF = (int)1e9;

int len[maxlen];
int go[maxn][2];
char in[maxlen + 1];
double out[maxlen + 1];
double f[2][maxn][alphabet];

int gauss(std::vector<std::vector<double>> matrix, std::vector<double> &ans) {
    size_t n = matrix.size();
    size_t m = matrix[0].size() - 1;
    vector<int> where(m, -1);
    for (size_t column = 0, row = 0; column < m && row < n; column++) {
        size_t minimal_row = row;
        for (int i = row; i < n; i++) {
            if (std::abs(matrix[i][column]) > std::abs(matrix[sel][column])) {
                minimal_row = i;
            }
        }
        if (std::abs(matrix[minimal_row][column]) < EPS) {
            continue;
        }
        for (size_t i = column; i <= m; i++) {
            std::swap(matrix[sel][i], matrix[row][i]);
        }
        where[column] = row;
        for (size_t i = 0; i < n; i++) {
            if (i != row) {
                double coefficient = matrix[i][column] / matrix[row][column];
                for (size_t j = column; j <= m; j++) {
                    matrix[i][j] -= matrix[row][j] * coefficient;
                }
            }
        }
        row++;
    }
 
    ans.resize(m, 0);
    for (size_t i = 0; i < m; i++) {
        if (where[i] != -1) {
            ans[i] = matrix[where[i]][m] / matrix[where[i]][i];
        }
    }
    for (size_t i = 0; i < n; i++) {
        double sum = 0;
        for (size_t j = 0; j < m; j++) {
            sum += ans[j] * matrix[i][j];
        }
        if (std::abs(sum - matrix[i][m]) > EPS) {
            return 0;
        }
    }
 
    for (int i = 0; i < m; i++) {
        if (where[i] == -1) {
            return INF;
        }
    }
    return 1;
}

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
  std::vector<std::vector<double>> matrix(2 * n, std::vector<double>(2 * n + 1));
  for (int it = 0; it < m; it++) {
    scanf("%d%s", &len[it], in);
    for (int i = 0; i < len; i++) {
        scanf("%f", out[i]);
    }
    int state = 0;
    
  }
  return 0;
}