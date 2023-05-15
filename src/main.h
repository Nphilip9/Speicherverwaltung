#ifndef MAIN
#define MAIN

    #define ALGORITHM_BEST_FIT 1
    #define ALGORITHM_FIRST_FIT 2
    #define ALGORITHM_NEXT_FIT 3
    #define ALGORITHM_WORST_FIT 4

    #define MEMORY_SIZE 128
    #define MAX_PROCESS_NAME_LENGTH 5
    typedef struct node {
        int data;
        char *name;
        struct node *next;
    } NODE;

    extern void menu();
    extern void createNewElement(int, char *);
    extern void addProcess(int, int, char *, int);
    extern void removeProcess(char *);
    extern void printList();
    extern void freeAndExit();

    extern int processExists(char *);
    extern int getFreeMemSize();

    // FirstFit sucht den ersten freien Speicherplatz der gross genug ist
    extern int firstFit(unsigned int);

    // BestFit sucht die kleinst mögliche Lücke die entweder gleich gross oder größer ist als der angeforderte Speicher
    extern int bestFit(unsigned int);

    // NextFit fängt beim erstem Durchlauf, an der ersten Stelle der LinkedList an,
    // merkt sich dann aber wo die Suche aufgehört hat, und startet die nächste Suche von dieser Stelle aus
    extern int nextFit(unsigned int);

    // WorstFit sucht den größtmöglichen freien Speicherplatz
    extern int worstFit(unsigned int);
#endif