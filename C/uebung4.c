#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Bekanntmachung der Funktionen
int linearSearch(int arr[], int x);
int binarySearch(int arr[], int x);
void unknownSort(int *arr, int size);
void arrayAusgeben(int *arr, int size);
void bubbleSort(int arr[], int size);

int main(int argc, char const *argv[])
{

    // ---------------------Aufgabe 1--------------------- //
    printf(" \n");
    printf("Aufgabe 1: \n");

    // Erstellung des Arrays
    int arrZufallszahlen[200000];
    int i;
    srand(time(NULL)); // sorgt für eine zufällige Reihenfolge

    // Befüllen des Arrays
    for (i = 0; i < 200000; i++)
    {
        int zufallszahl = rand() % 50000 + 1;
        arrZufallszahlen[i] = zufallszahl;
        // printf("%d \n", arrZufallszahlen[i]);
    }

    // generiert einen zufälligen Suchschlüssel(0 - 50.000)
    int suchschluessel = rand() % 50000 + 1;
    printf("Suchschlüssel: %d \n", suchschluessel);

    // lineare Suche
    clock_t startLIN = clock();
    printf("LINSEARCH - Der Suchschlüssel wurde am Index: %d gefunden.\n", linearSearch(arrZufallszahlen, suchschluessel));
    clock_t endeLIN = clock();
    double genutzte_cpu_zeit_LIN = ((double)(endeLIN - startLIN)) / CLOCKS_PER_SEC;

    // binäre Suche
    clock_t startBIN = clock();
    printf("BINSEARCH - Der Suchschlüssel wurde am Index: %d gefunden.\n", binarySearch(arrZufallszahlen, suchschluessel));
    clock_t endeBIN = clock();
    double genutzte_cpu_zeit_BIN = ((double)(endeBIN - startBIN)) / CLOCKS_PER_SEC;

    // Ausgabe der Zeiten
    printf("LINSEARCH TIME: %f ms \n", genutzte_cpu_zeit_LIN * 1000);
    printf("BINSEARCH TIME: %f ms \n", genutzte_cpu_zeit_BIN * 1000);
    printf("\n");
    printf("--------------------------------------------------------------\n");

    // ---------------------Aufgabe 2--------------------- //
    printf(" \n");
    printf("Aufgabe 2: \n");
    // Erstellung der zufälligen Suchschlüssel
    int arrSuchschluessel[10000];

    int j;
    int k;
    int l;

    // Befüllen des Arrays
    for (j = 0; j < 10000; j++)
    {
        int zufallsSuchschluessel = rand() % 50000 + 1;
        arrSuchschluessel[j] = zufallsSuchschluessel;
    }

    clock_t startLIN_2 = clock();
    for (k = 0; k < 10000; k++)
    {
        // printf("LINSEARCH_2 - Der Suchschlüssel wurde am Index: %d gefunden.\n", linearSearch(arrZufallszahlen, arrSuchschluessel[k]));
        // !---! Den unteren Aufruf einfach auskommentieren und den oberen einkommentieren, um die zeilenweise Ausgabe der linearen Suche zu starten !---!
        linearSearch(arrZufallszahlen, arrSuchschluessel[k]);
    }
    clock_t endeLIN_2 = clock();
    double genutzte_cpu_zeit_LIN_2 = ((double)(endeLIN_2 - startLIN_2)) / CLOCKS_PER_SEC;
    printf("LINSEARCH TIME 2: %f ms \n", genutzte_cpu_zeit_LIN_2 * 1000);

    // analoges Anlegen und Befüllen eines zweiten Arrays mit dem Ersten
    int arrZufallszahlen2[200000];

    int n;

    for (n = 0; n < 200000; n++)
    {
        arrZufallszahlen2[n] = arrZufallszahlen[n];
    }

    // sortieren des zweiten Arrays
    bubbleSort(arrZufallszahlen2, 200000);

    clock_t startBIN_2 = clock();
    for (l = 0; l < 10000; l++)
    {
        // printf("BINSEARCH_2 - Der Suchschlüssel wurde am Index: %d gefunden.\n", binarySearch(arrZufallszahlen, arrSuchschluessel[k]));
        // !---! Den unteren Aufruf einfach auskommentieren und den oberen einkommentieren, um die zeilenweise Ausgabe der binären Suche zu starten !---!
        binarySearch(arrZufallszahlen2, arrSuchschluessel[l]);
    }
    clock_t endeBIN_2 = clock();
    double genutzte_cpu_zeit_BIN_2 = ((double)(endeBIN_2 - startBIN_2)) / CLOCKS_PER_SEC;
    printf("BINSEARCH TIME 2: %f ms \n", genutzte_cpu_zeit_BIN_2 * 1000);
    printf("\n");
    printf("--------------------------------------------------------------\n");

    // ---------------------Aufgabe 3--------------------- //
    printf(" \n");
    printf("Aufgabe 3: \n");

    // Erstellung des Arrays
    int sortierArray[5];

    int m;

    srand(time(NULL));

    // Befüllen des Arrays
    for (m = 0; m < 5; m++)
    {
        int randomZahl = rand() % 30 + 1;
        sortierArray[m] = randomZahl;
    }

    // Aufrufen des Sortieralgorithmus
    unknownSort(sortierArray, 5);
    printf("\n");
    return 0;
}
void bubbleSort(int arr[], int size)
{

    // BubbleSort von den Folien
    while (size) // Läuft solange, bis laenge den Wert 0 erreicht hat --> steht für false
    {
        for (int i = 1; i < size; i++) // vergleiche die aktuelle Stelle mit der Stelle davor
        {
            if (arr[i - 1] > arr[i]) // Tauschen des Größer-Kleiner-Vergleichsoperators, um absteigende Reihenfolge zu garantieren
            {
                int tmp = arr[i];    // Speicherung des int-Werts der aktuellen Position in einer temp-Variable
                arr[i] = arr[i - 1]; // an der aktuellen Postion wird nun der int-Wert aus der vorherigen Position gespeichert
                arr[i - 1] = tmp;    // an die vorherige Position wird der int-Wert in der temp-Variable gespeichert
            }
        }
        size--;
    }
}

int linearSearch(int arr[], int x)
{
    size_t laenge = sizeof(arr); // Stellt die Länge des int-Arrays bereit

    for (int i = 0; i < laenge; i++)
    {
        if (arr[i] == x) // wenn gesuchtes Element an der aktuellen Stelle im Array steht, gib den Index zurück
        {
            return i;
        }
    }

    return -1; // ansonsten gib -1 zurück
}

int binarySearch(int arr[], int x)
{
    size_t laenge = sizeof(arr);

    int middle = 0;
    int left = 0;
    int right = laenge - 1;

    while (left <= right)
    {
        middle = (left + right) / 2; // mittleres Element für die Suche
        if (arr[middle] == x)
            return middle;
        else if (arr[middle] > x)
            right = middle - 1; // an dieser Stelle wird bei gesuchtem 'd' im String -1 returned, da beim zweiten Suchdurchlauf 'd' aus der Suchreichweite geworfen wird --> da ASCII-Zahl kleiner ist (Fix durch BubbleSort)
        else if (arr[middle] < x)
            left = middle + 1;
    }

    return -1;
}

void unknownSort(int *arr, int size)
{
    // Ausgabe des Arrays, bevor es sortiert wird!
    int l;
    int i;
    int hold;

    printf("Unsortierte Elemente des Arrays: ");
    for (l = 0; l < size; l++)
    {
        printf("%d ", arr[l]);
    }

    printf("\n");

    // erster Schritt, um den Vorgänger zu überprüfen
    printf("Schritt nach rechts.\n");
    for (i = 1; i < size;)
    {
        // Start der Vergleichslogik
        if (arr[i - 1] > arr[i])
        {
            int hold = arr[i];
            arr[i] = arr[i - 1]; // Positionen tauschen
            arr[i - 1] = hold;
            printf("Tausch.\n");
            i--; // Dekrementieren
            printf("Schritt nach links.\n");
        }
        else if (arr[i - 1] <= arr[i]) // Wenn der Vorgänger gleich oder kleiner als die aktuelle Stelle ist
        {
            i++;
            printf("Schritt nach rechts.\n"); // einfach weiter, da die Position schon stimmt
        }
        else
        {
            break;
        }
    }
    printf("Sortierte Elemente des Arrays: ");

    arrayAusgeben(arr, 5); // Routine zum Ausgeben des sortierten Arrays
}

void arrayAusgeben(int *arr, int size)
{

    // einfache Ausgabe-Schleife für sortierte Elemente des Arrays

    int i;

    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
