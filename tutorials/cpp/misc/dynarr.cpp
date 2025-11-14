// dynamic alloc for array

#include <iostream>

int main()
{
    int size = 10;
    int* arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = i*10;
    }

    for (int j = 0; j < size; j++)
    {
        std::cout << arr[j] << std::endl;
    }

    delete[] arr;

    return 0;
}
