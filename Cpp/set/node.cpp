#include "set.h"

set::node::node() 
{
  this->value = 0;
  this->p = NULL;
  this->l = this->r = NULL;
}

set::node::node(int value) 
{
  this->value = value;
  this->p = NULL;
  this->l = this->r = NULL;
}

set::node::node(int value, set::node *l, set::node *r) {
  this->value = value;
  this->l = l;
  this->r = r;
  this->p = NULL;
}

set::node::node(const set::node &n) 
{
  this->value = n.value;
  this->l = n.l;
  this->r = n.r;
  this->p = n.p;
}

set::node::~node() 
{
}

set::node& set::node::operator = (const node &n) 
{
  this->value = n.value;
  this->l = n.l;
  this->r = n.r;
  this->p = n.p;
  return *this;
}
