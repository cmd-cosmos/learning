#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // if (argc < 2) {
    //     fprintf(stderr, "Usage: %s <message>\n", argv[0]);
    //     return 1;
    // }
    while (1)
    {
        sleep(1);
        printf("%s\n", argv[1]);
    }
    

    return 0;
}
