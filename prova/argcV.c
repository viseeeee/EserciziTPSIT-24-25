#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DIM 1024
int main(int argc, char **argv)
{
    // passa un numero tramite argv incrementalo e stampalo
    if (argc != 2)
    {
        printf("Errore");
        exit(-1);
    }

    printf("metti la stringa\n");
    int numero = atoi(argv[1]);
    printf("%d", numero);
    printf("\n");
    numero++;
    printf("%d\n", numero);

    char Stringa[DIM];
    printf("Inserisci una stringa\n");
    scanf(" %s", Stringa);
    printf("%s\n", Stringa);

    char *a=Stringa;
    printf("Inserisci una stringa\n");
    printf("%c\n",*a);
    printf("%p\n", &a);
    printf("%p\n", a);
    

    return 0;
}
