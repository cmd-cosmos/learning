#include <iostream>
#include <memory>

std::unique_ptr<int> createConfig()
{
    // return ownership
    // ensure exclusive ownership
    return std::make_unique<int>(100);
}

int main(void)
{
    std::unique_ptr<int> config = createConfig();
    std::cout << *config << "\n";

    return EXIT_SUCCESS;
}