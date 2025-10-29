#include <stdio.h>
#include <windows.h>

int main()
{
    int recNum;
    DWORD readBytes;
    char* line = "I am Batman";

    if (ReadFile(GetStdHandle(STD_INPUT_HANDLE), &recNum, sizeof(recNum), &readBytes, NULL))
    {
        printf("child received: num: %d\n", recNum);
        printf("child says: %s\n", line);
    }
    else
    {
        printf("child failed to read from parent\n");
    }

    return 0;
}