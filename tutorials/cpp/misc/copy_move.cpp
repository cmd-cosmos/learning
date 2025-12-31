#include <iostream>
#include <vector>

struct Box{
    std::vector<int> data;

    Box() : data(1'000'000, 21) {}

    Box(const Box&) {
        std::cout << "copy\n";
    }

    Box(Box&&) noexcept {
        std::cout << "move\n";
    }
};

int main(void)
{
    return EXIT_SUCCESS;
}
