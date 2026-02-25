#include <iostream>
#include <tuple>
#include <utility>
#include <string>

void printPair(const std::pair<int, std::string>& test)
{
    std::cout << test.first << " <-> " << test.second << std::endl;
}

int main()
{
    std::pair<int, std::string> test = {1,"Batman"};

    printPair(test);
    return 0;
}