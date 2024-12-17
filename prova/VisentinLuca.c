#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int p1, p2, p3, p4, p5;
    int n;
    // entra dentro p1 che è il processo padre

    do
    {
        printf("P1:Inserisci un numero compreso tra 3 e 10:\n");
        scanf(" %d", &n);
    } while (n < 3 || n > 10);

    // generazione p2
    p2 = fork();
    // entra dentro p2
    if (p2 == 0)
    {
        printf("p2:il mio pid;%d,mio padre p1 ha pid:%d\n", getpid(), getppid());
        exit(0);
        // entra nel padre
    }
    else if (p2 > 0)
    {
        wait(NULL);
        printf("p1 il mio pid:%d,mio figlio p2 ha pid:%d\n", getpid(), p2);
    }

    // generazione p3
    p3 = fork();
    // entra in p3
    if (p3 == 0)
    {
        printf("p3:il mio pid;%d,mio padre p1 ha pid:%d\n", getpid(), getppid());

        // generazione p4
        p4 = fork();
        // entra in p4
        if (p4 == 0)
        {
            printf("p4:il mio pid;%d,mio padre p3 ha pid:%d\n", getpid(), getppid());
            exit(0);
        }
        else if (p4 > 0)
        {
            wait(NULL);
            printf("p3 il mio pid:%d,mio figlio p4 ha pid:%d\n", getpid(), p4);
        }

        // generazione p5
        p5 = fork();
        if (p5 == 0)
        {
            printf("p5:il mio pid;%d,mio padre p3 ha pid:%d\n", getpid(), getppid());
            for (int i = n; i >= 0; i--)
            {
                printf("P5: %d\n", i);
                sleep(1);
            }
            exit(0);
        }
        else if (p5 > 0)
        {
            wait(NULL);
            printf("p3 il mio pid:%d,mio figlio p5 ha pid:%d\n", getpid(), p5);
        }

        for (int i = 0; i <= 10; i++)
        {
            int moltiplicazione = n * i;
            printf("P3:%d\n", moltiplicazione);
        }
    }
    else if (p3 > 0)
    {
        wait(NULL);
        printf("p1 il mio pid:%d,mio figlio p3 ha pid:%d\n", getpid(), p3);
    }
    exit(0);
    exit(0);
    return 0;
}
