/*Una birreria a fine serata deve conteggiare l’incasso. La cassiera accende il software gestionale il quale le chiede di inserire una alla volta le consumazioni servite.
Le consumazioni si dividono in bevande e ristorazione. La cassiera per ogni consumazione deve inserire la tipologia di consumazione e il suo importo.

Quando la cassiera inserisce la stringa “esci” il software deve mostrare a video le seguenti informazioni:
1.	La media dell’incasso delle bevande
2.	La media dell’incasso della ristorazione
3.	Deve indicare se sono state vendute più bevande o più ristorazioni*/
#include <stdio.h>
#include <string.h>
void main()
{
    char tipo[100];
    int numeroBevande = 0, numeroRistorazione = 0;
    float prezzoRistorazione, PrezzoBevande;
    int sommaBevande = 0, sommaRistorazione;
    double mediaBevande, mediaRistorazione;
    do
    {
        printf("Inserisci il tipo consumazione\n");
        scanf("%s", tipo);
        if (strcmp(tipo, "bevande") == 0)
        {
            do
            {
                printf("Inserisci il prezzo della bevanda\n");
                scanf("%f", &PrezzoBevande);
                sommaBevande += PrezzoBevande;
                numeroBevande++;
            } while (PrezzoBevande <= 0);
        }

        if (strcmp(tipo, "ristorazione") == 0)
        {
            do
            {
                numeroRistorazione++;
                printf("Inserisci il prezzo del cibo\n");
                scanf("%f", &prezzoRistorazione);
                sommaRistorazione += prezzoRistorazione;
            } while (prezzoRistorazione <= 0);
        }
    } while (strcmp(tipo, "esci") != 0);

    mediaBevande = sommaBevande / numeroBevande;
    mediaRistorazione = sommaRistorazione / numeroRistorazione;
    if (numeroRistorazione>numeroBevande)
    {
        printf("E' stato preso più cibo\n");
    }else if(numeroBevande==numeroRistorazione){
        printf("E' stato preso lo stesso numero di bevande che di cibo\n");
    }else{
        printf("Sono state prese più bevande\n");
    }
    
    printf("La media delle bevande è:%.2f\n", mediaBevande);
    printf("La media della ristorazione è:%.2f\n", mediaRistorazione);
}