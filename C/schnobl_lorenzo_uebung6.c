#include <stdio.h>
#include <stdlib.h>
#define MAXCHAR 17

/*
*  Diese Aufgabe ist in Gruppenarbeit entstanden!
*  Folgende Studierende haben an der Enwicklung der Lösung mitgewirkt:
*  - Tristan Grobasch (1278200)
*  - Johannes Jäger (1258390)
*  - Lorenzo Schnobl (749069) 
*  - Marie Hergenröder (1258246)
*
*  Alle Studierenden sind in der Lage, die Aufgabe selbstständig zu erklären und den Entwicklungsprozess zu erläutern!
*  
*/

typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
} Node;

// Bekanntmachung der Funktionen
void getDataFromFile(const char *file_name);
Node *create(int value);
Node *insert(Node *nP, int value);
Node *search(Node *nP, int suchschluessel);
void print(Node *knoten);

// Null-Pointer für root-Knoten
Node *root = NULL;

// --------------------- Prozedur zum Einlesen einer Datei --------------------- //
void getDataFromFile(const char *file_name) // Methode zum Auslesen der einzelnen Zeilen der Datei
{
    FILE *file = fopen(file_name, "r"); // Öffnen der Datei
    int data = 0;                       // temporäre Variable für einzelne Werte der Zeilen
    int index = 0;

    while (!feof(file)) // solange nicht am Ende der Datei angekommen, mache Folgendes
    {
        fscanf(file, "%d", &data); // Scannt zeilenweise int-Werte
        root = insert(root, data); // fügt Knoten in Baum mit Wert data ein
    }
    fclose(file); // schließt Datei, wenn am Ende angekommen
}

// --------------------- Prozeduren zu Aufgabe 1 --------------------- //

Node *create(int value)
{

    Node *nP = (Node *)malloc(sizeof(Node)); // Speicher-Alloziierung für neuen Knoten

    if (nP != NULL) // wenn Speicher freigegeben wurde
    {
        nP->value = value; // übergebener Wert wird in neuem Knoten gespeichert
        nP->left = NULL;   // left- und right-Kante werden auf NULL gesetzt und später im Baum eingebunden
        nP->right = NULL;
    }

    return nP; // Pointer auf den neuen Knoten wird zurückgegeben
}

Node *insert(Node *nP, int newValue)
{
    if (nP == NULL)
    {
        nP = create(newValue);
    }
    else
    {
        if (nP->value > newValue) // wenn der aktuelle Wert größer als der neue Wert
        {
            nP->left = insert(nP->left, newValue); // left zeigt dann auf NULL, deshalb insert
        }
        else
        {
            nP->right = insert(nP->right, newValue);
        }
    }
    return nP;
}

Node *search(Node *nP, int suchschluessel)
{
    if (nP->value > suchschluessel)
    {
        if (nP->left != NULL)
        {
            search(nP->left, suchschluessel);
        }
        else
        {
            printf("Der Wert %d wurde nicht gefunden \n", suchschluessel);
        }
    }
    if (nP->value < suchschluessel)
    {
        if (nP->right != NULL)
        {
            search(nP->right, suchschluessel);
        }
        else
        {
            printf("Der Wert %d wurde nicht gefunden \n", suchschluessel);
        }
    }
    if (nP->value == suchschluessel)
    {
        printf("Der Wert %d befindet sich im Baum \n", suchschluessel);
    }
    return nP;
}

void print(Node *knoten)
{
    if (knoten->left != NULL)
    {
        print(knoten->left);
    }
    printf("%d ", knoten->value);
    if (knoten->right != NULL)
    {
        print(knoten->right);
    }
}

int main(int argc, char const *argv[])
{
    // ---------------------Aufgabe 1--------------------- //
    printf("Datei wird eingelesen! \n");
    getDataFromFile("Baum.txt");
    printf("Baum wurde erstellt! \n");
    search(root, 46);
    search(root, 22);
    print(root);
    return 0;
}

/*	

(\_/)
( •,•)
(")_(")

*/