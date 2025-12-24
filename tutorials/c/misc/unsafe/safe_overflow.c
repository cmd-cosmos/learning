// control flow hijack prevented by the stack canaries

#include <stdio.h>
#include <string.h>

void vulnerable(const char* inp)
{
    char buffer[16];
    // attempt to overflow the buffer
    strcpy(buffer, inp);
}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        puts("String Input Required as an argument.");
        return 1;
    }
    vulnerable(argv[1]);
    puts("Inp saved to buffer. No overflow detected\n");

    return 0;
}

