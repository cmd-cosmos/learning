#include <iostream>
#include <vector>

int main(void)
{
    std::vector<int> nums = {1,2,3,4};

    for(int x : nums)
    {
        std::cout << x << " ";
    } std::cout << std::endl;

    // using iterator
    for(std::vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter)
    {
        std::cout << *iter << " ";
    } std::cout << std::endl;

    return EXIT_SUCCESS;
}