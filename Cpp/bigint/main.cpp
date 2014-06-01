#include "big_integer.cpp"

int main() 
{
  try 
  {           
    /*big_integer a(-2), b(3);
    a &= b;
    int A = -2;
    int B = 3;
    A &= B;
    std::cout << a << " " << A << " " << (~(unsigned int)2) << '\n';*/
    big_integer a(-23), b(5);
    a %= b;
    std::cout << a << '\n';
  }                     
  catch (std::runtime_error& e) 
  {
    std::cout << e.what() << '\n';
  }
  return 0;
}

