#include <vector>
#include <cassert>
 
using namespace std;
 
vector < double > genTest(int testId) {
    assert(testId == 1);
    vector < double > data{
                0, 2,    2, 1,
                1, 0,    2, 2,
 
                1, 3,    3, 3,
                2, 3,    2, 4,
 
                3, 0,    4, 0,
                3, 2,    4, 1,

				1, 1,    3, 3,
				2, 2,    2, 2
    };
    return data;
}
