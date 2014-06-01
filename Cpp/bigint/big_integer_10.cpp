#include "big_integer.h"

#include <algorithm>
#include <iostream>
#include <cctype>
#include <cstring>
#include <stdexcept>

#define pb push_back

/* Constructors */

big_integer::big_integer() 
{
  sign = 0;
  memset(digits, 0, sizeof(digits));
}

big_integer::big_integer(big_integer const& other) 
{
  sign = other.sign;
  for (int i = 0; i < maxLen; ++i)
    digits[i] = other.digits[i];
}

big_integer::big_integer(int a) 
{
  sign = a > 0 ? 1 : (!a ? 0 : -1);
  a = abs(a);
  memset(digits, 0, sizeof(digits));
  int power = 1, p = 0;
  while (a) 
  {
    digits[p] += power * (a % 10);
    a /= 10;
    if ((power *= 10) == base)
      power = 1, ++p;
  }
}

big_integer::big_integer(std::string const& str) 
{
  sign = 0;
  memset(digits, 0, sizeof(digits));
  int start_index = 0;
  if (str.size() > 0 && str[0] == '-')
    start_index = 1, sign = -1;
  if (start_index == (int)str.size())
    throw std::runtime_error("Invalid string in input");

  bool is_zero = true;
  int power = 1, p = 0;
  for (int i = (int)str.size() - 1; i >= start_index; --i) 
  {
    if (!isdigit(str[i]))
      throw std::runtime_error("Invalid string in input");

    if (str[i] != '0')
      is_zero = false;
    digits[p] += power * (str[i] - '0');
    if ((power *= 10) == base)
      power = 1, ++p;
  }
  if (!is_zero && !sign)
    sign = 1;
}

/* Destructor */

big_integer::~big_integer() 
{
  sign = 0;
  delete [] digits;
}

/* Operators =, +=, -=, *=, /=, %= */

big_integer& big_integer::operator = (big_integer const& other) 
{
  sign = other.sign;
  for (int i = 0; i < maxLen; ++i)
    digits[i] = other.digits[i];
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
    for (int i = 0; i < maxLen; ++i)
      if ((digits[i] += rhs.digits[i]) >= base)
        ++digits[i + 1], digits[i] -= base;
  } 
  else 
  {
    sign = rhs.sign;
    if ((*this) == rhs) 
      return *this = big_integer(0);
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
    return *this = big_integer(0);    
  if (sign == 1)
  {
    if ((*this) < rhs)
      *this = -(rhs - (*this));
    else
    {
      for (int i = 0; i < maxLen; ++i)
        if ((digits[i] -= rhs.digits[i]) < 0)
          --digits[i + 1], digits[i] += base;
    }
  }
  else
  {
    if ((*this) > rhs)
      *this = (-rhs) + (*this);
    else
    {
      for (int i = 0; i < maxLen; ++i)
        if ((digits[i] -= rhs.digits[i]) < 0)
          --digits[i + 1], digits[i] += base;
    }
  }
  return *this;
}

big_integer& big_integer::operator *= (big_integer const& rhs) 
{
  if (!sign || !rhs.sign)
    return *this = big_integer(0);
  big_integer r = big_integer(0);
  r.sign = sign != rhs.sign ? -1 : 1;
  for (int i = 0; i < maxLen; ++i)
    for (int j = 0; j < maxLen - i; ++j)
      r.digits[i + j] += digits[i] * rhs.digits[j];
  for (int i = 0; i < maxLen; i++)
    if (r.digits[i] >= base)
      r.digits[i + 1] += r.digits[i] / base, r.digits[i] %= base;
  return *this = r;
}

big_integer& big_integer::operator /= (big_integer const& rhs) 
{
  return *this;
}

big_integer& big_integer::operator %= (big_integer const& rhs) 
{
  return *this;
}

/* Binary operators (&=, |=, ^=) */

big_integer& big_integer::operator &= (big_integer const& rhs)
{
  for (int i = 0; i < maxLen; ++i)
    digits[i] &= rhs.digits[i];
  return *this;
}

big_integer& big_integer::operator |= (big_integer const& rhs)
{
  for (int i = 0; i < maxLen; ++i)
    digits[i] |= rhs.digits[i];
  return *this;
}

big_integer& big_integer::operator ^= (big_integer const& rhs)
{
  for (int i = 0; i < maxLen; ++i)
    digits[i] ^= rhs.digits[i];
  return *this;
}

/* Shifts (<<=, >>=) */

big_integer& big_integer::operator <<= (int rhs)
{
  return *this;
}

big_integer& big_integer::operator >>= (int rhs)
{
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
  for (int i = 0; i < maxLen; ++i)
    r.digits[i] = ~r.digits[i];
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

big_integer operator * (big_integer a, big_integer const& b) 
{
  return a *= b;
}

big_integer operator / (big_integer a, big_integer const& b) 
{
  return a /= b;
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

/* Операторы сравнения (==, !=, <, <=, >, >=)*/

bool operator == (big_integer const& a, big_integer const& b)
{
  if (a.sign != b.sign)
    return false;
  for (int i = 0; i < maxLen; ++i)
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
  for (int i = maxLen - 1; i >= 0; --i)
    if (a.digits[i] != b.digits[i])
      return a.sign == 1 ? a.digits[i] < b.digits[i] : a.digits[i] > b.digits[i];
  return false;
}

bool operator <= (big_integer const& a, big_integer const& b)
{
  if (a.sign != b.sign)
    return a.sign < b.sign;
  for (int i = maxLen - 1; i >= 0; --i)
    if (a.digits[i] != b.digits[i])
      return a.sign == 1 ? a.digits[i] < b.digits[i] : a.digits[i] > b.digits[i];
  return false;
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

std::string to_string(int a, bool need_zeroes) 
{
  std::string number = "";
  while (a)
    number += char(a % 10 + '0'), a /= 10;
  if (need_zeroes) 
  {
    while ((int)number.size() < blen)
      number += '0';
  }
  reverse(number.begin(), number.end());
  return number;
}

std::string to_string(big_integer const& a) 
{
  if (!a.sign)
    return "0";
  std::string number = "";
  if ((int)a.sign == -1)
    number += '-';
  int i = maxLen - 1;
  while (!a.digits[i])
    --i;
  number += to_string(a.digits[i--], 0);
  while (i >= 0)
    number += to_string(a.digits[i--], 1);
  return number;
}

/* Operator << to std::cout */

std::ostream& operator << (std::ostream& s, big_integer const& a) 
{
  return s << to_string(a);
}

int main() 
{
  try 
  {
    big_integer a = big_integer("-87087987");
    big_integer b = big_integer("-78361831");
    a *= b;
    std::cout << a << '\n';
  } 
  catch (std::runtime_error& e) 
  {
    std::cout << e.what() << '\n';
  }
  return 0;
}

