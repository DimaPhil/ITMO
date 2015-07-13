#ifndef CLIONPROJECTS_UTILS_H
#define CLIONPROJECTS_UTILS_H

#include <typeinfo>
#include <string>
#include <vector>

namespace Utils {
    class Hasher {
    private:
        const int64_t BASE = 239017;
        const int64_t MODULO = (int64_t)1e9 + 7;

        int64_t boxed_value(int64_t value) {
            return (value % MODULO + MODULO) % MODULO;
        }

        std::string s;
        std::vector<int64_t> hashes;
        std::vector<int64_t> powers;
    public:
        Hasher() {}
        Hasher(const std::string &s) {
            this->s = s;
            hashes.resize(s.size() + 1);
            hashes[0] = 0;
            for (size_t i = 0; i < s.size(); i++) {
                hashes[i + 1] = boxed_value(hashes[i] * BASE + s[i]);
            }
            powers.resize(s.size() + 1);
            powers[0] = 1;
            for (int i = 1; i <= s.size(); i++) {
                powers[i] = boxed_value(powers[i - 1] * BASE);
            }
        }

        int64_t hash(size_t l, size_t r) {
            return boxed_value(hashes[r + 1] - hashes[l] * powers[r - l + 1]);
        }

        int64_t hash() {
            return hash(0, s.size() - 1);
        }
    };

    bool is_whitespace(char symbol) {
        return symbol == ' ' || symbol == '\t';
    }

    bool is_end_of_line(char symbol) {
        return symbol == '\n' || symbol == '\r';
    }

    template <typename Base, typename Derived>
    bool check_class_inherity(Derived *derived) {
        try {
            dynamic_cast<Base*&>(derived);
            return true;
        } catch (const std::bad_cast&) {
            return false;
        }
    }
}

#endif //CLIONPROJECTS_UTILS_H
