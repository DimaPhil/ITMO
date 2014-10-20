#include "buffer.h"

buffer::node::node() 
{
  this->value = 0;
  this->next = this->prev = 0;
}

buffer::node::node(int value) 
{
  this->value = value;
  this->next = this->prev = 0;
}

buffer::node::node(int value, int prev, int next) 
{
  this->value = value;
  this->prev = prev;
  this->next = next;
}

buffer::node::node(const buffer::node &other) {
  this->value = other.value;
  this->next = other.next;
  this->prev = other.prev;
}

buffer::node::~node() {
  //delete *this; 
}

buffer::node& buffer::node::operator = (const node &other) {
  this->value = other.value;
  this->next = other.next;
  this->prev = other.prev;   
  return *this; 
}
