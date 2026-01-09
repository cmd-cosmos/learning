#include <iostream>
#include <cstdint>

int main(void)
{
    // const type x = val; --> x cannot be modified at any point in the program
    const uint64_t a = 200;

    // cannot modify val via ref in case of const ref
    int val = 100;
    const int& valRef = val;

    // ptr to a const int
    uint32_t v1 = 110;
    uint32_t v2 = 120;
    const uint32_t* p1 = &v1;
    // *p1 = 1000; not allowed
    p1 = &v2; // allowed operation --> ptr can change ref to diff vals of same type

    // const ptr to int
    uint32_t* const p2 = &v1; // val of v1 can be modified via ptr deref
    *p2 = 1515;
    // p2 = &v2; --> reseting ref not allowed
    
    // const ptr to const int
    const uint32_t* const ptr3 = &v1;
    // *ptr3 = 1919; --> not allowewd
    // ptr3 = &v2; --> not allowewd
    

    return EXIT_SUCCESS;
}