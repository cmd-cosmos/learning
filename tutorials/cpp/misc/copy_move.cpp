#include <iostream>
#include <vector>

struct Box{
    std::vector<int> data;

    Box() : data(1'000'000, 21) {
        std::cout << "constructing obj\n";
    }

    Box(const Box&) {
        std::cout << "copy obj\n";
    }

    Box(Box&&) noexcept {
        std::cout << "move obj\n";
    }
};

int main(void)
{
    Box a;
    Box b = a;
    Box c = std::move(a);

    return EXIT_SUCCESS;
}
