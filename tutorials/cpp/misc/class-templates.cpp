// class templates --> similar to function templates but for class overloads
// https://www.youtube.com/watch?v=mQqzP9EWu58

#include <iostream>
#include <string>
#include <vector>

class intArray
// main problem is if we want a string array, we need to duplicate the class and use strings in place of ints
// class templates help override type behavior.
{
    public:
        int array[10];

        void fill(int val)
        {
            for (int i = 0; i < 10; i++)
            {
                array[i] = val;
            }
        }

        int& at(int idx)
        {
            return array[idx];
        }
};

template<typename T>
class Array
{
    public:
        T array[10];

        void fill(T val)
        {
            for (int i = 0; i < 10; i++)
            {
                array[i] = val;
            }
        }

        T& at(int idx)
        {
            return array[idx];
        }

};

int main()
{
    // the Array class produces homogenous and consistent arrays
    // only 1 value populated throughout the array
    Array<std::string> strArray;
    strArray.fill("Batman");
    Array<int> intArray;
    intArray.fill(10);
    std::cout << strArray.at(3) << std::endl;
    std::cout << strArray.at(4) << std::endl;
    std::cout << strArray.at(3) << std::endl;
    std::cout << intArray.at(1) << std::endl;
    std::cout << intArray.at(9) << std::endl;
    std::cout << intArray.at(0) << std::endl;
    return 0;
}
