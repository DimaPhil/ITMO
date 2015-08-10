#include <cstdio>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <cassert>

#include <set.h>

int main() {
    srand(time(nullptr));
    set s;
    s.insert("abacaba");
    set t = s;
    s.erase("abacaba");
    assert(t.contains("abacaba"));
    s = t;
    return 0;
}
