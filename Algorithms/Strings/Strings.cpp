#include <bits/stdc++.h>

struct Hash {
    const long long base = 239017;
    const long long mod = 1e9 + 7;

    template <typename T>
    T _mmod(T x) {
        return (x % mod + mod) % mod;
    }

    size_t _updateSize(std::vector <long long> &v, size_t newSize) {
        if (v.size() < newSize)
            v.resize(newSize);
        return v.size();
    }

    void _updatePowers(size_t size) {
        size_t lastSize = powers.size();
        size_t newSize = _updateSize(powers, size);
        if (!lastSize)
            powers[lastSize++] = 1;
        for (size_t it = lastSize; it < newSize; ++it)
            powers[it] = _mmod(powers[it - 1] * base);
    }

    Hash() { n = 0, hash.clear(), powers.clear(); }
    Hash(std::string &s) { 
        n = s.size();

        _updatePowers(n + 1);
        hash.resize(n + 1);
        hash[0] = 0;
        for (size_t i = 0; i < n; ++i)
            hash[i + 1] = _mmod(hash[i] * base + s[i]);
        hashRev.resize(n + 1);
        hashRev[n] = 0;
        for (int i = n - 1; i >= 0; --i)
            hashRev[i] = _mmod(hashRev[i + 1] * base + s[i]);
    }
    Hash(char *s) { 
        n = strlen(s);

        _updatePowers(n + 1);
        hash.resize(n + 1);
        hash[0] = 0;
        for (size_t i = 0; i < n; ++i)
            hash[i + 1] = _mmod(hash[i] * base + s[i]);
        hashRev.resize(n + 1);
        hashRev[n] = 0;
        for (int i = n - 1; i >= 0; --i)
            hashRev[i] = _mmod(hashRev[i + 1] * base + s[i]);
    }

    long long getHash(int l, int r) {
        assert(0 <= l && l <= r && r < (int)n);
        return _mmod(hash[r + 1] - hash[l] * powers[r - l + 1]);
    }

    long long getReversedHash(int l, int r) {
        assert(0 <= l && l <= r && r < (int)n);
        return _mmod(hashRev[l] - hashRev[r + 1] * powers[r - l + 1]);
    }

    bool eq(int l1, int r1, int l2, int r2) {
        return getHash(l1, r1) == getHash(l2, r2);
    }

    bool eqReversed(int l1, int r1, int l2, int r2) {
        return getReversedHash(l1, r1) == getReversedHash(l2, r2);
    }

private:
    size_t n;
    std::vector <long long> hash, hashRev;
    std::vector <long long> powers;
};

/*-------------------------------------------------------------------------*/ 

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

/* -------------------------------------------------------------------------- */

void calcKMP(std::string &s, std::vector <int> &pi) {
    size_t n = s.size();
    pi.resize(n);
    pi[0] = 0;
    for (size_t i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            ++j;
        pi[i] = j;
    }            
}

/* -------------------------------------------------------------------------- */

void calcZ(std::string &s, std::vector <int> &z) {
    size_t n = s.size();
    z.resize(s.size());
    z[0] = 0;
    size_t  l = 0, r = 0;
    for (size_t i = 1; i < n; ++i) {
        if (i <= r)
            z[i] = std::min(z[i - l], (int)(r - i + 1));
        while (i + z[i] < n && s[i + z[i]] == s[i])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}

/* -------------------------------------------------------------------------- */

int main() {
    std::string s = "abacaba";
    Hash hasher(s);
    printf("%lld %lld\n", hasher.getHash(0, 2), hasher.getHash(4, 6));
    printf("%lld %lld\n", hasher.getReversedHash(0, 1), hasher.getReversedHash(4, 5));

    HashWithManyModules hasherPro(s);
    printf("%d\n", hasherPro.eq(0, 2, 4, 6));
    printf("%d\n", hasherPro.eqReversed(0, 1, 4, 5));
    return 0;
}