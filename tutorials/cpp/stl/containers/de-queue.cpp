#include <iostream>
#include <deque>

int main(void)
{
    std::deque<int> dq = {1,2,3};

    dq.push_back(21);
    dq.push_front(-11);

    std::cout << "deque eles: ";

    for(int x : dq)
    {
        std::cout << x << " ";
    } std::cout << std::endl;

    return EXIT_SUCCESS;
}
