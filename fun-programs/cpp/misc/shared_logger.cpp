#include <iostream>
#include <memory>

struct Logger {
    void log(const char* msg)
    {
        std::cout << msg << "\n";
    }
};

int main(void) {
    auto logger = std::make_shared<Logger>();

    auto network = logger;
    auto db = logger;

    network->log("network stable.");
    db->log("db connected.");

    return EXIT_SUCCESS;
}