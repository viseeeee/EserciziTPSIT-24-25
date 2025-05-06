#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    char nome[100], buffer[128];
    int contaRighe = 0, contraCaratteri = 0;
    printf("Inserisci il nome del file\n");
    scanf(" %s", nome);
    FILE *fileAperto = fopen(nome, "r");
    if (fileAperto == NULL)
    {
        perror("Errore nell'apertura del file\n");
        exit(1);
    }
    else
    {
        while (fgets(buffer, 2, fileAperto) != NULL)
        {
            if (buffer[0] == '\n')
            {
                contaRighe++;
            }
            contraCaratteri = contraCaratteri + strlen(buffer);
        }
        printf(" %d\n", contaRighe);
        printf(" %d\n", contraCaratteri);
    }
    fclose(fileAperto);
    return 0;
}