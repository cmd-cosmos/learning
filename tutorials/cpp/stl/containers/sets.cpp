#include <iostream>
#include <set>

int main(void)
{
    std::set<int> test = {1,1,1,2,2,3,3,4,5,6,6,2,2,2,2,2,2,1,1,1,1,1,6};

    test.insert(10);
    test.insert(10);
    test.insert(20);
    test.insert(11);

    std::cout << "set size: " << test.size() << std::endl;
    std::cout << "set eles: ";

    for (int x : test) 
    {
        std::cout << x << " ";
    } std::cout << std::endl;

    return EXIT_SUCCESS;
}