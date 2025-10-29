#include <stdio.h>
#include <windows.h>

int main()
{
    HANDLE hReadPipe, hWritePipe;
    SECURITY_ATTRIBUTES sec_attr = {
        sizeof(SECURITY_ATTRIBUTES),
        NULL,
        TRUE // child inherits
    };

    // parent writes to hWritePipe
    // child reads from hReadPipe
    WINBOOL pipeCreationFlag = CreatePipe(&hReadPipe, &hWritePipe, &sec_attr, 0);

    if (!pipeCreationFlag)
    {
        printf("failed to create pipe\n");
        return 1;
    }

    STARTUPINFO si;         // for the parent
    PROCESS_INFORMATION pi; // for the child
    ZeroMemory(&si, sizeof(si)); // init both structs with 0 to avoid garbage vals
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // child reads from hReadPipe
    si.hStdInput = hReadPipe;
    // child writes to console
    si.hStdOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    // inform windows of handles to choose
    si.dwFlags |= STARTF_USESTDHANDLES;

    // launching child
    char* childProg = "child.exe";
    if (!CreateProcess(
        childProg, NULL, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi))
        {
            printf("failed to create child process.\n");
        }
    
    int num = 7;
    DWORD written; // number of bytes written successfully
    WriteFile(hWritePipe, &num, sizeof(num), &written, NULL);
    printf("parent wrote num: %d to child\n", num);

    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    CloseHandle(hReadPipe);
    CloseHandle(hWritePipe);

    return 0;
}