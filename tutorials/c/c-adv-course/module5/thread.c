#include <windows.h>
#include <stdio.h>

DWORD WINAPI func(LPVOID arg)
{
    printf("thread running\n");
    return 0;
}

int main()
{
    HANDLE thread = CreateThread(NULL, 0, func, NULL, 0, NULL);

    WaitForSingleObject(thread, INFINITE);
    CloseHandle(thread);

    return 0;
}