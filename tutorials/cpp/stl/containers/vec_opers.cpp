#include <iostream>
#include <vector>

void printVec(auto& vec)
{
    std::cout << "vector: ";
    for (int x : vec)
    {
        std::cout << x << " ";
    } std::cout << std::endl;
}

int main(void)
{
    std::vector<int> vec = {1,2,3};
    
    vec.push_back(4);
    vec.insert(vec.begin() + 1, 10); // insert 10 at index 1 --> vec.begin returns 0th idx

    std::cout << "insert 10 at idx 1: \n";
    printVec(vec);

    vec.erase(vec.begin() + 2); // remove element at idx 2 as in the 3rd element
    std::cout << "erased val at idx 2: \n";
    printVec(vec);

    return EXIT_SUCCESS;
}