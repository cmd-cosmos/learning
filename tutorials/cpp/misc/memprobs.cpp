// dangling ptrs and mem leaks

#include <iostream>

void leak()
{
    int* p = new int(100); // p points to int with val 100 on the heap
} // out of scope but no delete of the ptr --> mem leak

int main()
{
    int* p = new int(100);
    delete p;

    *p = 1000; // undefined behavior -> dangling ptr --> deref ptr after freeing mem

    return 0;
}