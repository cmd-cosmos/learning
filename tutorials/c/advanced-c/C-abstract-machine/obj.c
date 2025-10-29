#include <stdio.h>
#include <stdlib.h>

void increment()
{
    static int x = 0; // retains data after frame collapse
    int y = 0;        // data deleted when frame collapses

    printf("static_duration x: %d, auto_duration y: %d\n", x++,y++);
}

int main(int argc, char* argv[])
{
    int x = 42; // x = obj of type int --> lives until main scope ends --> auto storage duration, may be stored in a register.

    // register int x = 20; 
    // will store the obj in a register as we anticipate extreme usage --> can be ignored by the compiler based on optimization policies

    for (int i = 0; i < 10; i++)
    {
        increment();
    }
    

    return 0;
}

