/*Il file f.txt contiene l'output della seguente chiamata:
$ traceroute google.com

Lo scopo del Traceroute è seguire il percorso di un pacchetto di dati dalla sua sorgente fino a destinazione. Per farlo dovrà registrare ogni singolo "salto" del pacchetto.

Sfruttando la programmazione concorrente si vuole realizzare un programma che legga il file, prelevi la prima delle tre colonne che mostra il tempo di risposta in nano secondi e calcoli quindi il tempo totale di richiesta.

Esempio di file:

$ cat f.txt 
traceroute to google.com (216.58.208.174), 30 hops max, 60 byte packets
 1  _gateway (192.168.2.1)  0.686 ms  0.732 ms  0.775 ms
 2  net-93-149-86-45.cust.vodafonedsl.it (93.149.86.45)  5.868 ms  5.947 ms  5.477 ms
 3  192.168.50.18 (192.168.50.18)  11.627 ms  14.028 ms  14.207 ms
 4  * * *
 5  * * *
 6  185.210.48.39 (185.210.48.39)  14.759 ms 185.210.48.38 (185.210.48.38)  12.411 ms  12.312 ms
 7  185.210.48.39 (185.210.48.39)  12.630 ms  12.715 ms  13.159 ms
 8  185.210.48.3 (185.210.48.3)  12.783 ms  14.649 ms  14.006 ms
 9  74.125.245.225 (74.125.245.225)  14.535 ms * 74.125.245.241 (74.125.245.241)  16.420 ms
10  142.250.212.244 (142.250.212.244)  16.971 ms 72.14.234.75 (72.14.234.75)  12.953 ms 209.85.255.5 (209.85.255.5)  13.432 ms
11  lhr25s09-in-f14.1e100.net (216.58.208.174)  12.783 ms  12.623 ms  12.129 ms

Come si può vedere dall'esempio la prima riga non è utile, e il primo tempo utile si trova nella quarta colonna. 

Note operative: 
p0 crea il processo p1 che chiama il comando cat e inoltra il suo output a p2
p2 estrapola la quarta colonna e la inoltra a p3
p3 chiama il comando tail -n +2 per escludere la prima riga, fatto cio inoltra l'output a p0
p0 somma tutti i tempi di accesso e al termine mostra il tempo totale che un pacchetto ha impiegato lungo il percorso


Osservazione importante:
Al fine di rendere l'esercizio facilmente testabile si è deciso di utilizzare il file f.txt in modo da avere un risultato riproducibile. Dopo aver testato il software si consiglia di sostituire al comando cat il comando traceroute in modo da realizzare un software il cui funzionamento è reale.
Esempio di utilizzo reale: $./a.out google.com

*/

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

    int pid, p1p2[2], p2p3[2],p3p0[2];
    double totale = 0;
    char counter[1000], carattere[100], *end; // inizializza la stringa

    pipe(p1p2);
    pipe(p2p3);

    pid = fork();
    if (pid == 0) {
        close(1);
        dup(p1p2[1]);
        close(p1p2[0]);
        close(p1p2[1]);

        close(p2p3[0]);
        close(p2p3[1]);

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
        dup(p2p3[1]);
        close(p2p3[0]);
        close(p2p3[1]);

        execl("/usr/bin/awk", "awk", "{print $4}", (char *)0);
        exit(1);
    }

    pid = fork();
    if (pid == 0) {
        close(p1p2[0]);
        close(p1p2[1]);

        close(0);
        dup(p2p3[0]);
        close(p2p3[0]);
        close(p2p3[1]);

        close(1);
        dup(p3p0[1]);
        close(p3p0[0]);
        close(p3p0[1]);

        execl("/usr/bin/tail", "tail","-n+2", (char *)0);
        exit(1);
    }

    close(p1p2[0]);
    close(p1p2[1]);
    close(p2p3[1]);
    close(p2p3[0]);

    while (read(p3p0[0],carattere,1)>0)
    {
        strncat(counter,carattere,1);
        if (carattere[0]=='\n')
        {
            double x=strtod(counter,&end);
            totale+=x;
        }
        
    }
    

    printf("Sono stati trovati %.2f euro in totale\n", totale);
    close(p3p0[0]);
    close(p3p0[1]);
    wait(NULL);
    wait(NULL);

    return 0;
}



