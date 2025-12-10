#include <stdio.h>

#define EXECUTE 1 << 0 // 0000 0001
#define WRITE   1 << 1 // 0000 0010
#define READ    1 << 2 // 0000 0100

int main()
{
    unsigned char permissions = 0; // 0000 0000

    printf("==> Granting Read Write Permissions.\n");

    permissions |= READ | WRITE;
    printf("==> Permissions Set: %d\n", permissions); // 0000 0110 <-- execute denied at this stage

    if (permissions & EXECUTE) 
    {
        printf("==> Granted: EXECUTE\n");
    }
    else
    {
        printf("==> Denied: EXECUTE\n");
    }

    return 0;
}
