#include "list.h"

list::const_iterator::const_iterator() 
{
  this->now = 0;
}

list::const_iterator::const_iterator(node *now) 
{
  this->now = now;
}

int const& list::const_iterator::operator * () const
{
  return this->now->value;
}

list::const_iterator& list::const_iterator::operator ++ ()
{
  this->now = this->now->next;
  return *this;    
}

list::const_iterator list::const_iterator::operator ++ (int) 
{
  const_iterator res = *this;
  this->now = this->now->next;
  return res;
}

list::const_iterator& list::const_iterator::operator -- () 
{
  this->now = this->now->prev;
  return *this; 
}

list::const_iterator list::const_iterator::operator -- (int) 
{
  const_iterator res = *this;
  this->now = this->now->prev;
  return res;
}

bool list::const_iterator::operator == (const list::const_iterator &other) const {
  return this->now == other.now;
}

bool list::const_iterator::operator != (const list::const_iterator &other) const {
  return this->now != other.now;
}
