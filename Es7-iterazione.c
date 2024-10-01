#include <stdio.h>
/*Dato N un numero intero positivo maggiore di 1, generare e visualizzare
il numero precedente. */
int main(int argc, char *argv[])
{
    int numero;
    do
    {
        printf("Inserisci un numero positivo e intero\n");
        scanf("%d", &numero);

    } while (numero < 0);
    numero--;
    printf("Il numero successivo a quello inserito è:%d\n", numero);
    return 0;
}