#include "set.h"

set::iterator::iterator() 
{
  this->cur = 0;
}

set::iterator::iterator(node *cur) 
{
  this->cur = cur;
}

int& set::iterator::operator * () const 
{
  return this->cur->value;
}

set::iterator& set::iterator::operator ++ () 
{
  if (this->cur->r != NULL)
  {
    this->cur = this->cur->r;
    while (this->cur->l != NULL)
      this->cur = this->cur->l;
    return *this;
  }

  int need_value = this->cur->value;
  while (this->cur != end())
  {
    if (this->cur->value > need_value)
      return *this;
    this->cur = this->cur->p;
  }
  return *this;
}

set::iterator set::iterator::operator ++ (int) 
{
  iterator res = *this;
  ++res;
  return res;
}

set::iterator& set::iterator::operator -- () 
{
  if (this->cur->l != NULL)
  {
    this->cur = this->cur->l;
    while (this->cur->r != NULL)
      this->cur = this->cur->r;
    return *this;
  }

  int need_value = this->cur->value;
  while (this->cur != end())
  {
    if (this->cur->value < need_value)
      return *this;
    this->cur = this->cur->p;
  }
  return *this; 
}

set::iterator set::iterator::operator -- (int) 
{
  iterator res = *this;
  --res;
  return res;
}

bool set::iterator::operator == (const set::iterator &a) const 
{
  return this->cur == a.cur;
}

bool set::iterator::operator != (const set::iterator &a) const 
{
  return this->cur != a.cur;
}
