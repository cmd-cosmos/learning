// traditionally single return for a function
// workarounds: return pairs and tuples

#include <iostream>
#include <utility>  // contains pair
#include <tuple>    // contains tuple 

// tuples ---> fixed number of values, different data types allowed

std::tuple<int, std::string> Get(int x)
// function that returns a tuple obj. essentailly more than 1 return from a function
{
    std::tuple<int, std::string> tup = {x,"Batman"};
    return tup;
}

std::tuple<int, std::string> TimeToLaunch(int a)
{
    std::tuple<int, std::string> tup = std::make_tuple(a, "seconds to launch"); 
    return tup;

}

std::ostream& operator<<(std::ostream& os, const std::tuple<int, std::string>& tup)
{
    os << std::get<0>(tup) << ' ' << std::get<1>(tup);
    return os;
}

int main()
{
    std::cout << Get(5) << std::endl;
    std::cout << TimeToLaunch(1500) << std::endl;

    return 0;
}
