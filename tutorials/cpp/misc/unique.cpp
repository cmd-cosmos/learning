#include <iostream>
#include <memory>

int main(void) {
    auto  p = std::make_unique<int>(100);
    std::cout << *p << "\n";

    // move ownership in case of unique ptrs
    auto p2 = std::move(p);
    std::cout << *p2 << "\n";

    return EXIT_SUCCESS;
}