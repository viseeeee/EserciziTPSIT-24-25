/*rogettare un algoritmo che effettui la lettura da tastiera di una serie
di coppie di valori numerici reali (sia positivi che negativi che zero).
Per ciascuna coppia, l’algoritmo deve calcolare e stampare il valore
della radice quadrata del rapporto tra il valore maggiore e quello
minore dei due.
Il programma termina quando vengono inseriti dei valori
che non permettono di svolgere il calcolo nel dominio dei numeri reali.
Prima di terminare si richiede di stampare un messaggio che indichi la
ragione per cui non è stato possibile svolgere il calcolo.*/
#include <stdio.h>
#include <math.h>
void main()
{
    int a, b;
    double radice;
    do
    {

        printf("Inserisci il primo valore\n");
        scanf("%d", &a);

        printf("Inserisci il secondo valore\n");
        scanf("%d", &b);
        if (a < b)
        {
            radice = sqrt((double)b / (double)a);
        }
        else if (a >= b)
        {
            radice = sqrt((double)a / (double)b);
        }
        printf("la radice del rapporto è:%.2f\n", radice);
    } while (radice > 0);

    printf("Non si può calcolare la radice di indice pari di un numero negativo\n");
}