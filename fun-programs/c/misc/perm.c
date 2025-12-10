#include <stdio.h>

#define EXECUTE 1 << 0 // 0000 0001
#define WRITE   1 << 1 // 0000 0010
#define READ    1 << 2 // 0000 0100

int main()
{
    unsigned char permissions = 0; // 0000 0000

    printf("==> Granting READ WRITE Permissions.\n");

    permissions |= READ | WRITE;
    printf("==> Permissions Set: %d\n", permissions); // 0000 0110 <-- execute denied at this stage

    if (permissions & EXECUTE) 
    {
        printf("==> Granted: EXECUTE\n");
    }
    else
    {
        printf("====> Denied: EXECUTE\n");
    }

    printf("\n** REVOKE WRITE PERMISSIONS(y/n): ");
    char revoke_inp;
    scanf("%c", &revoke_inp);

    if (revoke_inp == 'y' || revoke_inp == 'Y')
    {
        printf("==> Revoking WRITE PERMISSION.\n");
        permissions &= ~WRITE;
        printf("==> Revoked WRITE\n====> Permissions Set: %d\n", permissions);
    }
    else
    {
        printf("==> WRITE PERMISSION --> UNTOGGLED.\n");
        printf("==> Permissions Set: %d\n", permissions);
    }

    return 0;
}
