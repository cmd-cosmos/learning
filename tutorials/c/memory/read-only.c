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

    // using mmap equivalent to assign 2 pages and ensure they are read only and anonymous

    void *mmap_readwrite = VirtualAlloc(
        NULL,
        buffersize,
        MEM_COMMIT | MEM_RESERVE,
        PAGE_READWRITE              // allows to rewrite
    );

    void *mmap_read_only = VirtualAlloc(
        NULL,
        buffersize,
        MEM_COMMIT | MEM_RESERVE,
        PAGE_READONLY              // seg fault when memset used
    );

    printf("mmap_readwrite: %p\n", mmap_readwrite);
    printf("mmap_readonly: %p\n", mmap_read_only);

    printf("starting write operation...\n");
    for(int i = 0; i < buffersize; i++)
    {
        printf("%d (%p): writing...\n", i, ptr + i );
        ((char*)ptr)[i] = 42;
    }
    printf("writing complete on aligned alloc pages...\n");
    printf("started write on mmap readwrite page...\n");
    memset(mmap_readwrite, 100, buffersize);
    printf("write complete on read write pages\n");
    memset(mmap_read_only, 100, buffersize);

    VirtualFree(mmap_read_only, 0, MEM_RELEASE);
    VirtualFree(mmap_readwrite, 0, MEM_RELEASE);
    _aligned_free(ptr);
    free(p1);
    
    return 0;
}
