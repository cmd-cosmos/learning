// traditionally single return for a function
// workarounds: return pairs and tuples

#include <iostream>
#include <utility>  // contains pair
#include <tuple>    // contains tuple 

// tuples ---> fixed number of values, different data types allowed

std::tuple<int, std::string> Get(int x)
{
    std::tuple<int, std::string> tup = {x,"Batman"};
    return tup;
}

std::ostream& operator<<(std::ostream& os, std::tuple<int, std::string>& tup)
{
    os << std::get<0>(tup) << ',' << std::get<1>(tup);
    return os;
};

int main()
{
    std::cout << Get(5);
    return 0;
}
