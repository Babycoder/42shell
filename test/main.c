#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>




int     main()
{
    int fd = open("file.txt", O_WRONLY | O_CREAT, 0777);
    if (fd == -1)
        return 1;
    dup2(fd, STDOUT_FILENO);
    write(1, "Hello\n", 6);
    return(0);
}