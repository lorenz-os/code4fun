#include <stdio.h>
#include <stdlib.h>

#define ArrayGröße 10

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

// globale Variablen für die Queue
int frontPointer = -1;
int rearPointer = -1;
int amount = 0;

// Initalisierung der Structs
struct Queue queue;

// Prozeduren aus Aufgabe 1 bekanntmachen
void enqueue(int e);
int dequeue();
int front();
int size();
void empty();

// Prozeduren aus Aufgabe 2 bekanntmachen
void enqueueList(int e);
int dequeueList();
int frontList();
int sizeList();
void emptyList();

// Structs definieren!
struct Queue
{
    int arr[ArrayGröße];
};

// Knoten, der die eigentlichen Daten enthält
typedef struct node
{
    int value;         // Daten werden hier gespeichert
    struct node *nxt;  // Pointer auf den Nachfolger
    struct node *prev; // Pointer auf den Vorgänger
} Node;

// Struct der Liste, in der sich die Knoten befinden
struct List
{
    int counter;     // zählt die Anzahl der Nodes (Knoten)
    Node *firstNode; // Pointer auf den ersten Node in der Liste
    Node *lastNode;  // Pointer auf den letzten Node in der Liste
} list;

// ---------------------Prozeduren zu Aufgabe 1--------------------- //
void enqueue(int e)
{
    if (rearPointer == ArrayGröße - 1) // wenn rearPointer an letzter Stelle im Array
    {
        rearPointer = 0;                 // dann setze ihn auf die erste Stelle im Array
        if (rearPointer != frontPointer) // wenn frontPointer nicht an erster Stelle im Array steht, dann ist Platz für neues Element
        {
            queue.arr[rearPointer] = e; // Element wird an erster Stelle eingefügt
            amount++;                   // Anzahl wird erhöht
        }
        else
        {
            rearPointer = ArrayGröße - 1; // wenn Queue den Anfang des Arrays belegt, dann wird rearPointer wieder auf die letzte Stelle gesetzt, da Queue voll ist
            printf("Queue ist voll!\n");
        }
    }
    else if (frontPointer == -1 & rearPointer == -1) // wenn noch kein Element in der Queue ist
    {
        frontPointer = 0; // werden beide Pointer auf die erste Stelle im Array gesetzt
        rearPointer = 0;
        queue.arr[rearPointer] = e; // und Element wird an erste Stelle im Array gesetzt
        amount++;                   // Anzahl wird erhöht
    }
    else if (rearPointer == frontPointer - 1) // wenn rearPointer eine Stelle vor frontPointer steht, ist kein freier Platz mehr für neues Element da
    {
        printf("Queue ist voll!\n");
    }
    else
    {
        rearPointer++;              // rearPointer wird um eins erhöht
        queue.arr[rearPointer] = e; // Element wird an leere Stelle eingefügt
        amount++;                   // und Anzahl wird erhöht
    }
}

int dequeue()
{
    if (frontPointer == -1 && rearPointer == -1) // wenn sowohl front- als auch rearPointer vor der Queue stehen, also keine Elemente in der Queue vorhanden sind
    {
        printf("Keine Elemente vorhanden!\n");
        return -1;
    }
    if (frontPointer == rearPointer) // wenn beide Pointer auf erstes Element zeigen, wird Queue komplett geleert
    {
        frontPointer = -1;
        rearPointer = -1;
        amount = 0;
    }
    int tmp = queue.arr[frontPointer]; // vorheriges Element speichern, bevor es gelöscht wird
    frontPointer++;                    // frontPointer wird um eins nach rechts in der Queue verschoben
    amount--;                          // Anzahl der Elemente in Queue wird verringert
    return tmp;                        // Element wird zurückgegeben
}

int front()
{
    if (frontPointer == -1) // wenn frontPointer vor der Queue steht, also keine Elemente in der Queue vorhanden sind
    {
        printf("Keine Elemente vorhanden!\n");
        return -1;
    }
    printf("%d \n", queue.arr[frontPointer]); // gibt erstes Element der Queue aus
    return queue.arr[frontPointer];           // returned erstes Element der Queue
}

int size()
{
    return amount; // returned die Anzahl und damit die Größe der Queue
}

void empty()
{
    if (amount == 0) // wenn kein Element in der Queue ist
    {
        printf("Queue ist leer!\n");
    }
    else
    {
        printf("Queue ist nicht leer!\n");
    }
}

// ---------------------Prozeduren zu Aufgabe 2--------------------- //

Node *createNode(int f)
{

    Node *nP = (Node *)malloc(sizeof(Node)); // Speicher-Alloziierung für neuen Knoten

    if (nP != NULL) // wenn Speicher freigegeben wurde
    {
        nP->value = f;   // übergebener Wert wird in neuem Knoten gespeichert
        nP->prev = NULL; // prev- und nxt-Pfeil werden auf NULL gesetzt und später in die Liste eingebunden
        nP->nxt = NULL;
    }

    return nP; // Pointer auf den neuen Knoten wird zurückgegeben
}

void enqueueList(int e)
{

    Node *newNode = createNode(e); // Erstellen eines neuen Knotens

    if (list.firstNode == NULL) // wenn kein Knoten in der Liste ist, werden beide List-Pfeile auf den neuen Knoten gesetzt
    {
        list.firstNode = newNode;
        list.lastNode = newNode;
    }
    else
    {
        list.lastNode->nxt = newNode;  // nxt-Pfeil vom aktuell letzten Knoten zeigt nun auf den neuen Knoten
        newNode->prev = list.lastNode; // prev-Pfeil von neuem Knoten zeigt auf letzten Knoten der Liste
        list.lastNode = newNode;       // last-Pfeil von Liste zeigt nun auf den neuen Knoten, somit ist neuer Knoten der neue letzte Knoten in der Liste
    }

    list.counter++; // Anzahl der Knoten wird erhöht
}

int dequeueList()
{
    if (list.firstNode != NULL) // wenn es (mind.) einen Knoten in der Liste gibt
    {
        int firstVal = list.firstNode->value; // Wert des ersten Knotens wird gespeichert
        if (list.firstNode->nxt != NULL)      // gibt es einen Nachfolger :)
        {
            list.firstNode = list.firstNode->nxt; // der erste Knoten ist nun der vorher zweite Knoten
            list.firstNode->prev->nxt = NULL;     // vom Vorgängerknoten den next-Pfeil auf NULL setzen
            list.firstNode->prev = NULL;          // vom aktuell neuen ersten Knoten den prev-Pfeil auf NULL setzen
        }
        else // wenn es nur noch einen Knoten gibt, werden beide List-Pfeile wieder auf NULL gesetzt
        {
            list.lastNode = NULL;
            list.firstNode = NULL;
        }
        list.counter--;  // Anzahl der Knoten wird in der Liste verringert
        return firstVal; // Wert des (nun entfernten) ersten Knotens wird zurückgegeben
    }
    else // wenn kein Knoten mehr in der Liste ist
    {
        printf("Liste ist leer!\n");
        return -1;
    }
}

int frontList()
{
    if (list.firstNode == NULL) // wenn Liste leer ist
    {
        printf("Keine Elemente vorhanden!\n");
        return -1;
    }
    printf("%d \n", list.firstNode->value); // Wert des ersten Knotens wird ausgegeben
    return list.firstNode->value;           // Wert des ersten Knotens wird zurückgegeben
}

int sizeList()
{
    return list.counter; // Anzahl der Knoten wird zurückgegeben
}

void emptyList()
{
    if (list.counter == 0) // wenn die Liste leer ist
    {
        printf("Liste ist leer!\n");
    }
    else
    {
        printf("Liste ist nicht leer!\n");
    }
}

int main()
{
    // ---------------------Aufgabe 1 + 3--------------------- //
    printf("-------------------Aufgabe 1 + 3-------------------\n");
    enqueue(7); // 7,
    enqueue(4); // 7, 4,
    enqueue(9); // 7, 4, 9,
    enqueue(0); // 7, 4, 9, 0,
    enqueue(6); // 7, 4, 9, 0, 6,
    enqueue(9); // 7, 4, 9, 0, 6, 9,

    enqueue(7);                 // 7, 4, 9, 0, 6, 9, 7,
    enqueue(4);                 // 7, 4, 9, 0, 6, 9, 7, 4,
    enqueue(9);                 // 7, 4, 9, 0, 6, 9, 7, 4, 9,
    enqueue(0);                 // 7, 4, 9, 0, 6, 9, 7, 4, 9, 0
    enqueue(6);                 // Queue ist voll
    enqueue(9);                 // Queue ist voll
    printf("%d \n", size());    // 10
    printf("%d \n", dequeue()); // 7
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    printf("%d \n", dequeue()); // 7

    printf("\n");
    // ---------------------Aufgabe 2--------------------- //
    printf("-------------------Aufgabe 2 + 3-------------------\n");
    printf("%d \n", sizeList()); // 0
    emptyList();                 // Liste ist leer!

    // Matrikelnummer Lorenzo Schnobl: 749069
    enqueueList(7);
    enqueueList(4);
    enqueueList(9);
    enqueueList(0);
    enqueueList(6);
    enqueueList(9);

    enqueueList(7);
    enqueueList(4);
    enqueueList(9);
    enqueueList(0);
    enqueueList(6);
    enqueueList(9);                 // 7, 4, 9, 0, 6, 9, 7, 4, 9, 0, 6, 9
    printf("%d \n", sizeList());    // 12
    frontList();                    // 7
    emptyList();                    // Liste nicht leer
    printf("%d \n", dequeueList()); // 7
    printf("%d \n", sizeList());    // 11
    frontList();                    // 4
    dequeueList();
    dequeueList();
    dequeueList();
    dequeueList();
    dequeueList();
    printf("%d \n", dequeueList()); // 7
    printf("%d \n", sizeList());    // 5
    frontList();                    // 4
}

/*	

Vielen lieben Dank für Ihre Mühen in diesem Modul!

(\_/)
( •,•)
(")_(")

*/