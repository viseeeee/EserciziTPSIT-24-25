#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero parametri errato\n");
        exit(1);
    }

    int pid, p2p0[2], countertot = 0, p1p2[2];
    char stringa[1000], counter[1000];

    while (1)
    {
        printf("Inserisci la stringa che vuoi cercare\n");
        scanf("%s", stringa);
        if (strcmp(stringa, "fine") == 0)
        {
            printf("numero di parole uguali trovate nel file %d\n", countertot);
            exit(0);
        }

        pipe(p2p0);
        pipe(p1p2);

        pid = fork();
        if (pid == 0)
        {
            // Figlio 1: grep
            close(p1p2[0]);
            dup2(p1p2[1], STDOUT_FILENO);
            close(p1p2[1]);

            close(p2p0[0]); // AGGIUNTA
            close(p2p0[1]); // AGGIUNTA

            execl("/usr/bin/grep", "grep", "-ow", stringa, argv[1], NULL);
            perror("execl grep");
            exit(1);
        }

        pid = fork();
        if (pid == 0)
        {
            // Figlio 2: wc
            close(p1p2[1]);
            dup2(p1p2[0], STDIN_FILENO);
            close(p1p2[0]);

            close(p2p0[0]);
            dup2(p2p0[1], STDOUT_FILENO);
            close(p2p0[1]);

            execl("/usr/bin/wc", "wc", "-l", (char *)0);
            perror("execl wc");
            exit(1);
        }

        // Padre
        close(p1p2[0]);
        close(p1p2[1]);
        close(p2p0[1]);

        read(p2p0[0], counter, sizeof(counter));
        printf("La parola è comarsa %d volte\n", atoi(counter));
        countertot += atoi(counter);
        close(p2p0[0]); // AGGIUNTA

        wait(NULL);
        wait(NULL);
    }

    return 0;
}
