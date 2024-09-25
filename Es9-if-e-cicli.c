/*Progettare un algoritmo che risolva il seguente problema. Si richieda
all’utente di inserire una serie di terne di dati numerici (A, B, C).

Il programma deve terminare quando uno dei valori inseriti è minore di
zero.
 Si scartino le terne nelle quali i valori non sono in ordine
strettamente crescente, ovvero quelle terne per cui non valga A < B < C.
Su tutte le terne non scartate si calcoli il massimo e il minimo dei
valori inseriti. Si stampino a video tali valori massimi e minimi prima
di terminare il programma.*/
#include <stdio.h>
int valoreMassimo(int numeri[3])
{
    int max = numeri[0];
    for (int i = 1; i < 3; i++)
    {
        if (max < numeri[i])
        {
            max = numeri[i];
        }
    }
    return max;
}

int valoreMinimo(int numeri[3])
{
    int min = numeri[0];
    for (int i = 1; i < 3; i++)
    {
        if (min > numeri[i])
        {
            min = numeri[i];
        }
    }
    return min;
}

void main()
{
    int numeri[3], max, min, ripetizione = 0;
    do
    {
        printf("Inserisci il primo valore\n");
        scanf("%d", &numeri[0]);
        printf("Inserisci il secondo valore\n");
        scanf("%d", &numeri[1]);
        printf("Inserisci il terzo valore\n");
        scanf("%d", &numeri[2]);
        //terna non valida 
        if (numeri[0] < numeri[1] && numeri[1] < numeri[2])
        {
            printf("Terna non valida\n");
        }
        else
        {
            int minTemporaneo = valoreMinimo(numeri);
            if (minTemporaneo < min || ripetizione == 0)
            {
                min = valoreMinimo(numeri);
            }
            int maxTemporaneo = valoreMassimo(numeri);
            if (maxTemporaneo > max || ripetizione == 0)
            {
                max = valoreMassimo(numeri);
            }
        }
        ripetizione++;
    } while (numeri[0] > 0 && numeri[1] > 0 && numeri[2] > 0);
    printf("Il valore minimo che hai inserito è:%d\n", min);
    printf("Il valore massimo che hai inserito è:%d\n", max);
}

