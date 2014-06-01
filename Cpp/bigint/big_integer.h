#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include <vector>
#include <string>

const int base = 1 << 30;
const int blen = 30;

typedef long long ll;

struct big_integer {
    char sign;
    std::vector <ll> digits;
 
    big_integer();
    big_integer(big_integer const& other);
    big_integer(int a);
    explicit big_integer(std::string const& str);
    ~big_integer();

    big_integer& operator = (big_integer const& other);

    big_integer& operator += (big_integer const& rhs);
    big_integer& operator -= (big_integer const& rhs);
    big_integer& operator *= (int const& rhs);
    big_integer& operator *= (big_integer const& rhs);
    big_integer& operator /= (int const& rhs); 
    big_integer& operator /= (big_integer const& rhs);
    int operator %= (int const& rhs); 
    big_integer& operator %= (big_integer const& rhs);

    big_integer& operator &= (big_integer const& rhs);
    big_integer& operator |= (big_integer const& rhs);
    big_integer& operator ^= (big_integer const& rhs);

    big_integer& operator <<= (int rhs);
    big_integer& operator >>= (int rhs);

    big_integer operator + () const;
    big_integer operator - () const;
    big_integer operator ~ () const;

    big_integer& operator ++ ();
    big_integer operator ++ (int);

    big_integer& operator -- ();
    big_integer operator -- (int);

    friend bool operator == (big_integer const& a, big_integer const& b);
    friend bool operator != (big_integer const& a, big_integer const& b);
    friend bool operator < (big_integer const& a, big_integer const& b);
    friend bool operator > (big_integer const& a, big_integer const& b);
    friend bool operator <= (big_integer const& a, big_integer const& b);
    friend bool operator >= (big_integer const& a, big_integer const& b);

    friend std::string to_string(big_integer const& a);
};

big_integer operator + (big_integer a, big_integer const& b);
big_integer operator - (big_integer a, big_integer const& b);
big_integer operator * (big_integer a, int const& b);
big_integer operator * (big_integer a, big_integer const& b);
big_integer operator / (big_integer a, int const& b);
big_integer operator / (big_integer a, big_integer const& b);
int operator % (big_integer a, int const& b);
big_integer operator % (big_integer a, big_integer const& b);

big_integer operator & (big_integer a, big_integer const& b);
big_integer operator | (big_integer a, big_integer const& b);
big_integer operator ^ (big_integer a, big_integer const& b);

big_integer operator << (big_integer a, int b);
big_integer operator >> (big_integer a, int b);

bool operator == (big_integer const& a, big_integer const& b);
bool operator != (big_integer const& a, big_integer const& b);
bool operator < (big_integer const& a, big_integer const& b);
bool operator > (big_integer const& a, big_integer const& b);
bool operator <= (big_integer const& a, big_integer const& b);
bool operator >= (big_integer const& a, big_integer const& b);

std::string to_string(big_integer const& a);
std::ostream& operator << (std::ostream& s, big_integer const& a);

#endif // BIG_INTEGER_H
