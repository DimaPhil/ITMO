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

int gauss(std::vector<std::vector<double>> matrix, std::vector<double>& answer) {
    size_t n = matrix.size();
    size_t m = matrix[0].size() - 1;
    std::vector<int> where(m, -1);
    for (size_t column = 0, row = 0; column < m && row < n; column++) {
        size_t minimal_row = row;
        for (size_t i = row; i < n; i++) {
            if (std::abs(matrix[i][column]) > std::abs(matrix[minimal_row][column])) {
                minimal_row = i;
            }
        }
        if (std::abs(matrix[minimal_row][column]) < EPS) {
            continue;
        }
        for (size_t i = column; i <= m; i++) {
            std::swap(matrix[minimal_row][i], matrix[row][i]);
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
 
    answer.resize(m, 0);
    for (size_t i = 0; i < m; i++) {
        if (where[i] != -1) {
            answer[i] = matrix[where[i]][m] / matrix[where[i]][i];
        }
    }
    for (size_t i = 0; i < n; i++) {
        double sum = 0;
        for (size_t j = 0; j < m; j++) {
            sum += answer[j] * matrix[i][j];
        }
        if (std::abs(sum - matrix[i][m]) > EPS) {
            return 0;
        }
    }
 
    for (size_t i = 0; i < m; i++) {
        if (where[i] == -1) {
            return INF;
        }
    }
    return 1;
}

int main() {
  freopen("continuous.in", "r", stdin);
  freopen("continuous.out", "w", stdout);
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
    for (int i = 0; i < len[it]; i++) {
        scanf("%lf", &out[i]);
    }
    int state = 0;
    std::vector<int> variables;
    for (int i = 0; i < len[it]; i++) {
        int new_varible = state * 2 + 1;
        if (in[i] == '0') {
            new_varible = state * 2;
        }
        variables.push_back(new_varible);
        for (size_t j = 0; j < variables.size(); j++) {
            for (size_t k = 0; k < variables.size(); k++) {
                matrix[variables[j]][variables[k]] += 2. / len[it];
            }
            matrix[variables[j]][2 * n] += 2. * out[i] / len[it];
        }
        if (in[i] == '0') {
            state = go[state][0];
        } else {
            state = go[state][1];
        }
     }
  }
  std::vector<double> answer;
  assert(gauss(matrix, answer) == 1);
  for (int i = 0; i < n; i++) {
    printf("%.10f %.10f\n", answer[2 * i], answer[2 * i + 1]);
  }
  return 0;
}