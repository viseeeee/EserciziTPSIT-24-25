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
    int pid, p1p2[2], fd;
    char stringa[50];
    pipe(p1p2);

    pid = fork();
    if (pid == 0)
    {
        // processo 1
        close(p1p2[0]);
        while (1)
        {
        printf("Inserisci una stringa\n");
        scanf("%s", stringa);
        if (strcmp(stringa, "esci")==0)
        {
            printf("Programma terminato\n");
            exit(0);
        }
        strcat(stringa,"\n");
        write(p1p2[1],stringa,strlen(stringa));
        }
        close(p1p2[1]);
        
    }

    pid = fork();
    if (pid == 0)
    {
        // processo 2

        close(0);
        close(p1p2[1]);
        dup(p1p2[0]);
        close(p1p2[0]);

        open(argv[1],O_CREAT | O_WRONLY, 077);     
        execl("/usr/bin/sort","sort",(char *)0);
    }

    close(p1p2[1]);
    close(p1p2[0]);

    wait(NULL);
    wait(NULL);
}