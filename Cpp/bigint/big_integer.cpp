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

void __delete_zeroes(big_integer& r)
{
  while (r.digits.size() > 1 && !r.digits.back())
    r.digits.pop_back();
  if (!r.digits.back())
    r.sign = 0;
}

big_integer tilda(big_integer const& rhs)
{
  big_integer r = big_integer(rhs);
  for (size_t i = 0; i < r.digits.size(); ++i)
    r.digits[i] = ~(unsigned int)r.digits[i];
  __delete_zeroes(r);
  return r;
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

big_integer::big_integer(int a) 
{
  digits.clear();
  if (!a) {
    sign = 0;
    digits.push_back(0);
    return;
  }
  sign = a > 0 ? 1 : (!a ? 0 : -1);
  a = abs(a);

  int power = 1, num = 0;
  while (a) 
  {
    num += power * (a & 1);
    a >>= 1;
    if ((power <<= 1) == base)
      power = 1, digits.push_back(num), num = 0;
  }
  if (num)
    digits.push_back(num);
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
    rs[i] = big_integer(i);
  bool is_zero = true;
  *this = big_integer(0);
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
      int rdigit = (i < rhs.digits.size() ? rhs.digits[i] : 0);
      carry = (digits[i] += rdigit + carry) >= base;
      if (carry)
        digits[i] -= base;
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
        int rdigit = (i < rhs.digits.size() ? rhs.digits[i] : 0);
        carry = (digits[i] -= carry + rdigit) < 0;
        if (carry)
          digits[i] += base;
      }
      __delete_zeroes(*this);
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
        int rdigit = (i < rhs.digits.size() ? rhs.digits[i] : 0);
        carry = (digits[i] -= carry + rdigit) < 0;
        if (carry)
          digits[i] += base;
      }
      __delete_zeroes(*this);
    }
  }

  return *this;
} 

big_integer& big_integer::operator *= (int const& rhs) 
{
  int carry = 0;
  for (size_t i = 0; i < digits.size() || carry; ++i)
  {
    if (i == digits.size())
      digits.push_back(0);
    ll current = carry + 1ll * digits[i] * rhs;
    digits[i] = current & (base - 1);
    carry = current >> blen;
  }

  __delete_zeroes(*this);
  return *this;
}

big_integer& big_integer::operator *= (big_integer const& rhs) 
{
  if (!sign || !rhs.sign)
    return *this = ZERO;
  big_integer r = ZERO;
  r.sign = sign != rhs.sign ? -1 : 1;

  r.digits.resize(digits.size() + rhs.digits.size());
  for (size_t i = 0; i < digits.size(); ++i)
    for (size_t j = 0; j < rhs.digits.size(); ++j)
      r.digits[i + j] += digits[i] * rhs.digits[j];
  for (size_t i = 0; i < r.digits.size(); i++)
    if (r.digits[i] >= base)
    {
      r.digits[i + 1] += r.digits[i] >> blen;
      r.digits[i] &= (base - 1);
    }

  __delete_zeroes(r);
  return *this = r;
}

big_integer& big_integer::operator /= (int const& rhs) 
{
  int carry = 0;
  for (int i = (int)digits.size() - 1; i >= 0; --i)
  {
    ll current = digits[i] + 1ll * carry * base;
    lldiv_t result = lldiv(current, rhs);
    digits[i] = result.quot;
    carry = result.rem;
  }

  __delete_zeroes(*this);
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

  int power = 0;
  while (r.digits.back() < (base >> 1))
    *this <<= 1, r <<= 1, ++power;

  int n = r.digits.size();
  int m = digits.size() - n;
  big_integer result = ZERO;
  for (int i = 0; i < m; i++)
    result.digits.push_back(0);
  result.digits[m] = 0;
  if (*this >= (r << (m * blen)))
  {
    result.digits[m] = 1;
    *this -= (r << (m * blen));
  }
  for (int j = m - 1; j >= 0; j--)
  {
    ll quot = (digits[n + j] * base + digits[n + j - 1]) / r.digits[n - 1];
    result.digits[j] = std::min(quot, (ll)base - 1);
    *this -= (r << (j * blen)) * result.digits[j];
    while (sign == -1)
    {
      --result.digits[j];
      *this += (r << (j * blen));
    }
  }

  result.sign = need_sign;
  __delete_zeroes(result);
  return *this = result;
}

int big_integer::operator %= (int const& rhs) 
{
  int carry = 0;
  for (int i = (int)digits.size() - 1; i >= 0; --i)
  {
    ll current = digits[i] + 1ll * carry * base;
    lldiv_t result = lldiv(current, rhs);
    digits[i] = result.quot;
    carry = result.rem;
  }

  __delete_zeroes(*this);
  return carry;
}

big_integer& big_integer::operator %= (big_integer const& rhs) 
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
    return *this;

  int power = 0;
  while (r.digits.back() < (base >> 1))
    *this <<= 1, r <<= 1, ++power;

  int n = r.digits.size();
  int m = digits.size() - n;
  big_integer result = ZERO;
  for (int i = 0; i < m; i++)
    result.digits.push_back(0);
  result.digits[m] = 0;
  if (*this >= (r << (m * blen)))
  {
    result.digits[m] = 1;
    *this -= (r << (m * blen));
  }
  for (int j = m - 1; j >= 0; j--)
  {
    ll quot = (digits[n + j] * base + digits[n + j - 1]) / r.digits[n - 1];
    result.digits[j] = std::min(quot, (ll)base - 1);
    *this -= (r << (j * blen)) * result.digits[j];
    while (sign == -1)
    {
      --result.digits[j];
      *this += (r << (j * blen));
    }
  }

  *this >>= power;
  sign = need_sign;
  __delete_zeroes(*this);
  return *this;
}

/* Binary operators (&=, |=, ^=) */

big_integer& big_integer::operator &= (big_integer const& rhs)
{
  if (!sign || !rhs.sign)
    return *this = ZERO;

  big_integer r = big_integer(rhs);
  while (digits.size() < r.digits.size())
    digits.push_back(0);
  while (digits.size() > r.digits.size())
    r.digits.push_back(0);

  std::cout << *this << '\n';
  std::cout << tilda(*this) << '\n';
  if (sign == -1)
    *this = (tilda(*this))++;
  std::cout << *this << '\n';
  if (r.sign == -1)
    r = (tilda(r))++;

  for (size_t i = 0; i < digits.size(); ++i)
    digits[i] &= r.digits[i];
  if (digits.back() >= (base >> 1))
    *this = tilda((*this)--);

  __delete_zeroes(*this);
  return *this;
}

big_integer& big_integer::operator |= (big_integer const& rhs)
{
  sign = (sign == -1 || rhs.sign == -1) ? -1 : 1;

  size_t size = std::max(digits.size(), rhs.digits.size());
  for (size_t i = 0; i < size; ++i)
  {
    if (i == digits.size())
      digits.push_back(0);
    int rdigit = (i < rhs.digits.size() ? rhs.digits[i] : 0);
    digits[i] |= rdigit;
  }

  __delete_zeroes(*this);
  return *this;
}

big_integer& big_integer::operator ^= (big_integer const& rhs)
{
  sign = ((sign == -1 && rhs.sign != -1) || (sign != -1 && rhs.sign == -1)) ? -1 : 1;

  size_t size = std::max(digits.size(), rhs.digits.size());
  for (size_t i = 0; i < size; ++i)
  {
    if (i == digits.size())
      digits.push_back(0);
    int rdigit = (i < rhs.digits.size() ? rhs.digits[i] : 0);
    digits[i] ^= rdigit;
  }

  __delete_zeroes(*this);
  return *this;
}

/* Shifts (<<=, >>=) */

big_integer& big_integer::operator <<= (int rhs)
{
  if (rhs < 0)
    throw std::runtime_error("Cannot shift to negative value");

  div_t result = div(rhs, blen);
  int carry = 0;
  for (size_t i = 0; i < digits.size() || carry; ++i)
  {
    if (i == digits.size())
      digits.push_back(0);
    ll current = (digits[i] << result.rem) + carry;
    digits[i] = current & (base - 1);
    carry = current >> blen;
  }

  int new_size = digits.size() + result.quot;
  digits.resize(new_size);
  for (int i = new_size - 1; i >= result.quot; --i)
    digits[i] = digits[i - result.quot];
  for (int i = result.quot - 1; i >= 0; --i)
    digits[i] = 0;

  __delete_zeroes(*this);
  return *this;
}

big_integer& big_integer::operator >>= (int rhs)
{
  if (rhs < 0)
    throw std::runtime_error("Cannot shift to negative value");

  div_t result = div(rhs, blen);

  int new_size = digits.size() - result.quot;
  for (size_t i = result.quot; i < digits.size(); ++i)
    digits[i - result.quot] = digits[i];
  for (size_t i = digits.size() - result.quot; i < digits.size(); ++i)
    digits[i] = 0;
  digits.resize(new_size);

  int carry = 0;
  for (int i = (int)digits.size() - 1; i >= 0; --i)
  {
    ll current = (digits[i] >> result.rem) + (carry << (blen - result.rem));
    carry = digits[i] - ((digits[i] >> result.rem) << result.rem);
    digits[i] = current & (base - 1);
  }
  
  __delete_zeroes(*this);
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
  return tilda(r);
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

big_integer operator * (big_integer a, int const& b)
{
  return a *= b;
}

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

int operator % (big_integer a, int const& b)
{
  return a %= b;
}

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
  while (b.sign)
  {
    int last_digit = b % 10;
    number += char('0' + last_digit);
    b /= 10;
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