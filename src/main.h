#ifndef MAIN
#define MAIN

    #define ALGORITHM_BEST_FIT 1
    #define ALGORITHM_FIRST_FIT 2
    #define ALGORITHM_NEXT_FIT 3
    #define ALGORITHM_WORST_FIT 4

    #define MEMORY_SIZE 1048 // Maximallänge der Liste
    #define MAX_PROCESS_NAME_LENGTH 5 // Maximallänge des Prozessnamens

    typedef struct node {
        int data; // Inhalt des Prozesses
        char *name; // Name des Prozesses
        struct node *next; // Nächstes Element in der Liste
    } NODE;

    // Listen relevante Funktionen
    extern void menu();
    extern void createNewElement(int, char *);
    extern void addProcess(int, int, char *, int);
    extern void removeProcess(char *);
    extern void freeAndExit();

    // Hilfsfunktionen
    extern int processExists(char *);
    extern int getFreeMemSize();
    extern void printList();

    // Algorithmen
    extern int firstFit(unsigned int);
    extern int bestFit(unsigned int);
    extern int nextFit(unsigned int);
    extern int worstFit(unsigned int);
#endif