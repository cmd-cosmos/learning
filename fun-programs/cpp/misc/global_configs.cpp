#include <iostream>

struct Config {
    int port;
    int timeout;
};

const Config& config() {
    static Config cfg{8000, 30};
    return cfg;
}

int main(void)
{
    std::cout << "------ CONFIG ------\n";
    std::cout << "PORT    | " << config().port << "\n";
    std::cout << "TIMEOUT | " << config().timeout << "\n";

    return EXIT_SUCCESS;
}