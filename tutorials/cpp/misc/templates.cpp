// function templates ---> help to overload functions

#include <iostream>
#include <string>
#include <vector>

// a function that returns the later datatype result 
// in this case return double and take in int, double or double, double or any order
template<typename T,typename R> 
R add(T a, R b)
{
    return (a + b);
}

int main()
{
    // same function overloaded to different types using function templates
    
    std::cout << add(3.144444, 90) << std::endl; // add float to int and return int
    std::cout << add(86, 3.141567) << std::endl; // same function to add int, float and return a float
    std::cout << add('s', 2.12) << std::endl; // s = 115 in ascii so add 2.12 ---> 117.12 as output
    return 0;
}

