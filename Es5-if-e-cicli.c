/*Progettare un algoritmo che effettui le seguenti operazioni:

• continui a leggere da tastiera una serie di terne di valori interi A ,
B e C finchè non vengono inseriti dei valori tali per cui A + B < C
• conteggi il numero di volte in cui la differenza tra A e B è pari, dispari, e quando è nulla
• prima di terminare, visualizzi il valore dei valori conteggiati*/
#include <stdio.h>
void main()
{
    int a, b, c, differenza, pari = 0, dispari = 0, nulla = 0;
    do
    {
        printf("Inserisci il primo valore\n");
        scanf("%d", &a);

        printf("Inserisci il secondo valore\n");
        scanf("%d", &b);

        printf("Inserisci il terzo valore\n");
        scanf("%d", &c);
        differenza = a - b;
        if (differenza == 0)
        {
            nulla++;
        }
        else if (differenza % 2 == 0)
        {
            pari++;
        }
        else if (differenza % 2 == 1)
        {
            dispari++;
        }
    } while (a + b >= c);
    printf("La differenza dei valori a e b è stata nulla %d volta/e\n", nulla);
    printf("La differenza dei valori a e b è stata dispari %d volta/e\n", dispari);
    printf("La differenza dei valori a e b è stata pari %d volta/e\n", pari);
}