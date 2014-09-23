#include <bits/stdc++.h>

struct HashWithManyModules {
    const long long base = 239017;
    const int modulesCount = 2;
    long long modules[2] = {(int)1e9 + 7, (int)1e6 + 3};

    template <typename T>
    T _mmod(T x, long long mod) {
        return (x % mod + mod) % mod;
    }

    size_t _updateSize(std::vector <long long> &v, size_t newSize) {
        if (v.size() < newSize)
            v.resize(newSize);
        return v.size();
    }

    void _updatePowers(size_t size) {
        size_t lastSize = powers[0].size();
        size_t newSize;
        for (int i = 0; i < modulesCount; ++i)
            newSize = _updateSize(powers[i], size);
        if (!lastSize) {
            for (int i = 0; i < modulesCount; ++i)                 
                powers[i][lastSize] = 1;
            ++lastSize;
        }
        for (int i = 0; i < modulesCount; ++i)
        for (size_t it = lastSize; it < newSize; ++it)
            powers[i][it] = _mmod(powers[i][it - 1] * base, modules[i]);
    }

    HashWithManyModules() { n = 0; }
    HashWithManyModules(std::string &s) { 
        n = s.size();
        hash.resize(modulesCount);
        hashRev.resize(modulesCount);
        powers.resize(modulesCount);

        _updatePowers(n + 1);
        for (int i = 0; i < modulesCount; ++i) {
            hash[i].resize(n + 1);
            hash[i][0] = 0;
            for (size_t it = 0; it < n; ++it)
                hash[i][it + 1] = _mmod(hash[i][it] * base + s[it], modules[i]);
            hashRev[i].resize(n + 1);
            hashRev[i][n] = 0;
            for (int it = n - 1; it >= 0; --it)
                hashRev[i][it] = _mmod(hashRev[i][it + 1] * base + s[it], modules[i]);
        }
    }
    HashWithManyModules(char *s) { 
        n = strlen(s);
        hash.resize(modulesCount);
        hashRev.resize(modulesCount);
        powers.resize(modulesCount);

        _updatePowers(n + 1);
        for (int i = 0; i < modulesCount; ++i) {
            hash[i].resize(n + 1);
            hash[i][0] = 0;
            for (size_t it = 0; it < n; ++it)
                hash[i][it + 1] = _mmod(hash[i][it] * base + s[it], modules[i]);
            hashRev[i].resize(n + 1);
            hashRev[i][n] = 0;
            for (int it = n - 1; it >= 0; --it)
                hashRev[i][it] = _mmod(hashRev[i][it + 1] * base + s[it], modules[i]);
        }
    }

    long long getHash(int l, int r, int moduloIndex) {
        assert(0 <= l && l <= r && r < (int)n);
        return _mmod(hash[moduloIndex][r + 1] - hash[moduloIndex][l] * powers[moduloIndex][r - l + 1], modules[moduloIndex]);
    }

    long long getReversedHash(int l, int r, int moduloIndex) {
        assert(0 <= l && l <= r && r < (int)n);
        return _mmod(hashRev[moduloIndex][l] - hashRev[moduloIndex][r + 1] * powers[moduloIndex][r - l + 1], modules[moduloIndex]);
    }

    bool eq(int l1, int r1, int l2, int r2) {
        bool isEq = 1;
        for (int i = 0; i < modulesCount && isEq; ++i)
            isEq &= getHash(l1, r1, i) == getHash(l2, r2, i);
        return isEq;
    }

    bool eqReversed(int l1, int r1, int l2, int r2) {
        bool isEq = 1;
        for (int i = 0; i < modulesCount && isEq; ++i)
            isEq &= getReversedHash(l1, r1, i) == getReversedHash(l2, r2, i);
        return isEq;
    }

private:
    size_t n;
    std::vector < std::vector <long long> > hash, hashRev;
    std::vector < std::vector <long long> > powers;
};
