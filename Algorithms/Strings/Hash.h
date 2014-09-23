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
