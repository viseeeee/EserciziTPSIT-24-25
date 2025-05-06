#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int pid, p1p2[2];

    pid = fork();
    if (pid == 0)
    {
        close(p1p2[0]);
        close(1);
        dup(p1p2[1]);
        close(p1p2[1]);

        execl("/usr/bin/cat", "cat", argv[1], NULL);
    }

    pid = fork();
    if (pid == 0)
    {
        close(p1p2[1]);
        close(0);
        dup(p1p2[0]);
        close(p1p2[0]);

        execl("/usr/bin/cp", "cp", argv[1],argv[2], NULL);
    }

    execl("/usr/bin/cat", "cat", argv[2], NULL);

    close(p1p2[0]);
    close(p1p2[1]);

    wait(NULL);
    wait(NULL);
}