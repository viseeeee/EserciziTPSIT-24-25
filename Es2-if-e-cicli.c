/*Progettare un algoritmo che effettui le seguenti operazioni:
• continui a leggere da tastiera due valori numerici, fermandosi quando uno dei due numeri è
0 (zero)
• per ogni coppia di numeri letti:
◦ calcoli il prodotto dei due numeri e ne stampi il valore
◦ sommi il prodotto calcolato ad una variabile che memorizzi la somma di tutti i prodotti
• all’uscita del ciclo, stampi il valore della somma*/
#include <stdio.h>
void main()
{
    int a, b;
    double prodotto, somma = 0;
    do
    {
        printf("Inserisci il primo valore numerico\n");
        scanf("%d", &a);
        printf("Inserisci il secondo valore numerico\n");
        scanf("%d", &b);
        prodotto = a * b;
        printf("Il prodotto dei numeri inseriti è:%.2f\n", prodotto);
        somma = somma + prodotto;
        printf("La somma del prodotto di tutti i numeri inseriti è:%.2f\n", somma);
    } while (a != 0 && b != 0);
}