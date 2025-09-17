// how to make memory read only in C
// memory permissions manipulations
// virtual memory ---> pages for memory allocation
// make a page or multiple pages read only in order to implement read-only behavior
// usual page size = 4096 bytes --->  = 2^12 and multiples of 4096 bytes are other page sizes
// when malloc called, pointer is stored on the page but could be in the middle of the page or at some random spot
// p1: 000001AB0455F890 <--- returned pointer, last 12 bits(890 in this case) of the address tell us where we are on the page, if they are 0 then we know we are at the start of the page.
// create page aligned memory allocs instead of calc. how many bytes to move to reach the beginning of the page

#include <stdio.h>
#include <signal.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);

    // windows equivalent for POSIX specific sysconf command
    DWORD pagesize = sysInfo.dwPageSize;
    printf("pagesize = %lu bytes\n", pagesize); 

    int buffersize = 2 * pagesize;

    char* p1 = malloc(sizeof(char) * 50);
    printf("p1: %p\n", p1);

    // allocates 2 pages of memory
    void* ptr = _aligned_malloc(buffersize, pagesize);
    if(!ptr)
    {
        perror("allign_malloc failure");
        return 1;
    }
    printf("ptr --> %p", ptr); //ptr --> 00000123BFAF6000 <--- 12 of the trailing bits are 000 which means we have allocated at the beginning of the page
    free(ptr);
    return 0;
}
