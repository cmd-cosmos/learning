// 1 word = 4 bytes
// cpu can read a complete int in 1 access if int stored in a mem loc divisible by 4
// unaligned access can cause a perf hit and on some older systems a hardware fault

#include <stdio.h>
#include <stdlib.h>

struct NON_UNIFORM
{
    // expected size = 6 bytes
    char c; // 1 byte
    int x;  // 4 byte
    char d; // 1 byte
};

struct UNIFORM
{
    // expected size = 6 bytes
    // output size 8 bytes --> only 2 bytes of padding added to the char storage
    int x;
    char c;
    char d;
};

int main(int argc, char* argv[])
{
    int sz = sizeof(struct NON_UNIFORM);
    printf("size of non uniform struct: %zu bytes\n", sz);
    // output: size of non uniform struct: 12

    int s_uni = sizeof(struct UNIFORM);
    printf("size of uniform struct: %zu bytes\n", s_uni);
    return 0;
}

