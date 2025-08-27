// auto ---> works out what the type of the var is by itself.
// helps in making cpp slighly weakly typed language.
// api changes could result in runtime bugs and errors
// less readable as intellisense dependence
// very useful for simpler use cases
// some use cases: when we want to loop through STL containers or use iterators.
// can also be used for super long custom types 
// also used for trailing return types
// also for func. returns after cpp 14

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

std::string Test()
{
    return "Hello";
}

char* Problem()
{
    return "Hello";
}

int main()
{
    int a = 5;
    auto b = a; // will deduce b to be an int.
    auto c = 10; 
    auto d = c; // both c and d are deduced to be int type.
    auto str = "Batman";
    auto ch = 'a';
    auto p = &a; // deduce p as an int*

    auto test = Test(); // deduced to be std::string
    // problems begin here ---> if return type changed to char* and auto used instead of std::string then we cannot use string methods with a char* return type although both are same in some terms.
    test.size(); // since function returned std::string test is deduced to std::string so we can use string lib functions

    auto prob = Problem(); // prob is deduced to be a char*
    // so we cannot use string library functions despite it being a string
    
    // prob.size(); // cannot do this as prob is a char*


    return 0;
}