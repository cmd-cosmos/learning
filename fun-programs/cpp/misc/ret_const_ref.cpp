#include <iostream>

struct Config
{
    int data = 42;
};

const Config& getConfig() {
    static Config c;
    return c;
}

int main(void) {
    std::cout << getConfig().data << "\n";

    return EXIT_SUCCESS;
}