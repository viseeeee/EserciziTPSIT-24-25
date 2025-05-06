#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Uso: %s <file>\n", argv[0]);
        exit(1);
    }

    int pid, p1p2[2], p2p0[2];
    char buffer, vocali[10];
    int contatore = 0;

    pipe(p1p2);
    pipe(p2p0);

    pid = fork();
    if (pid == 0)
    {
        // Primo figlio (cat)
        close(p1p2[0]);  // Chiudi la lettura dalla pipe 1
        close(p2p0[0]);  // Chiudi la lettura dalla pipe 2
        close(p2p0[1]);  // Chiudi la scrittura dalla pipe 2

        // Redirigi la scrittura su p1p2[1] (pipe verso il secondo figlio)
        close(1);
        dup(p1p2[1]);
        close(p1p2[1]);

        // Esegui il comando "cat" per leggere il file
        execl("/usr/bin/cat", "cat", argv[1], NULL);
        exit(1);
    }

    // Processo padre
    close(p1p2[1]);  // Chiudi la scrittura della pipe 1

    pid = fork();
    if (pid == 0)
    {
        // Secondo figlio (conta le vocali)
        close(p2p0[0]);  // Chiudi la lettura della pipe 2
        close(p1p2[1]);  // Chiudi la scrittura della pipe 1

        while (read(p1p2[0], &buffer, 1) > 0)
        {
            buffer = tolower(buffer);
            if (buffer == 'a' || buffer == 'e' || buffer == 'i' || buffer == 'o' || buffer == 'u')
            {
                contatore++;
            }
        }
        close(p1p2[0]);  // Chiudi la lettura della pipe 1

        // Scrivi il numero di vocali nella pipe 2
        sprintf(vocali, "%d", contatore);
        write(p2p0[1], vocali, strlen(vocali) + 1);  // Aggiungi +1 per il terminatore di stringa
        close(p2p0[1]);  // Chiudi la scrittura della pipe 2
        exit(0);
    }

    // Processo padre
    close(p2p0[1]);  // Chiudi la scrittura della pipe 2

    // Leggi il numero di vocali dal secondo figlio
    read(p2p0[0], vocali, sizeof(vocali));

    printf("Il numero di vocali trovate è: %s\n", vocali);

    close(p2p0[0]);  // Chiudi la lettura della pipe 2

    // Aspetta la terminazione dei processi figli
    wait(NULL);
    wait(NULL);

    return 0;
}
