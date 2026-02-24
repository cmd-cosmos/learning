#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> nums = {1,2,3,4};

    // iter using range based for loop
    for(int x : nums)
    {
        std::cout << x << " ";
    } std::cout << std::endl;

    // using iterator
    for(std::vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter)
    {
        std::cout << *iter << " ";
    } std::cout << std::endl;

    std::vector<std::string> test;

    test.push_back("A");
    test.push_back("B");
    test.push_back("C");
    test.push_back("D");

    std::cout << "test[1] = " << test[1] << std::endl;
    std::cout << "test[3] = " << test[3] << std::endl;

    return EXIT_SUCCESS;
}