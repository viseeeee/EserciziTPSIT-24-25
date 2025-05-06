#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Numero parametri errato\n");
        exit(1);
    }

    int pid, p1p2[2], p2p0[2];
    double totale = 0;
    char counter[1], importo[100], *end; // inizializza la stringa

    pipe(p1p2);
    pipe(p2p0);

    pid = fork();
    if (pid == 0) {
        close(1);
        dup(p1p2[1]);
        close(p1p2[0]);
        close(p1p2[1]);

        close(p2p0[0]);
        close(p2p0[1]);

        execl("/usr/bin/cat", "cat", argv[1], (char *)0);
        exit(1);
    }

    pid = fork();
    if (pid == 0) {
        close(0);
        dup(p1p2[0]);
        close(p1p2[0]);
        close(p1p2[1]);

        close(1);
        dup(p2p0[1]);
        close(p2p0[0]);
        close(p2p0[1]);

        execl("/usr/bin/awk", "awk", "{print $3}", (char *)0);
        exit(1);
    }

    close(p1p2[0]);
    close(p1p2[1]);
    close(p2p0[1]);

    while (read(p2p0[0], counter, 1) > 0) {
        strncat(importo, counter, 1);
        if (counter[0] == '\n') {
            double x = strtod(importo, &end);
            totale += x;
            importo[0] = '\0';
        }
    }

    printf("Sono stati trovati %.2f euro in totale\n", totale);
    close(p2p0[0]);

    wait(NULL);
    wait(NULL);

    return 0;
}
