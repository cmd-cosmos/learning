#include <iostream>
#include <array>    // cpp 11 std array

void Log(auto input)
{
    std::cout << input << '\n';
};

class Entity
{
public:
    int sample[5];
    Entity()
    {
        for (int i = 0; i < 5; i++)
        {
            sample[i] = 0;
        }
    }
};

int main()
{
    int array[5];
    array[0] = 100;
    array[4] = 500;
    std::cout << array[0] << '\n';
    std::cout << array << '\n';
    std::cout << &array[0] << '\n';

    for (int i=0; i < 5; i++)
    {
        array[i] = (100*i); // sets value at each index = 100 x idx
    }

    // for each loop to print an array.
    for(int num: array)
    {
        Log(num);
    }

    // pointer based view of arrays
    int sample[5];
    sample[0] = 50;
    // sample ---> int* ptr = sample <---- same thing because array name is a pointer to the 0th idx
    int* ptr = sample;
    Log(*(sample)); // should print 50 ---> 0th idx

    // assign the 4th index a value of 80 using ptr
    *(ptr+4) = 80; // deref the 4th index and assign a val of 80 ---> 4th idx
    Log(*(sample+4)); // should print 80

    // reason why we have to add 4 annd not 4x4 =16 bytes is beacause it internally knwos the type of the ptr which is int, but if we were using a char pointer for modifying an int arr then we would need to multiply it by  4
    *(int*)((char*)ptr + (8)) = 70; // deref the 2nd idx and assign the val of 70
    Log(*(sample+2)); // should print 70

    // creating an array on the heap
    int* heap_arr = new int[5];
    // the heap_arr will have a different lifetime in comparision to the arrays on stack seen before.
    delete[] heap_arr; // delete using the array operator. 

    Entity e;

    static const int size_arr = 5; // correct way to track size of an array in terms of number of elements it can hold.

    // using the std array from cpp 11
    std::array<int, 5> arr11;
    std::cout << "size for the std arr from cpp 11: " << arr11.size() << '\n';

    return 0;
}