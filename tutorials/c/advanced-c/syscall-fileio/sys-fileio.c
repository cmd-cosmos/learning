// using system calls to perform file operations
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    // open is an interface to trigger a sys call trap
    int fd = open("file.txt", O_RDONLY);

    // file descriptor table --> int mapped to open files --> 0,1,2 --> stdin, stdout, stderr
    // 3 --> file.txt
    if (fd < 0)
    {
        perror("open");
        return 1;
    } printf("FD: %d\n", fd);

    char buffer[30];

    ssize_t n = read(fd, buffer, sizeof(buffer) - 1);
    // read --> kernel looks up fd in the table and loads the data from kernel space to user space which is the buffer array

    if (n < 0)
    {
        perror("read");
        return 1;
    }

    buffer[n] = '\0';

    // use the write sys call to write to fd 1 --> file descriptor maps to the stdout directly
    write(1, buffer, n);

    close(fd);
    
    return 0;
}

