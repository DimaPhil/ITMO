#ifndef MY_VECTOR_H
#define MY_VECTOR_H
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

typedef unsigned int uint;

struct my_vector {
public:          
  my_vector();
  my_vector(int size);
  my_vector(my_vector const& other);
  ~my_vector();
  void push_back(uint item);
  void pop_back();
  void resize(int size);
  void clear();
  
  size_t size() const;
  uint const& operator [] (int i) const;
  uint& operator [] (int i);

  my_vector& operator = (my_vector const& other);
  uint const& back() const;                          
  friend bool operator == (my_vector const& a, my_vector const& b);
  friend void reverse(my_vector& a);
    
  void make_own_copy();       
    
private:
  vector<uint>* vs;
  union Some 
  {
    uint links;
    uint* plinks;
  } s;
  char msk;
  void init();
};

bool operator == (my_vector const& a, my_vector const& b);
void reverse(my_vector& a);
#endif //MY_VECTOR_H
