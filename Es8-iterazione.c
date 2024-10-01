#include <stdio.h>
/*Dato N un numero intero positivo, generare e visualizzare in ordine
decrescente i primi N numeri interi positivi.*/
int main(int argc, char *argv[])
{
    int numero;
    do
    {
        printf("Inserisci un numero intero e positivo\n");
        scanf("%d", &numero);
    } while (numero < 0);
    printf("I numeri precedenti interi e positivi sono:\n");
    for (int i = numero - 1; i >= 0; i--)
    {
        printf("%d\n", i);
    }

    return 0;
}