#include <iostream>
#include <chrono>
#include <thread>

int main(void)
{
    char spinner[] = {'|', '/', '-', '\\'};
    for (int i = 0; i < 200; i++)
    {
        std::cout << "\r" << spinner[i % 4] << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "\nSpinner...\n";

    return EXIT_SUCCESS;
}