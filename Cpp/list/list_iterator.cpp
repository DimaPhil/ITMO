#include "list.h"

list::iterator::iterator() 
{
  this->now = 0;
}

list::iterator::iterator(node *now) 
{
  this->now = now;
}

int& list::iterator::operator * () const 
{
  return this->now->value;
}

list::iterator& list::iterator::operator ++ () 
{
  this->now = this->now->next;
  return *this;    
}

list::iterator list::iterator::operator ++ (int) 
{
  iterator res = *this;
  this->now = this->now->next;
  return res;
}

list::iterator& list::iterator::operator -- () 
{
  this->now = this->now->prev;
  return *this; 
}

list::iterator list::iterator::operator -- (int) 
{
  iterator res = *this;
  this->now = this->now->prev;
  return res;
}

bool list::iterator::operator == (const list::iterator &it) const 
{
  return this->now == a.now;
}

bool list::iterator::operator != (const list::iterator &it) const
 {
  return this->now != a.now;
}
