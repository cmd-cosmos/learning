// type punning in cpp
// even though cpp is strongly typed --> we can work around types 

#include <iostream>
#include <string>

struct Entity
// empty struct ---> at least 1 byte
{
    int x, y;
};

int main()
{
    int a = 10;
    double val = a; // it works by implicit conversion  ---> we do get a 50
    std::cout << val << std::endl;
    // OUTPUT - 10
    // what happens under the hood ---> double val = (double)a
    // this copies the val to a double size mem locn instead of expanding on pre-existing memory alloc

    //######### Unsafe practice
    // type punning ---> this expands the mem assigned for ints to be able to fit a double type --> so any unitialized mem will be included when the pointer is deref.
    // so 4 extra bytes that could potentially hold some garbage val will be included in the assignment as no new loc assigned but the preexisting assignment expanded
    // now the pointer points to 8 bytes starting from 0th byte of a which was initially only assigned 4 bytes
    double garbage = *(double*)&a; // cast a 4 byte mem addr to a 8 byte address in place and deref ---> so the int a was assigned 4 bytes but now we are asking for a cast to a pointer to a double var -- which req 8 bytes so it expands the pre existing alloc.
    std::cout << garbage << std::endl;
    //OUTPUT -  2.97079e-313

    Entity e = { 5,8 };
    int x = e.x;
    // we can also use type punning
    int* position = (int *)&e;
    int y = *(int*)((char*)&e + 4);
    std::cout << y << std::endl;

    return 0;
}