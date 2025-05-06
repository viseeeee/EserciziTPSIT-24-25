#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int numeri[4];
    int numero;
    FILE *fileNumeri;
    fileNumeri = fopen("fileNumeri.txt", "w");
    if (fileNumeri == NULL)
    {
        perror("Errore nell'apertura del file");
    }

    for (int i = 0; i < 5; i++)
    {
        printf("Inserisci il numeri nella posizione %d\n", i + 1);
        scanf("%d", &numeri[i]);
        fprintf(fileNumeri, "%d\n", numeri[i]);
    }
    fclose(fileNumeri);

    fileNumeri = fopen("fileNumeri.txt", "r");
    if (fileNumeri == NULL)
    {
        perror("Errore nell'apertura del file");
    }
    printf("I numeri sono:");
    while (fscanf(fileNumeri, "%d", &numero) != EOF)
    {
        printf("%d\n", numero);
    }
    fclose(fileNumeri);

    return 0;
}
