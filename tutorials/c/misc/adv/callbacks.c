// function pointers and callbacks object less mini event system

#include <stdio.h>

// defining a function pointer type
typedef void (*handler_t)(int);

void even(int x)
{
    printf("even: %d\n", x);
}
void odd(int x)
{
    printf("odd: %d\n", x);
}

void dispatch(int x, handler_t even, handler_t odd)
{
    (x % 2 == 0 ? even : odd)(x);
}

int main(void)
{
    for (int i = 0; i < 6; i++)
    {
        dispatch(i, even, odd);
    }

    return 0;
}