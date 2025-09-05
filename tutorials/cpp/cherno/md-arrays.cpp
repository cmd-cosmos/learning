// multi dimensional arrays 
// 2D arrays ---> array of arrays ---> buffer of pointers pointing to arrays

#include <iostream>
#include <string>

int main()
{
    // array of ints
    int* arr = new int[50]; // allocate space for 50 integers --> 200 bytes alloc

    // array of int pointers ---> 50 pointers can then be set to point to 50 different arrays
    int** buffer = new int*[50]; // returns a pointer to an array that can store 50 integer pointers ---> 200 bytes

    // 2D array
    for(int i = 0; i < 50; i++)
    {
        buffer[i] = new int[50]; // all pointers in the pointer buffer will point to a unique array ---> 200 bytes each
    }

    return 0;
}