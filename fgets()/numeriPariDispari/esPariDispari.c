#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    FILE *filePari, *fileDispari, *fileNumeri;
    int caratteri;

    fileNumeri = fopen("Numeri.txt", "r");
    if (fileNumeri == NULL)
    {
        perror("Errore nell'apertura del file");
        exit(1);
    }

    filePari = fopen("numeriPari.txt", "w");
    if (filePari == NULL)
    {
        perror("Errore nell'apertura del file");
        exit(1);
    }

    fileDispari = fopen("numeriDispari.txt", "w");
    if (fileDispari == NULL)
    {
        perror("Errore nell'apertura del file");
        exit(1);
    }

    while (fscanf(fileNumeri, "%d", &caratteri)!= EOF)
    {   
        if (caratteri % 2 == 0)
        {
             fprintf(filePari, "%d ", caratteri);
        }
        else
        {
             fprintf(fileDispari, "%d ", caratteri);
        }
    }
    fclose(fileDispari);
    fclose(filePari);
    fclose(fileNumeri);
return 0;
}