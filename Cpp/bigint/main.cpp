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
    big_integer a("10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    big_integer b(                                                     "100000000000000000000000000000000000000");
    big_integer c("100000000000000000000000000000000000000000000000000000");
    std::cout << "Number: ";
    for (int i = 0; i < (int)a.digits.size(); i++)
      std::cout << a.digits[i] << ' ';
    std::cout << '\n';
    a /= b;
    std::cout << a << '\n';
  }                     
  catch (std::runtime_error& e) 
  {
    std::cout << e.what() << '\n';
  }
  return 0;
}

