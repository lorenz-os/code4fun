#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[])
{
    // ---------------------Aufgabe 1--------------------- //
    // Bekanntmachung der Funktionen
    // void bubbleSort(char arr[]);
    // void quickSort(char arr[], int l, int r);

    // Definiere einen String
    // char eingabeString[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '\0'};

    // Laenge für den Aufruf von Quicksort
    // int laengeEingabeString = strlen(eingabeString);

    // bubbleSort(eingabeString);
    // quickSort(eingabeString, 0, laengeEingabeString - 1);

    // ---------------------Aufgabe 2--------------------- //
    // Bekanntmachung der Funktionen
    //int linearSearch(char arr[], char x);
    int binarySearch(char arr[], char x);

    char str2[] = "Hello World";
    char key = 'd';

    // printf("%d", linearSearch(str2, key));
    printf("Der Index des Suchschluessels lautet: %d \n", binarySearch(str2, key));
    printf("Dieser Index gleicht aber nicht der Position des Suchschluessels im unsortieren, originalen Array.");

    return 0;
}

/*
// -------------------------------------------------------Aufgabe 1.1------------------------------------------------------- //
void bubbleSort(char arr[])
{
    // speichern der Länge des Strings in Variable n
    int n = strlen(arr);

    // BubbleSort von den Folien
    while (n) // Läuft solange, bis n den Wert 0 erreicht hat --> steht für false
    {
        for (int i = 1; i < n; i++) // vergleiche die aktuelle Stelle mit der Stelle davor
        {
            if (arr[i - 1] < arr[i]) // Tauschen des Größer-Kleiner-Vergleichsoperators, um absteigende Reihenfolge zu garantieren // Vergleichen der ASCII-Integerwerte der chars
            {
                char tmp = arr[i];   // Speicherung des char der aktuellen Position in einer temp-Variable
                arr[i] = arr[i - 1]; // an der aktuellen Postion wird nun der char aus der vorherigen Position gespeichert
                arr[i - 1] = tmp;    // an die vorherige Position wird der char der temp-Variable gespeichert
            }
        }
        n--;
    }

    // Ausgeben des gesamten Strings
    printf("BubbleSort absteigend: '%s'", arr);
}


// -------------------------------------------------------Aufgabe 1.2------------------------------------------------------- //
void quickSort(char arr[], int l, int r)
{
    // Quicksort von den Folien
    int i = l;                    // linker Index
    int j = r;                    // rechter Index
    int pivot = arr[(l + r) / 2]; // Pivotelement definieren (im Normalfall einfach die Mitte)

    do
    {
        while (arr[i] < pivot) // ist das Element kleiner als das Pivotelement
            i++;               // linken Index erhöhen
        while (pivot < arr[j]) // ist das Element größer als das Pivotelement
            j--;               // rechten Index verringern
        if (i <= j)            // ist der linke Index kleiner oder gleich dem rechten Index
        {
            char h = arr[i]; // selbe Prozedur wie beim BubbleSort-Algorithmus, hier allerdings für einen Teil des Arrays
            arr[i] = arr[j];
            arr[j] = h;
            i++;            // Inkrementieren von i und Dekrementieren von j, um Untersuchungsbereich des Arrays zu verkleinern
            j--;
        }

    } while (i <= j);

    if (l < j)
        quickSort(arr, l, j); // rekursiver Aufruf der Methode, um in weitere Teilarrays zu untergliedern

    if (i < r)
        quickSort(arr, i, r); // rekursiver Aufruf der Methode, um in weitere Teilarrays zu untergliedern

    // Wenn QuickSort durchgelaufen ist, dann gebe folgendes aus:
    if (i == 0 || j == 0)
    {
        printf("QuickSort aufsteigend: '%s'", arr);
    }
}
*/
/*
// -------------------------------------------------------Aufgabe 2.1------------------------------------------------------- //
int linearSearch(char arr[], char x)
{
    int laenge = strlen(arr);

    for (int i = 0; i < laenge; i++)
    {
        if (arr[i] == x) // wenn gesuchtes Element an der aktuellen Stelle im Array steht, gib den Index zurück
        {
            return i;
        }
    }
    return -1; // ansonsten gib -1 zurück
}
*/
// -------------------------------------------------------Aufgabe 2.2------------------------------------------------------- //
int binarySearch(char arr[], char x)
{
    int n = strlen(arr); // Stellt die Länge des Strings bereit

    // -------------------------------------Anfang BubbleSort------------------------------------- //

    // BubbleSort von den Folien
    while (n) // Läuft solange, bis n den Wert 0 erreicht hat --> steht für false
    {
        for (int i = 1; i < n; i++) // vergleiche die aktuelle Stelle mit der Stelle davor
        {
            if (arr[i - 1] > arr[i]) // Tauschen des Größer-Kleiner-Vergleichsoperators, um absteigende Reihenfolge zu garantieren // Vergleichen der ASCII-Integerwerte der chars
            {
                char tmp = arr[i];   // Speicherung des char der aktuellen Position in einer temp-Variable
                arr[i] = arr[i - 1]; // an der aktuellen Postion wird nun der char aus der vorherigen Position gespeichert
                arr[i - 1] = tmp;    // an die vorherige Position wird der char der temp-Variable gespeichert
            }
        }
        n--;
    }

    printf("Der sortierte String lautet: '%s' und wir suchen jetzt im Anschluss nach dem Index des Suchschluessels. \n", arr);

    // -------------------------------------Ende BubbleSort------------------------------------- //

    n = strlen(arr); // Neuinitialisierung von n, da n sonst nach der while-Schleife 0 ist

    int middle = 0;
    int left = 0;
    int right = n - 1;

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
