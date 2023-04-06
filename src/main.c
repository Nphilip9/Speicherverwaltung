#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

NODE *head = NULL;
int nextFitLastAllocated = 0;

int main() {
    // Allocate memory
    for (int i = 0; i < SIZE; ++i) {
        createNewElement(0, "Hole");
    }

    addProcess("P1", 23);
    addProcess("P2", 45);

    printList();

    return 0;
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

void addProcess(char *newName, int newData) {
    int firstFitIndex = bestFit(5);
    printf("%d", firstFitIndex);
    int index = firstFitIndex;

    int count = 0;
    NODE *firstElement = head;
    while(firstElement->next != NULL && count != firstFitIndex) {
        firstElement = firstElement->next;
        count++;
    }

    NODE *currentFitElement = firstElement;
    printf("%p\n", currentFitElement);
    while(currentFitElement->next != NULL && index != firstFitIndex + 5) {
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