// multi dimensional arrays 
// 2D arrays ---> array of arrays ---> buffer of pointers pointing to arrays
// major issues ---> memory fragmantation --> each cell in the main array contains a pointer to individual int arrays which means there are high chances of cache misses.

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

    // 3D array
    int*** arr3d = new int**[50];
    for(int i = 0; i < 50; i++)
    {
        // in the main array --> 50 int pointers
        arr3d[i] = new int*[50];
        for(int j = 0; j < 50; j++)
        {
            int** ptr = arr3d[i];
            ptr[j] = new int[50]; 
        }
    }

    // after use we need to delete all memory by iteration and not just by deleting the main pointer ----> otherwise memory leak and dangling values
    // correct deletion logic.
    for (int i = 0; i < 50; i++)
    {
        // delete each individual array inside the main array
        delete[] buffer[i];
    }
    // deleting the main array 
    delete[] buffer;

    int** a2d = new int*[10];
    for (int i = 0; i < 10; i++)
    {
        // this assigns each pointer in the root array with individual arrays having 10 vals each
        // by the end total 100 ints can be added but in 10 different arrays pointed to by 10 pointers and could be at any position in memory
        // this would result in cache misses
        // instead if we assign all the 100 elements to a single memory --> program will be much faster and iterating would be contiguous.
        a2d[i] = new int[10];
    }
    // assignment to this a2d array will be super slow
    for(int x = 0; x < 10; x++)
    {
        for(int y = 0; y<10; y++)
        {
            a2d[x][y] = 1; // assign all vals a 1
        }
    }
    // alternate method to do this using a single array 
    int* clean_arr = new int[10*10];
    for(int x = 0; x < 10; x++)
    {
        for(int y = 0; y<10; y++)
        {
            clean_arr[x + y * 10] = 1; // assign all vals a 1
        }
    }

    return 0;
}