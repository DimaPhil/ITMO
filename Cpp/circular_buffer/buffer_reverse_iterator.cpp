#include "buffer.h"

buffer::reverse_iterator::reverse_iterator() 
{
  this->now = 0;
}

buffer::reverse_iterator::reverse_iterator(node *now) 
{
  this->now = now;
}

int& buffer::reverse_iterator::operator * () const 
{                       
  reverse_iterator it = this->now;
  ++it;
  return it.now->value;
}

buffer::reverse_iterator& buffer::reverse_iterator::operator ++ () 
{
  this->now = this->now->prev;
  return *this;    
}

buffer::reverse_iterator buffer::reverse_iterator::operator ++ (int) 
{
  reverse_iterator res = *this;
  this->now = this->now->prev;
  return res;
}

buffer::reverse_iterator& buffer::reverse_iterator::operator -- () 
{
  this->now = this->now->next;
  return *this; 
}

buffer::reverse_iterator buffer::reverse_iterator::operator -- (int) 
{
  reverse_iterator res = *this;
  this->now = this->now->next;
  return res;
}

bool buffer::reverse_iterator::operator == (const buffer::reverse_iterator &it) const 
{
  return this->now == it.now;
}

bool buffer::reverse_iterator::operator != (const buffer::reverse_iterator &it) const
{
  return this->now != it.now;
}
