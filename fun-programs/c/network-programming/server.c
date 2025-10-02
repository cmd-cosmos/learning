/*
Reference 
 https://learn.microsoft.com/en-us/windows/win32/winsock/initializing-winsock
*/
#include <stdio.h>
#include <winsock2.h>
#include <windows.h>

int main()
{
    WSADATA wsadata;

    WSAStartup(MAKEWORD(2,2), &wsadata);
    
    // if (res != 0)
    // {
    //     printf("WSAStartup failed: %d\n", res);
    //     return 1;
    // }
    // printf("WSAStartup success\n");

    // // SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
    
    SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = 0;
    addr.sin_port = htons(8080);

    listen(s, 10);

    SOCKET client = accept(s, 0, 0);
    char request[256] = {0};

    return 0;
}