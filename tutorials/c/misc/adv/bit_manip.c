#include <stdio.h>

#define READ     (1 << 0)
#define WRITE    (1 << 1)
#define EXEC     (1 << 2)

int main(void)
{
    int permissions = READ | WRITE;

    if (permissions & READ) printf("Read permission - TRUE\n");
    if (permissions & WRITE) printf("Write permission - TRUE\n");
    if (!(permissions & EXEC)) printf("Exec permission - FALSE\n");

    return 0;
}
