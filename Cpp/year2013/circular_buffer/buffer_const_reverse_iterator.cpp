#include "buffer.h"

buffer::const_reverse_iterator::const_reverse_iterator() 
{
  this->now = 0;
}

buffer::const_reverse_iterator::const_reverse_iterator(node *now) 
{
  this->now = now;
}

int const& buffer::const_reverse_iterator::operator * () const
{
  const_reverse_iterator it = this->now;
  ++it;
  return it.now->value;
}

buffer::const_reverse_iterator& buffer::const_reverse_iterator::operator ++ ()
{
  this->now = this->now->prev;
  return *this;    
}

buffer::const_reverse_iterator buffer::const_reverse_iterator::operator ++ (int) 
{
  const_reverse_iterator res = *this;
  this->now = this->now->prev;
  return res;
}

buffer::const_reverse_iterator& buffer::const_reverse_iterator::operator -- () 
{
  this->now = this->now->next;
  return *this; 
}

buffer::const_reverse_iterator buffer::const_reverse_iterator::operator -- (int) 
{
  const_reverse_iterator res = *this;
  this->now = this->now->next;
  return res;
}

bool buffer::const_reverse_iterator::operator == (const buffer::const_reverse_iterator &other) const {
  return this->now == other.now;
}

bool buffer::const_reverse_iterator::operator != (const buffer::const_reverse_iterator &other) const {
  return this->now != other.now;
}
