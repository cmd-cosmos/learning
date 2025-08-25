// templates: allow to write generic code that works with any dat a type.
// template <typename a, typename b>

#include <iostream>
#include <string>
#include <utility>

template <typename Temp> Temp ReturnMax(Temp x, Temp y) {
    return (x > y) ? x : y;
}

int main()
{
    std::cout << ReturnMax<int>(1,2) << std::endl;
    return 0;
}

