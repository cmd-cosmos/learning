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

        void fillUnique(int idx, T val)
        {
            array[idx] = val;
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
    for (int i = 0; i < 10; i++)
    {
        std::cout << intArray.at(i) << std::endl;
    }
    std::cout << strArray.at(3) << std::endl;
    std::cout << strArray.at(4) << std::endl;
    std::cout << strArray.at(3) << std::endl;

    Array<std::string> characters;
    characters.fillUnique(0,"Batman");
    characters.fillUnique(1,"Joker");
    characters.fillUnique(2,"Alfred");
    characters.fillUnique(3,"Nighwing");
    characters.fillUnique(4,"Robin");
    characters.fillUnique(5,"Bruce");
    characters.fillUnique(6,"2-Face");
    characters.fillUnique(7,"Riddler");
    characters.fillUnique(8,"Cobblepot");
    characters.fillUnique(9,"Scarecrow");
    for(int i = 0; i < 10; i++)
    {
        std::cout << characters.at(i) << std::endl;
    }
    
    Array<int> nums;
    for (int i = 0; i < 10; i++)
    {
        nums.fillUnique(i,i);
    } 
    for (int j = 0; j < 10; j++)
    {
        std::cout << nums.at(j) << std::endl;
    }
    return 0;
}
