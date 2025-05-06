#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)
{
    FILE *fileAperto;
    int max = 5, min = 1, numeroGenerare = 5, numeroGenerato;
    int numero, numero2;

    srand(time(NULL));
    printf("Prima fopen: %p\n", (void *)fileAperto);

    fileAperto = fopen("file.txt", "w");
    if (fileAperto == NULL) {
        perror("Errore apertura file");
        return 1;
    }
    printf("Dopo fopen: %p\n", (void *)fileAperto);

    /* genera numeri casuali e li inserisce con fprintf
    for (int i = 0; i < numeroGenerare; i++) {
        numeroGenerato = rand() % (max - min + 1) + min;
        printf("%d\n", numeroGenerato);
        fprintf(fileAperto, "%d\n", numeroGenerato);
    }

    inserimento tramite fprintf
    printf("Inserisci un numero\n");
    scanf("%d", &numero);
    fprintf(fileAperto, "%d\n", numero);

    */
    // inserimento tramite putc
    printf("Inserisci quanti caratteri vuoi inserire\n");
    scanf("%d", &numero2);
    for (int i = 0; i < numero2; i++) {
        char carattere;
        printf("Inserisci un carattere\n");
        scanf(" %c", &carattere);
        fprintf(fileAperto, "%c", carattere);
        putc(carattere, fileAperto);
        putc('\n', fileAperto);
    }

    // inserimento stringa
    printf("Inserisci una stringa\n");
    char stringa[100];
    scanf("%s", stringa);
    fprintf(fileAperto, "%s\n", stringa);

    fclose(fileAperto);

    // lettura file
    fileAperto = fopen("file.txt", "r");
    if (fileAperto == NULL) {
        perror("Errore apertura file in lettura");
        return 1;
    }
    printf("Dopo fopen: %p\n", (void *)fileAperto);

    // Riavvolgi il file per poter leggere la prima riga

    printf("caratteri\n");
    char carattereLetti[81];
    if (fgets(carattereLetti, 81, fileAperto)) {
        printf("\nPrima riga: %s", carattereLetti);
    }

    fclose(fileAperto);
    printf("Dopo fclose: %p\n", (void *)fileAperto);

    return 0;
}
