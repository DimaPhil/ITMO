#include <bits/stdc++.h>

void query(const std::vector<double> &x) {
    for (double coordinate_x : x) {
        double c = coordinate_x;
        c = std::max(0., c);
        c = std::min(1., c);
        printf("%.10f ", c);
        assert(0 <= c && c <= 1);
    }
    printf("\n");
    fflush(stdout);
}

const int MAX_SEGMENTS = 20;
const int MAX_ITERATIONS = 25;

int n;
std::vector<double> ms;
double global_minumum = 1e18;

double calc_function(int i, double x) {
    ms[i] = x;
    query(ms);
    double local_minumum;
    scanf("%lf", &local_minumum);
    return local_minumum;
}

int main() {
    scanf("%d", &n);
    ms.resize(n);
    for (int i = 0; i < n; i++) {
        double len = 1. / MAX_SEGMENTS;
        double best_coordinate = -1;
        for (int iter = 0; iter < MAX_SEGMENTS; iter++) {
            double l = iter * len, r = l + len;
            double m1, m2, f_m1, f_m2;
            for (int it = 0; it < MAX_ITERATIONS; it++) {
                m1 = (2 * l + r) / 3;
                m2 = (l + 2 * r) / 3;
                f_m1 = calc_function(i, m1);
                f_m2 = calc_function(i, m2);
                if (f_m1 > f_m2) {
                   l = m1;
                } else {
                    r = m2;
                }
            }
            if (f_m1 < global_minumum) {
                global_minumum = f_m1;
                best_coordinate = m1;
            }
            if (f_m2 < global_minumum) {
                global_minumum = f_m2;
                best_coordinate = m2;
            }
        }
        ms[i] = best_coordinate;
    }
    printf("minimum %.10f\n", global_minumum);
    fflush(stdout);
    return 0;
}
