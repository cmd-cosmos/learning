// stack smashing by overflowing a string

#include <stdio.h>
#include <string.h>

void unsafeCopy()
{
    char buffer[8];
    strcpy(buffer, "I am Batman, no I am Iron Man");
    printf("%s\n", buffer);
    /*
        stack_smash.c: In function 'unsafeCopy':
    stack_smash.c:9:5: warning: '__builtin_memcpy' writing 30 bytes into a region of size 8 overflows the destination [-Wstringop-overflow=]
        9 |     strcpy(buffer, "I am Batman, no I am Iron Man");
        |     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    stack_smash.c:8:10: note: destination object 'buffer' of size 8
        8 |     char buffer[8];
    */
}

int main(int argc, char* argv[])
{
    unsafeCopy();
    return 0;
}
