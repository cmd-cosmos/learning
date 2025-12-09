#include <iostream>

int main()
{
    unsigned char bits = 0b00001000;

    // bits >> 2 ===> 0000 0010 & 0000 0001 ===> 0000 0000  

    for (int i = 0; i < 8; i++)
    {
        std::cout << "bit " << i << ": " << ((bits >> i) & 1) << '\n';
    }
    // bit 7 is the MSB and bit 0 is the LSB

    bits = bits | (1 << 0); // set the first bit i.e bit 0
   
    std::cout << "\nAfter set bit 0: \n";
    for (int i = 0; i < 8; i++)
    {
        std::cout << "bit " << i << ": " << ((bits >> i) & 1) << '\n';
    }

    return EXIT_FAILURE;
}