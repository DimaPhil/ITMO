#include <bits/stdc++.h>

const int max_sum = 15 * 9;

std::vector<int> get_digits(long long n) {
    std::vector<int> digits;
    long long n0 = n;
    while (n0) {
        digits.push_back(n0 % 10);
        n0 /= 10;
    }
    std::reverse(digits.begin(), digits.end());
    return digits;
}

long long memory[2][max_sum][max_sum];

long long go(const std::vector<int> &digits, int pos, bool was, int sum) {
    if (pos == (int)digits.size()) {
        return !sum ? 1 : 0;
    }
    long long &ans = memory[was][pos][sum];
    if (ans != -1) {
        return ans;
    }
    ans = 0;
    int end_digit = was ? 9 : digits[pos];
    for (int digit = 0; digit <= end_digit; digit++) {
        if (digit > sum) {
            break;
        }
        ans += go(digits, pos + 1, was | (digit < digits[pos]), sum - digit);
    }
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long k, n;
    std::cin >> n >> k;

    std::vector<int> digits_n = get_digits(n);
    std::vector<int> digits_k = get_digits(k);
    for (int i = 0; i < 2; i++)
    for (int j = 0; j < max_sum; j++)
    for (int k = 0; k < max_sum; k++)
        memory[i][j][k] = -1;
    int s = 0;
    for (size_t i = 0; i < digits_k.size(); i++) {
        s += digits_k[i];
    }
    long long result = 0;
    for (int i = 1; i < s; i++) {
        result += go(digits_n, 0, false, i);
    }
    for (int i = 0; i < 2; i++)
    for (int j = 0; j < max_sum; j++)
    for (int k = 0; k < max_sum; k++)
        memory[i][j][k] = -1;
    digits_n = digits_k;
    result += go(digits_n, 0, false, s);
    std::cout << result << '\n';
    return 0;
}
