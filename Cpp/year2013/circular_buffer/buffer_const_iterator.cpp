#include "buffer.h"

buffer::const_iterator::const_iterator() 
{
  this->now = 0;
}

buffer::const_iterator::const_iterator(node *now) 
{
  this->now = now;
}

int const& buffer::const_iterator::operator * () const
{
  return this->now->value;
}

buffer::const_iterator& buffer::const_iterator::operator ++ ()
{
  this->now = this->now->next;
  return *this;    
}

buffer::const_iterator buffer::const_iterator::operator ++ (int) 
{
  const_iterator res = *this;
  this->now = this->now->next;
  return res;
}

buffer::const_iterator& buffer::const_iterator::operator -- () 
{
  this->now = this->now->prev;
  return *this; 
}

buffer::const_iterator buffer::const_iterator::operator -- (int) 
{
  const_iterator res = *this;
  this->now = this->now->prev;
  return res;
}

bool buffer::const_iterator::operator == (const buffer::const_iterator &other) const {
  return this->now == other.now;
}

bool buffer::const_iterator::operator != (const buffer::const_iterator &other) const {
  return this->now != other.now;
}
