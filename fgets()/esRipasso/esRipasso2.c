#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    FILE *fileAperto;
    int max = 5, min = 1, numeroGenerare = 5, numeroGenerato;
    int numero, numero2;
    srand(time(NULL));
    printf("Prima fopen: %p\n", (void *)fileAperto);

    fileAperto = fopen("file.txt", "w");
    printf("Dopo fopen: %p\n", (void *)fileAperto);

    // inserimento tramite putc
    printf("Inserisci quanti caratteri vuoi inserire\n");
    scanf("%d", &numero2);
    for (int i = 0; i < numero2; i++)
    {
        char carattere;
        printf("Inserisci un carattere\n");
        scanf(" %c", &carattere);
        fprintf(fileAperto, "%c\n", carattere);
        putc(carattere, fileAperto);
        putc('\n', fileAperto);
    }


    printf("Inserisci una stringa\n");
    char stringa[100];
    scanf("%s", stringa);
    fprintf(fileAperto, "%s\n", stringa);

    fclose(fileAperto);

    fileAperto = fopen("file.txt", "r");
    printf("Dopo fopen: %p\n", (void *)fileAperto);
    char carattereLetto;
    int contarighe=0,contacaratteri=0;
    while ((carattereLetto = fgetc(fileAperto)) != EOF)
    {
        if (carattereLetto=='\n')
        {
            contarighe++;
        }else{
            contacaratteri++;
        }
        printf("%c", carattereLetto);
    }

    printf("Le righe sono:%d\n",contarighe);
    printf("I caratteri sono:%d\n",contacaratteri);
    fclose(fileAperto);
    printf("Dopo fclose: %p\n", (void *)fileAperto);
}