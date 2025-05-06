/*Un’applicazione multiprocesso in C deve presentare la seguente interfaccia:
controlloFatture nomeFileFatture 
dove nomeFileFatture è un nome assoluto di file.

A questo fine, l’addetto dell’azienda deve verificare, sul file passato 
come parametro, se un cliente ha ancora delle fatture in sospeso oppure se 
le ha pagate tutte.

Nel file passato come parametro sono memorizzate tutte le fatture, una per
ogni riga. Ogni riga è composta dal nome del cliente (un codice di 5 caratteri
alfanumerico che identifica univocamente ogni cliente), da un campo che 
contiene la stringa “pagato” per le fatture saldate oppure “insoluto”
per quelle ancora insolute, più altri campi con altre informazioni.

L’addetto dell’azienda inserisce a terminale il codice dei clienti (uno alla
volta) di cui vuole controllare lo stato dei pagamenti. Per ogni cliente
inserito, l’applicazione deve visualizzare il nome del cliente stesso e il
numero di fatture di tale cliente che risultano ancora da pagare.

Quando l’applicazione termina,a causa dell’inserimento della stringa “esci”,
il programma deve visualizzare il numero totale di richieste di servizio
eseguite fino a quel momento.*/

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

    int pid, p2p0[2], countertot = 0;
    char stringa[1000], counter[1000];

    while (1)
    {
        printf("Inserisci il codice che vuoi cercare\n");
        scanf("%s", stringa);
        if (strcmp(stringa, "esci") == 0)
        {
            printf("Numeri di insoluti trovati %d\n", countertot);
            exit(0);
        }

        pipe(p2p0);

        pid = fork();
        if (pid == 0)
        {
            // Figlio 1: grep
            close(1);
            close(p2p0[0]);
            dup(p2p0[1]);
            close(p2p0[1]);

        
            execl("/usr/bin/grep", "grep", "-c", strcat(stringa," insoluto"), argv[1], NULL);
            perror("execl grep");
            exit(1);
        }

        close(p2p0[1]);

        read(p2p0[0], counter, sizeof(counter));
        printf("Sono stati trovati %d insoluti \n", atoi(counter));
        countertot += atoi(counter);
        close(p2p0[0]); // AGGIUNTA

        wait(NULL);
    }

    return 0;
}
