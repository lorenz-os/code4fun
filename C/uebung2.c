#include <stdio.h>
#define CIRCLE(x, y, xc, yc, r) ((x - xc) * (x - xc)) + ((y - yc) * (y - yc)) - (r * r)
typedef float DISPLAY[25][25];
/*
// Aufgabe 1
int main(int argc, char const *argv[])
{
    // Bekanntmachung der Funktion
    void ausgabe(float ergebnis);

    // Variablen anlegen
    float ergebnis; // Ergebnis der Gleichung wird hier gespeichert
    float xc = 12; // Mittelpunktkoordinaten des Kreises
    float yc = 12; // Mittelpunktkoordinaten des Kreises
    float r = 10; // Radius

    // Berechnung der Rasterung mit 2 for-Schleifen, um jede Dimension anzusprechen!
    for (float x = 0; x < 25; x++)
    {
       for (float y = 0; y < 25; y++)
       {
           // Gleichung für die Kreisrasterung
           ergebnis = ((x - xc)  *  (x - xc)) + ((y - yc)  *  (y - yc)) - (r * r);
           ausgabe(ergebnis);
       }
       printf("\n");
    }
    return 0;
}

// Ausgabe des Pixelbildschirms mit Kreis
void ausgabe(float ergebnis){
    (ergebnis > -10 && ergebnis < 10) ? printf(" # ") : printf(" - ");
} 
*/

// Aufgabe 2
int main(int argc, char const *argv[])
{
    // Bekanntmachung der Funktion
    void ausgabe(float ergebnis[25][25]);

    // Variablen anlegen
    char eingabe;
    float ergebnis[25][25]; // Ergebnis der Gleichung wird hier gespeichert
    float xc = 12;          // Mittelpunktkoordinaten des Kreises
    float yc = 12;          // Mittelpunktkoordinaten des Kreises
    float r = 10;           // Radius

    printf("Bitte geben Sie 'a' ein, um den Code aus Aufgabe 1 auszuführen. Bei jeglicher anderer Eingabe wird der Code aus Aufgabe 2 ausgeführt.\n");
    scanf("%c", &eingabe);

    if (eingabe == 'a')
    {
        printf("Aufgabe 1: \n");
        // Berechnung der Rasterung mit 2 for-Schleifen, um jede Dimension anzusprechen!
        for (int x = 0; x < 25; x++)
        {
            for (int y = 0; y < 25; y++)
            {
                // Gleichung für die Kreisrasterung
                ergebnis[x][y] = ((x - xc) * (x - xc)) + ((y - yc) * (y - yc)) - (r * r);
            }
        }
        ausgabe(ergebnis);
    }
    else
    {
        DISPLAY pixelflaeche;
        printf("Aufgabe 2: \n");
        for (int x = 0; x < 25; x++)
        {
            for (int y = 0; y < 25; y++)
            {
                // Gleichung für die Kreisrasterung
                pixelflaeche[x][y] = CIRCLE(x, y, xc, yc, r);
            }
        }
        ausgabe(pixelflaeche);
    }

    return 0;
}

// Ausgabe des Pixelbildschirms mit Kreis
void ausgabe(float ergebnis[25][25])
{
    for (int x = 0; x < 25; x++)
    {
        for (int y = 0; y < 25; y++)
        {
            (ergebnis[x][y] > -10 && ergebnis[x][y] < 10) ? printf(" # ") : printf(" - ");
        }
        printf("\n");
    }
}

/*
Lorenzo Schnobl
12.11.2020
*/
