#include "my_vector.h"

my_vector::my_vector() 
{
  msk = 1;
  links = 0;
}

my_vector::my_vector(int size) 
{
  links = 0;
  if (size <= 1) 
  {
    msk = 1 + size * 2;
  }
  else 
  {
    vs = new vector<uint>(size);
    links = (uint)new uint(1);
    msk = 0;
  }
}

my_vector::my_vector(my_vector const& other) 
{
  if (other.msk) 
  {
    msk = other.msk;
    links = other.links;
  }
  else 
  {
    vs = other.vs;
    ++(*(int*)other.links);
    links = other.links;
    msk = 0;
  }
}

my_vector::~my_vector() 
{
  if (msk) 
  {
    //delete links;
  }
  else 
  {
    --(*(int*)links);
    if (*(int*)links == 0) 
    {
      delete (int*)links;
      delete vs;
    }
  }
}

void my_vector::make_own_copy() 
{
  if (msk)
    return;
  if ((*(int*)links) > 1) 
  {
    --(*(int*)links);
    links = (uint)new uint(1);
    vs = new vector<uint>(*vs);
  }
}

void my_vector::init() 
{
  if (!msk)
    return;
  vs = new vector<uint>();
  if (msk & 2)
    (*vs).push_back(links);
  links = (uint)new uint(1);
  msk = 0;
}


void my_vector::push_back(uint item) 
{
  if (msk == 1) 
  {
    links = item;
    msk |= 2;
  }
  else 
  {
    make_own_copy();
    init();
    (*vs).push_back(item);
  }
} 

void my_vector::pop_back() 
{
  if (msk) 
  {
    msk = 1;
    return;
  }
  make_own_copy();
  (*vs).pop_back();
}

void my_vector::resize(int size) 
{
  make_own_copy();
  init();
  (*vs).resize(size);
}

void my_vector::clear() 
{
  resize(0);
}

int my_vector::size() const 
{
  if (msk)
    return (msk & 2) > 0;
  return (*vs).size();
} 

uint const& my_vector::operator [] (int i) const 
{
  if (msk)
    return links;
  return (*vs)[i];
}

uint& my_vector::operator [] (int i) 
{
  if (msk)
    return links;
  make_own_copy();
  return (*vs)[i];
}

my_vector& my_vector::operator = (my_vector const& other) 
{
  make_own_copy();
  if (other.msk) 
  {
    if (msk) 
    {
      msk = other.msk;
      links = other.links;
    }
    else 
    {
      (*vs).clear();
      if (other.msk > 1)
      (*vs).push_back(other.links);
    }
  }
  else 
  {
    if (!msk) 
    {
      --(*(int*)links);
      if (*(int*)links == 0) 
      {
        delete vs;
        delete (int*)links;
      }
    }
    else 
    {
      msk = 0;
      //delete links;
    }
    vs = other.vs;
    links = other.links;
    ++(*(int*)links);
  }
  return *this;
}

uint const& my_vector::back() const 
{
  if (msk)
    return links;
  return (*vs).back();
}

bool operator == (my_vector const& a, my_vector const& b) 
{
  if (!a.msk && !b.msk)
    return *(a.vs) == *(b.vs);
  if (a.msk && b.msk)
    return a.msk == b.msk && a.links == b.links;
  if (a.msk && !b.msk) 
  {
    if (bool(a.msk & 2) != (*b.vs).size())
      return false;
    if (bool(a.msk & 2) == 0)
      return true;
    return a.links == (*b.vs)[0];
  }
  if (b.msk && !a.msk) 
  {
    if (bool(b.msk & 2) != (*a.vs).size())
      return false;
    if (bool(b.msk & 2) == 0)
      return true;
    return b.links == (*a.vs)[0];
  }
  return false;
}

void reverse(my_vector& a) 
{
  if (a.msk)
    return;
  a.make_own_copy();
  reverse((*a.vs).begin(), (*a.vs).end());
}
