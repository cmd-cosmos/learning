// standard arrays ---> class in the STL
// similar to a regular c type array
// on a surface level ---> works in a similar way as a c style array
// one advantage ---> since it is a class there are methods that track size
//                    we can use STL algorithms as it is an STL class
// automated bounds violation checks based on debug or release build
// both std array and c style array are on the stack and work in a similar way

#include <iostream>
#include <string>
#include <array>
#include <algorithm>

int main()
{
    std::array<int, 10> buffer;
    buffer[0] = 1;
    buffer.size();
    buffer.begin();

    return 0;
}

