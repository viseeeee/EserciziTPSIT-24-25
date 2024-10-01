#include <stdio.h>
/*Dato N un numero intero positivo, calcolare e visualizzare la somma dei
primi N numeri interi. */
int main(int argc, char *argv[])
{
    int numero, somma = 0;
    do
    {
        printf("Inserisci un numero intero e positivo\n");
        scanf("%d", &numero);
    } while (numero < 0);

    for (int i = 0; i < numero; i++)
    {
        somma += i;
    }
    printf("la somma dei numeri precedenti è:%d\n", somma);
    return 0;
}