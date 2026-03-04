#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <string.h>

int main()
{
    int fd = _open("test.txt", _O_CREAT | _O_WRONLY | _O_TEXT, 0644);

    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    char msg[] = "I am batman\r\n";
    _write(fd, msg, strlen(msg));
    _close(fd);

    return 0;
}
