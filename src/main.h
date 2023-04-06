#ifndef MAIN
#define MAIN
#define SIZE 64
    typedef struct node {
        int data;
        char *name;
        struct node *next;
    } NODE;

    extern void createNewElement(int, char *);
    extern void printList();
    extern void addProcess(char *, int);

    extern int bestFit(unsigned int);
    extern int firstFit(unsigned int);
    extern int nextFit(unsigned int);
    extern int worstFit(unsigned int);
#endif