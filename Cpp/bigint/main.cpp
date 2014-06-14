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
    /*for (int it = 0; it < 1000; ++it)
    {
      big_integer accumulator = 1;
      vector <int> numbers;
      for (int i = 0; i < 1000; ++i) 
      {
        int x = rand() % 100 - 50;
        while (!x)
          x = rand() % 100 - 50;
        accumulator *= x;
        numbers.push_back(x);
      }
      random_shuffle(numbers.begin(), numbers.end());
      for (int i = 1; i < (int)numbers.size(); ++i)
        accumulator /= numbers[i];
      //cout << accumulator << "\n" << numbers[0] << "\n\n";
      if (accumulator != numbers[0])
        cout << "Something went wrong :(\n";
    }*/
    cout << double(clock()) / CLOCKS_PER_SEC;
  }                     
  catch (std::runtime_error& e) 
  {
    std::cout << e.what() << '\n';
  }
  return 0;
}

