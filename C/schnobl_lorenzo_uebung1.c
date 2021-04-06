#include <stdio.h>
#include <math.h>

// Aufgabe 1​
/*
int main()
{
    double radius;
    double flaeche;
    double division;
    double volumen;

    // Zahl einscannen ohne \n sorgt dafür, dass die Zahl in derselben Zeile steht.
    printf("Bitte Radius angeben: ");
    scanf("%lf", &radius);
    
    // Mathematische Implementierung von PI
    flaeche = M_PI * (radius * radius);
    printf("Flaeche %.2lf \n", flaeche);

    // Mit dem eingescannten Wert weiterrechnen
    division = 4.0/3.0; 
    volumen = (division) * M_PI * (radius * radius * radius);
    printf("Volumen %.2lf", volumen);
    return 0; 
}
*/

// Aufgabe 2
/*
int main()
{
    double radius;
    double division;
    
    // Bekanntmachung mit dem Compiler (Deklaration)
    double flaechenBerechnung(double radius);
    double volumenBerechnung(double radius);

    // Zahl einscannen ohne \n sorgt dafür, dass die Zahl in derselben Zeile steht.
    printf("Bitte Radius angeben: ");
    scanf("%lf", &radius);
    
    // Aufruf der Flächenberechnungsfunktion
    printf("Flaeche %.2lf \n", flaechenBerechnung(radius));

    // Aufruf der Volumenberechnung 
    printf("Volumen %.2lf", volumenBerechnung(radius));
    
    return 0; 
}

// Berechnung der Fläche mit vorgegebener Flächenformel und eingegebenem Radiuswert
double flaechenBerechnung(double radius)
{
    double flaeche;

    flaeche = M_PI * (radius * radius);
    return flaeche;
}

// Berechnung des Volumens mit vorgegebener Volumenformel und eingegebenem Radiuswert
double volumenBerechnung(double radius) 
{
    double volumen;
    double division;

    division = 4.0/3.0;

    volumen = (division) * M_PI * (radius * radius * radius);
    return volumen;
}
*/

// Aufgabe 3
int main()
{
    int matrikelnummerL;

    void meinNameL(int matrikelnummerL);

    // Lorenzo Schnobl, 749069
    printf("Bitte geben Sie ihre Matrikelnummer ein: ");
    scanf("%d", &matrikelnummerL);
    printf("\n");
    meinNameL(matrikelnummerL);

    return 0;
}

void meinNameL(int matrikelnummerL)
{
    // Matrikelnummer: 749069
    // Vorname: 76 111 114 101 110 122 111  Nachname: 83 99 104 110 111 98 108
    // Nur einmal pro Buchstabe

    int lL = 'L';
    int o = 'o';
    int r = 'r';
    int e = 'e';
    int n = 'n';
    int z = 'z';
    int leer = ' ';
    int sS = 'S';
    int c = 'c';
    int h = 'h';
    int b = 'b';
    int l = 'l';

    int ascii[15] = {lL, o, r, e, n, z, o, leer, sS, c, h, n, o, b, l};

    int i;
    int tempLetter;

    if (matrikelnummerL == 749069)
    {
        for (i = 0; i < 15; i++)
        {
            tempLetter = ((matrikelnummerL % 10) - 9) + ascii[i];
            printf("%c", tempLetter);
        }
        printf("\n");
    }
    else
    {
        printf("Die Matrikelnummer ist leider nicht korrekt! Bitte Versuche es erneut! \n");
    }
}