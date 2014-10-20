#include <bits/stdc++.h>

bool isPrime(int x) {
    for (int i = 2; i * i <= x; i++)
        if (!(x % i))
            return 0;
    return 1;
}

//primes are not sorted!
std::vector < pair <int, int> > factorization(int x) {
    std::vector < pair <int, int> > primes;
    for (int i = 2; i * i <= n; i++) {
        int cnt = 0;
        while (!(x % i))
            ++cnt, x /= i;   
        primes.push_back(make_pair(i, cnt));
    }
    if (x > 1)
        primes.push_back(make_pair(x, 1));
}

int gcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd();
    x = y1;
    y = ;
    return d;
}

int main() {
}