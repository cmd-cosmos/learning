// traditionally single return for a function
// workarounds: return pairs, tuples or vectors
// we can also use pass by reference to get multiple updates using a single function
// pass by pointer can also be employed to essentially have a function update multiple vals.

#include <iostream>
#include <vector>
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

std::pair<int, std::string> PairWork(int a)
{
    return {a, "Joker"};
}

std::vector<int> ReturnVector()
{
    std::vector<int> nums;
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    return nums;
}

void PassByRef(int a, int b, int& sum, int& diff)
{
    sum = a+b;  // these alliases will auto update 
    diff = a-b;
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

    std::vector<int> result = ReturnVector();
    for (int val : result)
    {
        std::cout << val << std::endl;
    }

    int x = 100;
    int y = 20;
    int sum;
    int diff;

    PassByRef(x,y, sum, diff);
    std::cout << sum << std::endl;
    std::cout << diff << std::endl;

    int res1;
    std::string res2;
    std::tie(res1, res2) = PairWork(5);
    std::cout << res1 << ' ' << res2;

    return 0;
}
