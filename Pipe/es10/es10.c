#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        perror("Errore in argc");
        exit(1);
    }

    int p1p2[2], pid;

    pipe(p1p2);
    pid = fork();
    if (pid == 0)
    {
        close(1);
        close(p1p2[0]);
        dup(p1p2[1]);
        close(p1p2[1]);

        execl("/usr/bin/cat", "cat", argv[1], NULL);
    }

    pid = fork();
    if (pid == 0)
    {
        close(0);
        close(p1p2[1]);
        dup(p1p2[0]);
        close(p1p2[0]);

        execl("/usr/bin/sort", "sort", (char *)0);
    }

    execl("/usr/bin/cat", "cat", argv[1], NULL);

    close(p1p2[1]);
    close(p1p2[0]);
    wait(NULL);
    wait(NULL);
    return 0;
}