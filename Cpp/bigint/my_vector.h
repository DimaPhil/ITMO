#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <vector>
#include <algorithm>

typedef unsigned int uint;

struct my_vector 
{
  public:          
    my_vector();
    my_vector(int size);
    my_vector(my_vector const& other);
    ~my_vector();
    void clear();
    void push_back(uint item);
    void pop_back();
    void resize(int size);
    
    int size() const;
    uint const& operator [] (int i) const;
    uint& operator [] (int i);

    my_vector& operator = (my_vector const& other);

    uint const& back() const;                          
    friend bool operator == (my_vector const& a, my_vector const& b);
    friend void reverse(my_vector& a);
    
    void make_copy();       
    
  private:
    std::vector <uint>* vect;
    uint* n;
    char msk;
    void init_ptns();
};

bool operator == (my_vector const& a, my_vector const& b);
void reverse(my_vector& a);

#endif
