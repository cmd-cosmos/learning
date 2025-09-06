// sorting algorithm ---> std::sort
// works by taking in an iterator
// O(nlogn)

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

int main()
{
    std::vector<int> vec = {3,2,7,1,9,0};
    
    // ascending order --> if no predicate provided/ if no function provided
    std::sort(vec.begin(), vec.end());

    for (int val : vec)
    {
        std::cout << val << std::endl;
    }
        
    // descending --> using the functional library to use a pre defined function
    std::sort(vec.begin(), vec.end(), std::greater<int>());

    for (int val : vec)
    {
        std::cout << val << std::endl;
    }
    
    // ascending --> using lambdas to sort in a descending order
    std::sort(vec.begin(), vec.end(), [](int a, int b)
    {
        return a < b; // bool 1 if a < b --> a in the front --> ascending
    });

    for (int val : vec)
    {
        std::cout << val << std::endl;
    }

    return 0;
}
