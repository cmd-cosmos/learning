#include <stdio.h>

int glob_uninitialized;      // BSS segment
int glob_intiialized = 10;   // data segment
const int global_const = 99; // internal linkage - read only data

static int static_uninitialized; // BSS internal
static int static_initialized;   // BSS internal

void func_static(void)
{
    static int local_static; // BSS
    local_static++;
    printf("function local static: %d\n", local_static);
}

void normal_func(void)
{
    int local_not_static = 100; // stack --> so dies with end of func scope
    printf("local not static: %d\n", local_not_static);
}

int main(void)
{
    func_static();
    func_static();
    normal_func();
    return 0;
}

/*
uppercase letters = external linkage
lowercase letters = internal linkage

0000000000000000 b .bss
0000000000000000 d .data
0000000000000000 p .pdata
0000000000000000 r .rdata
0000000000000000 r .rdata$zzz
0000000000000000 t .text
0000000000000000 r .xdata
                 U __main
0000000000000000 T func_static
0000000000000000 D glob_intiialized
0000000000000000 B glob_uninitialized
0000000000000000 R global_const
000000000000000c b local_static.0
000000000000005f T main
0000000000000035 T normal_func
                 U printf
0000000000000008 b static_initialized
0000000000000004 b static_uninitialized

*/