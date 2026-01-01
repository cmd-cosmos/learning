#include <windows.h>
#include <stdio.h>

int main(void)
{
    // auto allocated 4 bytes on the stack
    int stack_var = 1;

    // allocate 32 bytes on the process heap
    void *heap_var = HeapAlloc(GetProcessHeap(), 0, 32);
    if (!heap_var) {
        return 1;
    }

    // reserving os mem by contacting windows kernel -> reserves address space
    // reserve 1 mem page
    void *os_mem   = VirtualAlloc(
        NULL,
        4096,
        MEM_COMMIT | MEM_RESERVE,
        PAGE_READWRITE
    );
    if (!os_mem) {
        HeapFree(GetProcessHeap(), 0, heap_var);
        return 1;
    }

    printf("stack mem addr : %p\n", (void*)&stack_var);
    printf("heap mem addr  : %p\n", heap_var);
    printf("os mem addr    : %p\n", os_mem);

    HeapFree(GetProcessHeap(), 0, heap_var);
    VirtualFree(os_mem, 0, MEM_RELEASE);

    return 0;
}
