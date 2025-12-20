// using vars after freeing mem.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void safeUse()
{
    printf("executing safe routine:\n");
    int *p = malloc(sizeof(int));
    if (!p) return;

    *p = 1000;
    printf("%d\n", *p);

    free(p);
    p = NULL; // poisoning the malloc ptr
    printf("exiting safe routine\n");

}

void unsafe()
{
    printf("executing unsafe routine:\n");
    int *p = malloc(sizeof(int));
    *p = 1000;

    free(p);
    printf("%d\n", *p); // use after 
    // memory leak: -2038919296
    printf("exiting unsafe routine\n");
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("flags: --safe | --unsafe\n");
        return 1;
    }
    if (strcmp(argv[1], "--safe") == 0)
    {
        safeUse();
    }
    else if (strcmp(argv[1], "--unsafe") == 0)
    {
        unsafe();
    }
    else{
        printf("unknown arg: %s\n", argv[1]);
        printf("flag: --safe | --unsafe\n");
        return 1;
    }

    return 0;    
}

