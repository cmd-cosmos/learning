#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    FILE* f = fopen(argv[1], "r");

    if (!f)
    {
        fprintf(stderr, "Error - %d - %s", errno, strerror(errno));
        exit(errno);
    }

    char buffer[24];
    fread(buffer, 1, 23, f); // read 8 chars of 1 byte each from f file into the buffer
    printf("buffer: \n%s\n", buffer);
    fclose(f);

    return 0;

}