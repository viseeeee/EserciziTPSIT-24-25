/*Progettare un algoritmo che risolve il seguente problema. Si desidera
calcolare la somma delle radici quadrate di N valori numerici inseriti
dall’utente, con N inserito in input.
L’algoritmo deve stampare la somma calcolata. L’algoritmo deve terminare
con un messaggio di errore quando viene inserito un numero che non
permette di effettuare il calcolo (nel dominio dei numeri reali).*/
#include <stdio.h>
#include <math.h>

void main()
{
    int quantita, numeri;
    double radice, somma = 0;
    do
    {
        printf("Inserisci il numero di quanti valori vuoi inserire\n");
        scanf("%d", &quantita);
    } while (quantita > 0);

    for (int i = 0; i < quantita; i++)
    {
        // inserimento dei numeri
        printf("Inserisci il valore numero %d:\n", i + 1);
        scanf("%d", &numeri);
        if (numeri >= 0)
        {
            radice = sqrt((double)numeri);
            somma = somma + radice;
            radice = 0;
        }
        else
        {
            printf("Il valore che hai inserito è errato\n");
            break;
        }
    }
    printf("La somma delle radici quadrate che hai inserito è:%.2f\n", somma);
}