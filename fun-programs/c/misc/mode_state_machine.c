#include <stdio.h>

typedef enum {
    INIT,    // 0
    ASCENT,  // 1
    CRUISE,  // 2
    LANDING, // 3
    SIZE     // 4
} flightStates;

int main(void)
{
    flightStates states = INIT;
    
    for (int i = 0; i < SIZE; i++)
    {
        switch(states)
        {
            case INIT:
                puts("Initialized Flight\n");
                states = ASCENT;
                break;
            case ASCENT:
                puts("Ascent Phase\n");
                states = CRUISE;
                break;
            case CRUISE:
                puts("Cruise Phase\n");
                states = LANDING;
                break;
            case LANDING:
                puts("Landing Phase\n");
                break;
        }
    }
    return 0;
}
