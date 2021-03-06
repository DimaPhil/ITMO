#include "big_integer.h"

#include <algorithm>
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <stdexcept>

/* Private functions */

const big_integer ZERO = big_integer(0);
const big_integer ONE = big_integer(1);

void big_integer::__delete_zeroes()
{
  while (digits.size() > 1 && !digits.back())
    digits.pop_back();
  if (!digits.back())
    sign = 0;
}

void big_integer::__additional_code()
{
  for (size_t i = 0; i < digits.size(); ++i)
    digits[i] = ~digits[i];
  --(*this);
}

/* Constructors */

big_integer::big_integer()
{
  *this = ZERO;
}

big_integer::big_integer(big_integer const& other)
{
  sign = other.sign;
  digits = other.digits;
}

big_integer::big_integer(unsigned int a)
{
  digits.clear();
  if (!a) {
    sign = 0;
    digits.push_back(0);
    return;
  }
  sign = 1;
  digits.push_back(a);
}

big_integer::big_integer(int a)
{
  digits.clear();
  if (!a) {
    sign = 0;
    digits.push_back(0);
    return;
  }
  sign = a > 0 ? 1 : (!a ? 0 : -1);
  if (a < 0)
    a = -a;
  digits.push_back(a);
}

big_integer::big_integer(long long a)
{
  digits.clear();
  if (!a) {
    sign = 0;
    digits.push_back(0);
    return;
  }
  sign = a > 0 ? 1 : (!a ? 0 : -1);
  if (a < 0)
    a = -a;
  digits.push_back(a & (1LL * base));
  digits.push_back(a >> blen);
  __delete_zeroes();
}

big_integer::big_integer(std::string const& str)
{
  int start_index = 0;
  char need_sign = 0;
  if (str.size() > 0 && str[0] == '-')
    start_index = 1, need_sign = -1;
  if (start_index == (int)str.size())
    throw std::runtime_error("Invalid string in input");

  big_integer rs[10];
  for (int i = 0; i < 10; ++i)
    rs[i] = i;
  bool is_zero = true;
  *this = ZERO;
  for (size_t i = start_index; i < str.size(); ++i)
  {
    if (!isdigit(str[i]))
      throw std::runtime_error("Invalid string in input");

    if (str[i] != '0')
      is_zero = false;
    *this *= 10;
    *this += rs[str[i] - '0'];
  }

  if (!is_zero && !need_sign)
    need_sign = 1;
  if (is_zero)
    need_sign = 0;

  sign = need_sign;
}

/* Destructor */

big_integer::~big_integer()
{
  sign = 0;
  digits.clear();
}

/* Operators =, +=, -=, *=, /=, %= */

big_integer& big_integer::operator = (big_integer const& other)
{
  sign = other.sign;
  digits = other.digits;
  return *this;
}

big_integer& big_integer::operator += (big_integer const& rhs)
{
  if (!sign)
  {
    (*this) = rhs;
    return *this;
  }

  if ((sign == 1 && rhs.sign >= 0) || (sign == -1 && rhs.sign <= 0))
  {
    size_t size = std::max(digits.size(), rhs.digits.size());
    int carry = 0;
    for (size_t i = 0; i < size || carry; ++i)
    {
      if (i == digits.size())
        digits.push_back(0);
      ll rdigit = (i < rhs.digits.size() ? rhs.digits[i] : 0);
      ll current = digits[i] + rdigit + carry;
      carry = current > (ll)base;
      if (carry)
        digits[i] = current - base - 1;
      else
        digits[i] = current;
    }
  }
  else
  {
    sign = rhs.sign;
    if ((*this) == rhs)
      return *this = ZERO;
    if (rhs.sign == -1)
      sign = 1, *this -= -rhs;
    else
      *this = rhs - (*this);
  }

  __delete_zeroes();
  return *this;
}

big_integer& big_integer::operator -= (big_integer const& rhs)
{
  if (!rhs.sign)
    return *this;
  if (!sign)
    return *this = -rhs;

  if (sign == 1 && rhs.sign == -1)
    return (*this) += (-rhs);
  if (sign == -1 && rhs.sign == 1)
  {
    *this = -(*this);
    *this += rhs;
    return *this = -(*this);
  }

  if ((*this) == rhs)
    return *this = ZERO;

  if (sign == 1)
  {
    if ((*this) < rhs)
      *this = -(rhs - (*this));
    else
    {
      int carry = 0;
      for (size_t i = 0; i < rhs.digits.size() || carry; ++i)
      {
        ll rdigit = (i < rhs.digits.size() ? rhs.digits[i] : 0);
        ll current = digits[i] - rdigit - carry;
        carry = current < 0;
        if (carry)
          digits[i] = current + base + 1;
        else
          digits[i] = current;
      }
      __delete_zeroes();
    }
  }
  else
  {
    if ((*this) > rhs)
      *this = (-rhs) + (*this);
    else
    {
      int carry = 0;
      for (size_t i = 0; i < rhs.digits.size() || carry; ++i)
      {
        ll rdigit = (i < rhs.digits.size() ? rhs.digits[i] : 0);
        ll current = digits[i] - rdigit - carry;
        carry = current < 0;
        if (carry)
          digits[i] = current + base + 1;
        else
          digits[i] = current;
      }
      __delete_zeroes();
    }
  }

  return *this;
}

/*big_integer& big_integer::operator *= (unsigned long long const& rhs)
{
  unsigned long long carry = 0;
  for (size_t i = 0; i < digits.size() || carry; ++i)
  {
    if (i == digits.size())
      digits.push_back(0);
    unsigned long long current = carry + (unsigned long long)digits[i] * rhs;
    digits[i] = current & (base - 1);
    carry = current >> blen;
  }

  __delete_zeroes(*this);
  return *this;
} */

big_integer& big_integer::operator *= (big_integer const& rhs)
{
  if (!sign || !rhs.sign)
    return *this = ZERO;
  sign = ((sign == -1) ^ (rhs.sign == -1)) ? -1 : 1;

  my_vector ans(digits.size() + rhs.digits.size());
  for (size_t i = 0; i < digits.size(); ++i)
  {
    uint carry = 0;
    for (size_t j = 0; j < rhs.digits.size() || carry; ++j)
    {
      uint rdigit = (j < rhs.digits.size() ? rhs.digits[j] : 0);
      unsigned long long current = ans[i + j] + 1ULL * digits[i] * rdigit + carry;
      ans[i + j] = current & (1ULL * base);
      carry = current >> blen;
    }
  }

  digits.resize(ans.size());
  for (size_t i = 0; i < ans.size(); ++i)
    digits[i] = ans[i];
  __delete_zeroes();
  return *this;
}

big_integer& big_integer::operator /= (int const& rhs)
{
  if (!sign)
    return *this = ZERO;
  int r = rhs;

  int carry = 0;
  sign = ((sign == -1) ^ (r < 0)) ? -1 : 1;
  if (r < 0)
    r = -r;
  for (int i = (int)digits.size() - 1; i >= 0; --i)
  {
    ll current = digits[i] + carry * (1LL * base + 1);
    lldiv_t result = lldiv(current, r);
    digits[i] = result.quot;
    carry = result.rem;
  }

  __delete_zeroes();
  return *this;
}

big_integer& big_integer::operator /= (big_integer const& rhs)
{
  if (!rhs.sign)
    throw std::runtime_error("Division by zero!");
  if (!sign)
    return *this = ZERO;

  big_integer r = big_integer(rhs);
  char need_sign = (r.sign * sign == -1) ? -1 : 1;
  sign = 1;
  r.sign = 1;
  if ((*this) < r)
    return *this = ZERO;

  int n = r.digits.size();
  int m = digits.size() - n;
  if (r.digits[n - 1] <= (base >> 1))
  {
    ll tmp = (1LL * base + 1) / (r.digits[n - 1] + 1);
    *this *= tmp;
    r *= tmp;
    n = r.digits.size();
    m = digits.size() - n;
  }

  my_vector result(m + 1);
  big_integer y = r << (m * blen);
  if (*this >= y)
  {
    result[m] = 1;
    *this -= y;
  }

  for (int j = m - 1; j >= 0; --j)
  {
    if ((int)digits.size() <= n + j)
      break;

    int len = y.digits.size();
    for (size_t i = r.digits.size(); i > 0; --i)
      y.digits[len - i - 1] = y.digits[len - i];
    y.digits.pop_back();

    unsigned long long quot = (digits[n + j] * (1ULL * base + 1) + digits[n + j - 1]) / r.digits[n - 1];
    quot = std::min(quot, 1ULL * base);
    uint res = quot;

    *this -= y * res;

    while (sign == -1)
    {
      *this += y;
      --res;
    }
    result[j] = res;
  }

  big_integer res;
  res.sign = need_sign;
  res.digits = result;
  res.__delete_zeroes();
  return *this = res;
}

/*int big_integer::operator %= (int const& rhs)
{
  int carry = 0;
  for (int i = (int)digits.size() - 1; i >= 0; --i)
  {
    unsigned long long current = digits[i] + 1ULL * carry * base;
    lldiv_t result = lldiv(current, rhs);
    digits[i] = result.quot;
    carry = result.rem;
  }

  __delete_zeroes(*this);
  return carry;
} */

big_integer& big_integer::operator %= (big_integer const& rhs)
{
  if (!sign)
    return *this;

  *this -= (*this / rhs) * rhs;
  __delete_zeroes();
  return *this;
}

/* Binary operators (&=, |=, ^=) */

big_integer& big_integer::operator &= (big_integer const& rhs)
{
  if (!sign || !rhs.sign)
    return *this = ZERO;

  char need_sign = (sign == -1 && rhs.sign == -1) ? -1 : 1;
  big_integer r = big_integer(rhs);
  if (r.digits.size() > digits.size())
    digits.resize(r.digits.size());
  if (digits.size() > r.digits.size())
    r.digits.resize(digits.size());


  if (sign == -1)
    __additional_code();
  if (r.sign == -1)
    r.__additional_code();

  for (size_t i = 0; i < digits.size(); ++i)
    digits[i] &= r.digits[i];
  sign = need_sign;
  if (need_sign == -1)
    __additional_code();

  __delete_zeroes();
  return *this;
}

big_integer& big_integer::operator |= (big_integer const& rhs)
{
  if (!sign || !rhs.sign)
    return *this = ZERO;

  char need_sign = (sign == -1 || rhs.sign == -1) ? -1 : 1;
  big_integer r = big_integer(rhs);
  if (r.digits.size() > digits.size())
    digits.resize(r.digits.size());
  if (digits.size() > r.digits.size())
    r.digits.resize(digits.size());


  if (sign == -1)
    __additional_code();
  if (r.sign == -1)
    r.__additional_code();

  for (size_t i = 0; i < digits.size(); ++i)
    digits[i] |= r.digits[i];
  sign = need_sign;
  if (need_sign == -1)
    __additional_code();

  __delete_zeroes();
  return *this;
}

big_integer& big_integer::operator ^= (big_integer const& rhs)
{
  if (!sign || !rhs.sign)
    return *this = ZERO;

  char need_sign = ((sign == -1) ^ (rhs.sign == -1)) ? -1 : 1;
  big_integer r = big_integer(rhs);
  if (r.digits.size() > digits.size())
    digits.resize(r.digits.size());
  if (digits.size() > r.digits.size())
    r.digits.resize(digits.size());


  if (sign == -1)
    __additional_code();
  if (r.sign == -1)
    r.__additional_code();

  for (size_t i = 0; i < digits.size(); ++i)
    digits[i] ^= r.digits[i];
  sign = need_sign;
  if (need_sign == -1)
    __additional_code();

  __delete_zeroes();
  return *this;
}

/* Shifts (<<=, >>=) */

big_integer& big_integer::operator <<= (int rhs)
{
  if (rhs < 0)
    throw std::runtime_error("Cannot shift to negative value");

  if (sign == -1)
    __additional_code();

  div_t result = div(rhs, blen);
  if (result.rem)
  {
    ll carry = 0;
    ll BASE = base;
    for (size_t i = 0; i < digits.size() || carry; ++i)
    {
      if (i == digits.size())
        digits.push_back(0);
      ll current = ((1LL * digits[i]) << result.rem) + carry;
      digits[i] = current & BASE;
      carry = current >> blen;
    }
  }

  int new_size = digits.size() + result.quot;
  digits.resize(new_size);
  for (int i = new_size - 1; i >= result.quot; --i)
    digits[i] = digits[i - result.quot];
  for (int i = result.quot - 1; i >= 0; --i)
    digits[i] = 0;

  if (sign == -1)
    __additional_code();

  __delete_zeroes();
  return *this;
}

big_integer& big_integer::operator >>= (int rhs)
{
  if (rhs < 0)
    throw std::runtime_error("Cannot shift to negative value");

  if (sign == -1)
    __additional_code();

  div_t result = div(rhs, blen);

  int new_size = digits.size() - result.quot;
  for (size_t i = result.quot; i < digits.size(); ++i)
    digits[i - result.quot] = digits[i];
  for (size_t i = digits.size() - result.quot; i < digits.size(); ++i)
    digits[i] = 0;
  digits.resize(new_size);

  if (result.rem)
  {
    ll carry = 0;
    if (sign == -1)
      carry = base;
    ll BASE = base;
    int power = blen - result.rem;
    for (int i = (int)digits.size() - 1; i >= 0; --i)
    {
      ll shl = (1LL * digits[i]) >> result.rem;
      ll current = shl + (carry << power);
      carry = digits[i] - (shl << result.rem);
      digits[i] = current & BASE;
    }
  }

  if (sign == -1)
    __additional_code();

  __delete_zeroes();
  return *this;
}

/* Unary operators (-, +, ~) */

big_integer big_integer::operator - () const
{
  big_integer r = big_integer(*this);
  r.sign = -r.sign;
  return r;
}

big_integer big_integer::operator + () const
{
  return *this;
}

big_integer big_integer::operator ~ () const
{
  big_integer r = big_integer(*this);
  r = -r - 1;
  r.__delete_zeroes();
  return r;
}

/* Increment operators (++) */

big_integer& big_integer::operator ++ ()
{
  *this += big_integer(1);
  return *this;
}

big_integer big_integer::operator ++ (int)
{
  big_integer r = *this;
  ++(*this);
  return r;
}

/* Decrement operator (--) */

big_integer& big_integer::operator -- ()
{
  *this -= big_integer(1);
  return *this;
}

big_integer big_integer::operator -- (int)
{
  big_integer r = *this;
  --(*this);
  return r;
}

/* Operators +, -, *, /, % */

big_integer operator + (big_integer a, big_integer const& b)
{
  return a += b;
}

big_integer operator - (big_integer a, big_integer const& b)
{
  return a -= b;
}

/*big_integer operator * (big_integer a, int const& b)
{
  return a *= b;
} */

big_integer operator * (big_integer a, big_integer const& b)
{
  return a *= b;
}

big_integer operator / (big_integer a, int const& b)
{
  return a /= b;
}

big_integer operator / (big_integer a, big_integer const& b)
{
  return a /= b;
}

/*int operator % (big_integer a, int const& b)
{
  return a %= b;
} */

big_integer operator % (big_integer a, big_integer const& b)
{
  return a %= b;
}

/* Binary operators (&, |, ^) */

big_integer operator & (big_integer a, big_integer const& b)
{
  return a &= b;
}

big_integer operator | (big_integer a, big_integer const& b)
{
  return a |= b;
}

big_integer operator ^ (big_integer a, big_integer const& b)
{
  return a ^= b;
}

/* Shift (<<, >>) */

big_integer operator << (big_integer a, int b)
{
  return a <<= b;
}

big_integer operator >> (big_integer a, int b)
{
  return a >>= b;
}

/* Comparsion operators (==, !=, <, <=, >, >=)*/

bool operator == (big_integer const& a, big_integer const& b)
{
  if (a.sign != b.sign || a.digits.size() != b.digits.size())
    return false;

  for (size_t i = 0; i < a.digits.size(); ++i)
    if (a.digits[i] != b.digits[i])
      return false;
  return true;
}

bool operator != (big_integer const& a, big_integer const& b)
{
  return !(a == b);
}

bool operator < (big_integer const& a, big_integer const& b)
{
  if (a.sign != b.sign)
    return a.sign < b.sign;
  if (a.digits.size() != b.digits.size())
    return a.sign == 1 ? a.digits.size() < b.digits.size() : a.digits.size() > b.digits.size();

  for (int i = (int)a.digits.size() - 1; i >= 0; --i)
    if (a.digits[i] != b.digits[i])
      return a.sign == 1 ? a.digits[i] < b.digits[i] : a.digits[i] > b.digits[i];
  return false;
}

bool operator <= (big_integer const& a, big_integer const& b)
{
  if (a.sign != b.sign)
    return a.sign < b.sign;
  if (a.digits.size() != b.digits.size())
    return a.sign == 1 ? a.digits.size() < b.digits.size() : a.digits.size() > b.digits.size();

  for (int i = (int)a.digits.size() - 1; i >= 0; --i)
    if (a.digits[i] != b.digits[i])
      return a.sign == 1 ? a.digits[i] < b.digits[i] : a.digits[i] > b.digits[i];
  return true;
}

bool operator > (big_integer const& a, big_integer const& b)
{
  return !(a <= b);
}

bool operator >= (big_integer const& a, big_integer const& b)
{
  return !(a < b);
}

/* Big integer to string */

std::string to_string(big_integer const& a)
{
  if (!a.digits.size())
    throw std::runtime_error("Cannot output this number: no constructors were called");
  if (!a.sign)
    return "0";

  std::string number = "";
  char sign = a.sign;
  big_integer b = big_integer(a);
  big_integer divisor = 10;
  while (b.sign)
  {
    big_integer last_digit = b % divisor;
    number += char('0' + last_digit.digits[0]);
    b /= divisor;
  }
  if (sign == -1)
    number += '-';

  reverse(number.begin(), number.end());
  return number;
}

/* Operator << to std::cout */

std::ostream& operator << (std::ostream& s, big_integer const& a)
{
  return s << to_string(a);
}
