#include <stdio.h>
/*Dato N un numero intero positivo, generare e visualizzare in ordine
crescente i numeri compresi maggiori uguali di -N e minori uguali di N.*/
int main(int argc, char *argv[])
{
    int numero;
    do
    {
        printf("Inserisci un numero intero e positivo\n");
        scanf("%d", &numero);
    } while (numero < 0);
    printf("I numeri compresi tra %d e %d sono:\n", numero * -1, numero);
    for (int i = (numero * -1) + 1; i < numero; i++)
    {
        printf("%d\n", i);
    }

    return 0;
}