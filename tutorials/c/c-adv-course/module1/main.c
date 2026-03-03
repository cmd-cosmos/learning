#include <stdio.h>
#include <stdalign.h>
#include <stdatomic.h>

_Thread_local int tl_var = 10;

int main()
{
    _Atomic int x = 21;
    atomic_fetch_add(&x, 4);

    printf("atomic val: %d\n", x);
    printf("thread local: %d\n", tl_var);

    return 0;
}
