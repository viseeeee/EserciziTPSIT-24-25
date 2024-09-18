/*Progettare un algoritmo che effettui le seguenti operazioni:
• legga da tastiera una coppia di valori interi A e B con A<B;
• continui a leggere da tastiera una serie di valori interi, terminando
quando il valore letto è al di fuori dell’intervallo [A, B];
• conteggi la media dei valori letti;
• prima di terminare, stampi il valore calcolato.*/
#include <stdio.h>
void main()
{
    int a, b, c, somma = 0, valoriInseriti = 0;
    double media;
    do
    {
        printf("Inserisci il valore del primo numero\n");
        scanf("%d", &a);

        printf("Inserisci il valore del secondo numero\n");
        scanf("%d", &b);
    } while (a > b);
    do
    {
        printf("Inserisci il valore \n");
        scanf("%d", &c);
        valoriInseriti++;
        somma = somma + c;
    } while (c >= a && c <= b);

    media = (double)somma / (double)valoriInseriti;
    printf("La media di tutti i numeri inseriti è:%.2f\n", media);
}