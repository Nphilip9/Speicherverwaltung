#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "main.h"

NODE *head = NULL;
int nextFitLastAllocated = 0;

int main() {
    // Speicher vorreservieren
    for (int i = 0; i < SIZE; ++i) {
        createNewElement(0, "Hole");
    }
    srand(time(NULL));

    menu();
    return 0;
}

void menu() {
    while(1) {
        int action, memSize, algorithm;
        char *pName = malloc(10 * sizeof(char));
        printf("Was moechtest du machen?\n");
        printf("1. Prozess zu Speicher hinzufuegen\n");
        printf("2. Prozess aus Speicher loeschen\n");
        printf("3. Speicher ausgeben\n");
        scanf("%d", &action);
        switch (action) {
            case 1:
                printf("Wie viel Speicher moechtest du verwenden?\n");
                scanf("%d", &memSize);
                printf("Wie soll der Prozess heissen?\n");
                scanf("%s", pName);
                getchar();
                printf("Welchen Algorithmus moechtest du verwenden?\n");
                printf("1. Best Fit\n");
                printf("2. First Fit\n");
                printf("3. Next Fit\n");
                printf("4. Worst Fit\n");
                scanf("%d", &algorithm);
                addProcess(algorithm, memSize, pName, rand() % 1000 + 1);
                break;
            case 2:
                printf("Gib den Namen des Prozesses ein den du löschen möchtest: ");
                scanf("%s", pName);
                removeProcess(pName);
                break;
            case 3:
                printList();
                break;
            default:
                break;
        }
    }
}

void createNewElement(int data, char *name) {
    NODE *newElement = malloc(sizeof(NODE));
    newElement->data = data;
    newElement->name = name;
    newElement->next = NULL;

    if(head == NULL) {
        head = newElement;
    } else {
        NODE *current = head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = newElement;
    }
}

void addProcess(int algorithm, int size, char *newName, int newData) {
    int firstFitIndex = 0;
    switch (algorithm) {
        case 1:
            firstFitIndex = bestFit(size);
            break;
        case 2:
            firstFitIndex = firstFit(size);
            break;
        case 3:
            firstFitIndex = nextFit(size);
            break;
        case 4:
            firstFitIndex = worstFit(size);
            break;
    }

    int index = firstFitIndex;
    int count = 0;
    NODE *firstElement = head;
    while(firstElement->next != NULL && count != firstFitIndex) {
        firstElement = firstElement->next;
        count++;
    }

    NODE *currentFitElement = firstElement;
    printf("%p\n", currentFitElement);
    while(currentFitElement->next != NULL && index != firstFitIndex + size) {
        currentFitElement->data = newData;
        currentFitElement->name = newName;
        index++;
        currentFitElement = currentFitElement->next;
    }
}

// FirstFit sucht den ersten frien Speicherplatz der grossgenug ist
int firstFit(unsigned int size) {
    int counter = 0;
    int index = 0;
    for(NODE *current = head; current != NULL; current = current->next) {
        if(strcmp(current->name, "Hole") == 0) {
            counter++;
            if(counter == size) {
                return index + 1 - size;
            }
        } else {
            counter = 0;
        }
        index++;
    }
    return -1;
}

int nextFit(unsigned int size) {
    int nextBlockIndex = nextFitLastAllocated;
    int blockSize = 0;
    // while (blockSize < size) {
    for (NODE *current = head; current != NULL; current = current->next) {
        if(blockSize < size) {
            if (strcmp(current->name, "Hole") == 0) { // 0 bedeutet, dass der Speicherplatz frei ist
                blockSize++;
            } else {
                blockSize = 0;
            }
            nextBlockIndex = (nextBlockIndex + 1) % SIZE;
            if (nextBlockIndex == nextFitLastAllocated) { // Wir haben den Speicher einmal durchsucht
                break;
            }
        }
    }
    if (blockSize < size) {
        nextBlockIndex = -1;
    }
    nextFitLastAllocated = nextBlockIndex - size;
    return nextBlockIndex - size;
}

int bestFit(unsigned int pSize) {
    int bestBlockIndex = -1;
    int smallestBlockSize = 0;
    int index = 0;
    for (NODE *current = head; current != NULL; current = current->next) {
        if (strcmp(current->name, "Hole") == 0) {
            int blockSize = 0;
            int j = index;
            // This loop counts each consecutive free block
            // It runs until the end of the list is reached or until the block size is greater than the requested size
            NODE *tmp = current;
            while (tmp != NULL && strcmp(tmp->name, "Hole") == 0 && blockSize < pSize) {
                blockSize++;
                tmp = tmp->next;
                j++;
            }
            // This if block checks if the block size is greater than or equal to the requested size and smaller than the current smallest block size found so far
            // If the condition is true, the smallest block size is updated and the index of the first block of the smallest size is also saved
            if (blockSize >= pSize && (smallestBlockSize == 0 || blockSize < smallestBlockSize)) {
                bestBlockIndex = index;
                smallestBlockSize = blockSize;
            }
        }
        index++;
    }
    // Returns the index of the first block of the smallest size found
    return bestBlockIndex;
}

// WorstFit sucht den größtmöglichen freien Speicherplatz
int worstFit(unsigned int size) {
    int worstBlockIndex = -1;
    int largestBlockSize = 0;
    int index = 0;
    for(NODE *current = head; current != NULL; current = current->next) {
        if (current->data == 0) {
            int blockSize = 0;
            int j = index;
            while (j != SIZE && current->data == 0) {
                blockSize++;
                j++;
            }
            if (blockSize >= size && blockSize > largestBlockSize) {
                worstBlockIndex = index;
                largestBlockSize = blockSize;
            }
        }
        index++;
    }
    return worstBlockIndex;
}

void printList() {
    NODE *current = head;
    while(current != NULL) {
        printf("Name: %s | Inhalt: %d | Addresse: %p\n", current->name, current->data, current);
        current = current->next;
    }
}

void removeProcess(char *pName) {
    NODE *current = head;
    while(current->next != NULL) {
        if(strcmp(current->name, pName) == 0) {
            current->data = 0;
            current->name = "Hole";
        }
        current = current->next;
    }
}