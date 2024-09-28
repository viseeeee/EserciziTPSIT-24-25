#include <stdio.h>
/*Dato N un numero intero positivo, generare e visualizzare in ordine
crescente i numeri pari minori o uguali a N.*/
int main(int argc, char *argv[])
{
    int numero;
    do
    {
        printf("Inserisci un numero intero e positivo\n");
        scanf("%d", &numero);
    } while (numero < 0);
    printf("I numeri precedenti e dispari sono:\n");
    for (int i = 0; i <= numero; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d\n", i);
        }
    }
    return 0;
}