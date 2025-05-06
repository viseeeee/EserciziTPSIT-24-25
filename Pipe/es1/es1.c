/*Scrivere un programma concorrente che realizzi il seguente comando:

cat costituzione.txt | more
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>


int main(int argc,char ** argv){
    if(argc!=2){
        perror("Errore in argc");
        exit(1);
    }

    int p1p2[2],pid;
    pipe(p1p2);

    pid=fork();

    if (pid==0)
    {
        close(1);
        close(p1p2[0]);
        dup(p1p2[1]);
        close(p1p2[1]);
        execl("/usr/bin/cat","cat",argv[1],NULL);
        return -1;
    }

    close(p1p2[1]);
    pid=fork();
    if (pid==0)
    {
        close(0);
        close(p1p2[1]);
        dup(p1p2[0]);
        close(p1p2[0]);
        execl("/usr/bin/more","more",(char *)0);
        return -1;
    }

    close(p1p2[0]);
    close(p1p2[1]);
    wait(&pid);
    wait(&pid);    
}
