#include <iostream>

void lval_ref(int& x) {
    std::cout << "lval ref: " << x << std::endl;
}

void rval_ref(int&& x) {
    std::cout << "rval ref: " << x << std::endl;
}

int main(void)
{
    int val = 19;

    lval_ref(val);
    rval_ref(21);

    int&& temp = 200;
    std::cout << "temp val = " << temp << std::endl;

    return EXIT_SUCCESS;
}