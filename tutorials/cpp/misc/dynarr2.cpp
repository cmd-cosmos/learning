#include <iostream>

int main()
{
    int n;
    std::cout << "enter size of arr: ";
    std::cin >> n;

    int* arr = new int[n];

    for(int i = 0; i < n; i++)
    {
        arr[i] = i * 10;
    }

    for(int i = 0; i < n; i++)
    {
        std::cout << arr[i] << "\n";
    }

    delete[] arr;
    arr = nullptr;

    return 0;
}