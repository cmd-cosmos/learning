// templates: allow to write generic code that works with any dat a type.
// template <typename a, typename b>
// templates are sort of like macros
// essentially the compiler writes the code for the program based on the rules given
// good use case would be a function that is used multiple times but with different data types.
// automates function overloads

#include <iostream>
#include <string>

template <typename Temp> Temp ReturnMax(Temp x, Temp y) {
    return (x > y) ? x : y;
}

// template<class T> ---> same as using typename
template<typename T>
void Print(T val)
// function restricted to printing integer values if int val used
// now the function is a template and is only created when it is called based on the template parameters
{
    std::cout << val << '\n';
}

template<int N>
class Array
// array for integers, size passed at compile time
// stack assigned array ---> size needs to be known at compile time
// templates are evaluated at compile time ---> good fit
{
    private:
        int m_Array[N];
    public:
        int GetSize() const
        {
            return N;
        }
};

template<typename T, int N> // template for an array on the stack which can hold N number of elements for a T datatype ---> homogeneous array.
class MultiTypeArray
{
    private:
        T m_MultiArray[N];
    public:
        int GetSize() const
        {
            return N;
        }
};

int main()
{
    Print(5);
    // when no typename sent as an arg ---> compiler deciphers the types              
    Print("Hello");
    Print<std::string>("Batman");   // use string as parameter to the typename arg to the template
    Print<int>(100);                // use int as parameter to the typename arg to the template

    std::cout << ReturnMax<int>(1,2) << std::endl;

    Array<5> arr; // replaces N with 5
    std::cout << arr.GetSize() << std::endl;

    MultiTypeArray<std::string, 10> arr2;
    std::cout << arr2.GetSize() << std::endl;
    
    return 0;
}

