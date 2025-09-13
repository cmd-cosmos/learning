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



int main()
{
    return 0;
}
