#include <stdio.h>
/*Dati due numeri interi positivi N1 e N2 con N2>N1, generare e
visualizzare in ordine crescente i numeri interi compresi
nell'intervallo chiuso [N1,N2]. */
int main(int argc, char *argv[])
{
    int numero1, numero2;
    do
    {
        printf("Inserisci il primo numero intero e positivo\n");
        scanf("%d", &numero1);
        printf("Inserisci il secondo numero intero e positivo\n");
        scanf("%d", &numero2);
    } while (numero1 > numero2 || numero1 < 0 || numero2 < 0);
    printf("I numeri compresi sono:\n");
    for (int i = numero1 + 1; i < numero2; i++)
    {
        printf("%d\n", i);
    }

    return 0;
}