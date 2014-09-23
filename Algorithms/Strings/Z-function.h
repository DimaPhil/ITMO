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
