#include <iostream>
#include <stdexcept>

int divide(int a, int b) {
    if (b == 0) {
        throw std::runtime_error("DIVISION BY 0");
    }
    return a / b;
}

int main(void) {
    try {
        std::cout << divide(100, 0) << "\n";
    } catch (const std::runtime_error& e) {
        std::cout << "ERROR: " << e.what() << "\n";
    }

    return EXIT_SUCCESS;
}