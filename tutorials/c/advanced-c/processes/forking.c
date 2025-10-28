#include <stdio.h>
#include <windows.h>
// ref = https://learn.microsoft.com/en-us/windows/win32/procthread/creating-processes

int main()
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);

    ZeroMemory(&pi, sizeof(pi));

    char* progPath = "C:\\Windows\\System32\\notepad.exe";

    if (CreateProcess(
        progPath, // path to notepad 
        NULL, // CLI args
        NULL, // security info --> null = default
        NULL, // thread security
        FALSE,// resource sharing with parent
        0,    // creation flags --> 0 = normal proc
        NULL, // use parents env vars
        NULL, // use parents curr dir
        &si,  // ptr to startup info
        &pi   // ptr to process info
    ))
    {
        printf("process created\n");
        printf("launching process\n");

        WaitForSingleObject(pi.hProcess, INFINITE); // wait for child proc completion

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    else
    {
        printf("CreateProcess failure, error: %lu\n", GetLastError());
    }


}