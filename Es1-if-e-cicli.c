
/*Progettare un algoritmo che effettui la lettura da tastiera di una serie di coppie di valori numerici.
L’algoritmo deve calcolare e stampare il rapporto tra il valore minore e quello maggiore dei due. Il
programma termina quando uno dei due valori o entrambi sono uguali a zero.*/
#include <stdio.h>

void main(int argc, char *argv[])
{
    int a, b;
    double rapporto;
    do
    {
        printf("Inserisci il primo valore\n");
        scanf("%d", &a);

        printf("Inserisci il secondo valore\n");
        scanf("%d", &b);

        if (a > b)
        {
            rapporto = (double)b / (double)a;
        }
        else
        {
            rapporto = (double)a / (double)b;
        }
        
        printf("Il risltato del rapporto e':%f\n", rapporto);

    } while (a != 0 && b != 0);
}