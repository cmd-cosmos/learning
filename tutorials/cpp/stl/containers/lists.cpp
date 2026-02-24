#include <iostream>
#include <list>

int main(void)
{
    std::list<int> lst = {1,2,3};

    lst.push_back(20);
    lst.push_front(100);

    std::cout << "elements: ";

    for (int x : lst) {
        std::cout << x << " ";
    } std::cout << std::endl;

    return EXIT_SUCCESS;
}