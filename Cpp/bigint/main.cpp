#include "big_integer.cpp"
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
  try 
  {           
    big_integer a = 2;
    big_integer b = 3;
    cout << a + b << '\n';
  }                     
  catch (std::runtime_error& e) 
  {
    std::cout << e.what() << '\n';
  }
  return 0;
}

