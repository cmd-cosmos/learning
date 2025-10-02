/*
Reference 
 https://learn.microsoft.com/en-us/windows/win32/winsock/initializing-winsock
*/
#include <stdio.h>
#include <stdlib.h>
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
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(8080);
    bind(s, &addr, sizeof(addr));

    listen(s, 10);

    // client socket
    SOCKET client = accept(s, 0, 0);
    char request[1024] = {0};
    recv(client, request, 1024, 0);

    FILE* f = fopen("index.html", "r");
    if (f)
    {
        send(client, "HTTP/1.0 200 OK\r\nContent-Type: text/html\r\n\r\n", 44, 0);
        char buffer[1024] = {0};
        int n;
        while ((n = fread(buffer, 1, sizeof(buffer), f)) > 0)
        {
            send(client, buffer, n, 0);
        }
        fclose(f);
    }
    closesocket(client);
    closesocket(s);
    WSACleanup();
    return 0;
}