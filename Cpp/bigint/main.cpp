#include "big_integer.cpp"
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

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
    /*big_integer a("10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    big_integer b(                                                     "100000000000000000000000000000000000000");
    big_integer c("100000000000000000000000000000000000000000000000000000");
    a /= b;*/

    /*vector <int> v;
    srand(239017);
    for (int i = 0; i < 1000; i++) {
      big_integer accumulator = 1;
      for (int j = 0; j < 1000; j++) {
        int x = rand() % 100 - 50;
        while (!x)
          x = rand() % 100 - 50;
        v.push_back(x);
        accumulator *= x;
      }
      random_shuffle(v.begin(), v.end());
      for (size_t i = 1; i < v.size(); i++)
        accumulator /= v[i];
    } */
    big_integer a = big_integer("22");
    big_integer b = big_integer("3");
    /*for (size_t i = 0; i < a.digits.size(); i++)
      cout << a.digits[i] << " ";
    cout << '\n';
    for (size_t i = 0; i < b.digits.size(); i++)
      cout << b.digits[i] << " ";
    cout << '\n';*/
    cout << a << " ";
    cout << b << '\n';
    cout << a - b << '\n';
  }                     
  catch (std::runtime_error& e) 
  {
    std::cout << e.what() << '\n';
  }
  return 0;
}

