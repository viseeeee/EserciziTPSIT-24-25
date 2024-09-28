#include <stdio.h>
/*Dato N un numero intero positivo, generare e visualizzare in ordine crescente i primi N numeri
interi positivi*/
int main(int argc, char *argv[])
{
    int numero;
    do
    {
        printf("Inserisci un numero intero e positivo\n");
        scanf("%d", &numero);
    } while (numero < 0);
    printf("I numeri precedenti interi e positivi sono:\n");
    for (int i = 0; i < numero; i++)
    {
        printf("%d\n", i);
    }

    return 0;
}