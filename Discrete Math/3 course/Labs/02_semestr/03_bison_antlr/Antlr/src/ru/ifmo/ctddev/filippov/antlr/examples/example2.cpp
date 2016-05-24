#include <bits/stdc++.h>

std::array<std::array<std::array<int, (3+1)>, (3+1)>, (3+1)> a;
std::array<std::array<int, (3+1)>, (3+1)> b;
std::array<std::array<int, (3+1)>, (3+1)> c;
int i, j, k;

int main() {
  for (i = 1; i != 3+1; i++) {
          for (j = 1; j != 3+1; j++) {
                for (k = 1; k != 3+1; k++) {
                                a[i][j][k] = i + j + k;
                                ;
                };
          };
          ;
  };
  for (i = 1; i != 3+1; i++) {
      for (j = 1; j != 3+1; j++) {
            b[i][j] = i * j;
      };
  };
  for (i = 3; i != 1-1; i--) {
      for (j = 3; j != 1-1; j--) {
                  for (k = 3; k != 1-1; k--) {
                          std::cout << a[i][j][k] << " ";
                  };
                  std::cout << std::endl;
                  ;
      };
  };
  std::cout << std::endl;
  for (i = 1; i != 3+1; i++) {
          for (j = 1; j != 3+1; j++) {
                std::cout << b[i][j] << " ";
          };
          std::cout << std::endl;
          ;
  };
  ;
  return 0;
}

