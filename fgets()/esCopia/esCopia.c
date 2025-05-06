#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int main(int argc, char **argv)
{
    char nomeFileCreato[FILENAME_MAX], fileEsistente[FILENAME_MAX], carattere;
    FILE *fileAperto, *fileApertoCreato;
    printf("Inserisci il nome del file da creare\n");
    scanf("%s", nomeFileCreato);
    printf("Inserisci il nome del file da cui prendere le cose\n");
    scanf("%s", fileEsistente);

    fileAperto = fopen(fileEsistente, "r");

    if (fileAperto == NULL)
    {
        perror("Errore nell'apertura del file");
        exit(1);
    }

    fileApertoCreato = fopen(nomeFileCreato, "w");
    if (fileApertoCreato == NULL)
    {
        perror("Errore nell'apertura del file");
        exit(1);
    }
    else
    {
        while ((carattere = getc(fileAperto))!= EOF)
        {
            fputc(carattere,fileApertoCreato);
        }
    }
    fclose(fileAperto);
    fclose(fileApertoCreato);
    return 0;
}