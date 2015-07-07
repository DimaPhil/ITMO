#include "list.h"

list::const_reverse_iterator::const_reverse_iterator() 
{
  this->now = 0;
}

list::const_reverse_iterator::const_reverse_iterator(node *now) 
{
  this->now = now;
}

int const& list::const_reverse_iterator::operator * () const
{
  const_reverse_iterator it = this->now;
  ++it;
  return it.now->value;
}

list::const_reverse_iterator& list::const_reverse_iterator::operator ++ ()
{
  this->now = this->now->prev;
  return *this;    
}

list::const_reverse_iterator list::const_reverse_iterator::operator ++ (int) 
{
  const_reverse_iterator res = *this;
  this->now = this->now->prev;
  return res;
}

list::const_reverse_iterator& list::const_reverse_iterator::operator -- () 
{
  this->now = this->now->next;
  return *this; 
}

list::const_reverse_iterator list::const_reverse_iterator::operator -- (int) 
{
  const_reverse_iterator res = *this;
  this->now = this->now->next;
  return res;
}

bool list::const_reverse_iterator::operator == (const list::const_reverse_iterator &other) const {
  return this->now == other.now;
}

bool list::const_reverse_iterator::operator != (const list::const_reverse_iterator &other) const {
  return this->now != other.now;
}
