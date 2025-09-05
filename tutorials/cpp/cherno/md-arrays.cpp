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

    return 0;
}