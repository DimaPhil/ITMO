#include "list.h"

list::reverse_iterator::reverse_iterator() 
{
  this->now = 0;
}

list::reverse_iterator::reverse_iterator(node *now) 
{
  this->now = now;
}

int& list::reverse_iterator::operator * () const 
{                       
  reverse_iterator it = this->now;
  it--;
  return it.now->value;
}

list::reverse_iterator& list::reverse_iterator::operator ++ () 
{
  this->now = this->now->prev;
  return *this;    
}

list::reverse_iterator list::reverse_iterator::operator ++ (int) 
{
  reverse_iterator res = *this;
  this->now = this->now->prev;
  return res;
}

list::reverse_iterator& list::reverse_iterator::operator -- () 
{
  this->now = this->now->next;
  return *this; 
}

list::reverse_iterator list::reverse_iterator::operator -- (int) 
{
  reverse_iterator res = *this;
  this->now = this->now->next;
  return res;
}

bool list::reverse_iterator::operator == (const list::reverse_iterator &it) const 
{
  return this->now == it.now;
}

bool list::reverse_iterator::operator != (const list::reverse_iterator &it) const
{
  return this->now != it.now;
}
