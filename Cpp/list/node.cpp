#include "list.h"

list::node::node() 
{
  this->value = 0;
  this->next = this->prev = this;
}

list::node::node(int value) 
{
  this->value = value;
  this->next = this->prev = this;
}

list::node::node(int value, list::node *prev, list::node *next) 
{
  this->value = value;
  this->prev = prev;
  this->next = next;
}

list::node::node(const list::node &other) {
  this->value = other.value;
  this->next = other.next;
  this->prev = other.prev;
}

list::node::~node() {
  //delete *this; 
}

list::node& list::node::operator = (const node &other) {
  this->value = other.value;
  this->next = other.next;
  this->prev = other.prev;   
  return *this; 
}
