#ifndef MAIN
#define MAIN

#define MEMORY_SIZE 64
#define MAX_PROCESS_NAME_LENGTH 10
    typedef struct node {
        int data;
        char *name;
        struct node *next;
    } NODE;

    extern void menu();
    extern void createNewElement(int, char *);
    extern void printList();
    extern void addProcess(int, int, char *, int);
    extern void removeProcess(char *);

    // FirstFit sucht den ersten frien Speicherplatz der grossgenug ist
    extern int firstFit(unsigned int);

    // BestFit sucht die kleinst mögliche lücke die entweder gleich gross oder größer ist als der angeforderte Speicher
    extern int bestFit(unsigned int);

    // NextFit fängt beim erstem durchlauf, an der ersten Stelle der LinkedList an,
    // merkt sich dann aber wo die suche aufgehört hat, und startet die nächste Suche von dieser Stelle aus
    extern int nextFit(unsigned int);

    // WorstFit sucht den größtmöglichen freien Speicherplatz
    extern int worstFit(unsigned int);
#endif