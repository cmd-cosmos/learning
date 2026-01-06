#include <iostream>
#include <memory>

int main(void) {
    auto  p = std::make_unique<int>(100);
    std::cout << *p << "\n";

    return EXIT_SUCCESS;
}