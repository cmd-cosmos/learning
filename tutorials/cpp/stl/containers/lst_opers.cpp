#include <iostream>
#include <cstdlib>
#include <list>

void printList(const std::list<int>& lst)
{
    for (int x : lst)
    {
        std::cout << x << " <-> ";
    } std::cout << std::endl;
}

int main(void)
{
    std::list<int> lst = {1,2,3,4};
    printList(lst);

    lst.push_back(10);
    std::cout << "after push back: \n";
    printList(lst);

    lst.push_front(-1);
    lst.push_front(-2);
    std::cout << "after push front: \n";
    printList(lst);

    auto iter = lst.begin();
    std::advance(iter, 2); // move iterator to the 3rd ele / idx 2

    //insert 99 at curr iter position
    lst.insert(iter, 99);
    std::cout << "after iterator based insertion: \n";
    printList(lst);


    return EXIT_SUCCESS;
}