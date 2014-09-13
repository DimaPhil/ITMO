#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    if (a == "1")
        cout << b;
    else
    if (b == "1")
        cout << a;
    else
        cout << 4 << '\n';
}