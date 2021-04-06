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
