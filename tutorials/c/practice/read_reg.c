// inspect stack frame at runtime
#include <stdio.h>

void inspect_stack()
{
    int local = 123;

    void* rbp;
    void* rsp;

    asm("movq %%rbp, %0" : "=r"(rbp));
    asm("movq %%rsp, %0" : "=r"(rsp));

    printf("RBP: %p\n", rbp);
    printf("RSP: %p\n", rsp);
    printf("local var address: %p\n", &local);
}

int main()
{
    inspect_stack();
    return 0;
}