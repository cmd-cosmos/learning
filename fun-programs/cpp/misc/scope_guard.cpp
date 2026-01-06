#include <iostream>

struct Lock {
    Lock() {
        std::cout << "lock\n";
    }
    ~Lock() {
        std::cout << "unlock\n";
    }
};

int main(void) {
    {
        Lock l;
        std::cout << "working critical section\n";
    }
    return EXIT_SUCCESS;
}