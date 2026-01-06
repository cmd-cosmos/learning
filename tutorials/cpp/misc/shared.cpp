#include <iostream>
#include <memory>

int main(void) {
    auto p1 = std::make_shared<int>(100);
    auto p2 = p1;

    std::cout << p1.use_count() << "\n";
    std::cout << *p1 << "\n";
    std::cout << *p2 << "\n";

    return EXIT_SUCCESS;
}