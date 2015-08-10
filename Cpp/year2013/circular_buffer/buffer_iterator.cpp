#include "buffer.h"

buffer::iterator::iterator() 
{
  this->now = 0;
}

buffer::iterator::iterator(int now) 
{
  this->now = now;
}

int& buffer::iterator::operator * () const 
{
  return this->now->value;
}

buffer::iterator& buffer::iterator::operator ++ () 
{
  this->now = this->now->next;
  return *this;    
}

buffer::iterator buffer::iterator::operator ++ (int) 
{
  iterator res = *this;
  this->now = this->now->next;
  return res;
}

buffer::iterator& buffer::iterator::operator -- () 
{
  this->now = this->now->prev;
  return *this; 
}

buffer::iterator buffer::iterator::operator -- (int) 
{
  iterator res = *this;
  this->now = this->now->prev;
  return res;
}

bool buffer::iterator::operator == (const buffer::iterator &it) const 
{
  return this->now == it.now;
}

bool buffer::iterator::operator != (const buffer::iterator &it) const
{
  return this->now != it.now;
}
