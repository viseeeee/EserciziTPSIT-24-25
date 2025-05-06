#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

/*Scrivere un programma concorrente che realizzi il seguente comando:

cat file.txt | wc 

il processo p2 deve rimandare l'output di wc al padre, il quale lo scriverà
su un file chiamato wc.txt

il nome del file "file.txt" deve essere passato come argomento in argv[1]*/


int main(int argc,char ** argv){
    if(argc != 2){
        perror("Errore in argc");
        exit(1);
    }

    int pid,p1p2[2],p2p0[2];
    pipe(p1p2);
    char buff;
    pid = fork();
    if (pid==0)
    {
        close(1);
        close(p1p2[0]);
        dup(p1p2[1]);
        close(p1p2[1]);
        execl("/usr/bin/cat","cat",argv[1],NULL);
        return -1;
    }

    pipe(p2p0);
    pid = fork();
    if (pid==0)
    {
        close(1);
        close(p2p0[0]);
        dup(p2p0[1]);
        close(p2p0[1]);
        
        close(0);
        close(p1p2[1]);
        dup(p1p2[0]);
        close(p1p2[0]);
        execl("/usr/bin/wc","wc",(char *)0);
        return -1;
    }

    close(p1p2[0]);
    close(p1p2[1]);
    close(p2p0[1]);

    int fd=open("wc.txt",O_WRONLY | O_CREAT,0777);
    while (read(p2p0[0],buff,1)>0)
    {
        write(fd,buff,1);
    }
    close(p1p2[0]);
    close(fd);
    wait(&pid);
    wait(&pid);
    return 0;
}