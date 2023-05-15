#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "main.h"

NODE *head = NULL;
NODE *lastElement = NULL;

int main() {
    // Initialisieren der srand funktion für abwechselnde Zufallszahlen
    srand(time(NULL));

    // Speicher vorreservieren. Register Schlüsselwort für schnelleren Aufruf der variable i
    for (register int i = 0; i < MEMORY_SIZE; ++i) {
        createNewElement(0, "Hole");
    }

    menu();
    return 0;
}

/**
 * @brief Menu der Speicherverwaltung
 */
void menu() {
    while(1) {
        int action, memSize, algorithm, freeMemSize;
        char *pName = malloc(MAX_PROCESS_NAME_LENGTH * sizeof(char));
        printf("Was moechtest du machen?\n");
        printf("1. Prozess zu Speicher hinzufuegen\n");
        printf("2. Prozess aus Speicher loeschen\n");
        printf("3. Speicher ausgeben\n");
        printf("4. Exit\n");
        scanf("%d", &action);
        switch (action) {
            case 1:
                freeMemSize = getFreeMemSize();
                printf("Wie viel Speicher moechtest du verwenden? (Freier Speicherplatz: %d Bit)\n", freeMemSize);
                do {
                    scanf("%d", &memSize);
                    if(memSize > freeMemSize) {
                        printf("Die eingegebene groesse ist zu gross! Freier Speicherplatz: %d Bit\n", freeMemSize);
                    } else {
                        break;
                    }
                } while(1);
                do {
                    printf("Geben Sie einen Namen fuer den Prozess (max. %d Zeichen) ein: ", MAX_PROCESS_NAME_LENGTH);
                    scanf("%s", pName);
                    if (processExists(pName) != 0) {
                        printf("Dieser Prozess existiert bereits! Waehle einen anderen Namen oder loeschen den anderen Prozess!\n");
                    } else if (strlen(pName) > MAX_PROCESS_NAME_LENGTH) {
                        printf("Dieser Name ist zu lang er darf nur maximal %d zeichen lang sein!\n",
                               MAX_PROCESS_NAME_LENGTH);
                    } else {
                        break;
                    }
                } while (1);
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
                printf("Gib den Namen des Prozesses ein den du loeschen moechtest: ");
                scanf("%s", pName);
                removeProcess(pName);
                break;
            case 3:
                printList();
                break;
            case 4:
                freeAndExit();
                break;
            default:
                break;
        }
    }
}

/**
 * @brief Erstellt ein neues Element vom struct NODE
 * @param data Inhalt des Prozesses
 * @param name Name des Prozesses
 */
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

/**
 * @brief Überschreibt die Liste mit den neuen Prozess
 * @param algorithm Ausgewählte Algorithmus
 * @param size Die grösse des Prozesses
 * @param newName Der Name des Prozesses
 * @param newData Inhalt des Prozesses
 */
void addProcess(int algorithm, int size, char *newName, int newData) {
    int firstIndex = 0;
    switch (algorithm) {
        case ALGORITHM_BEST_FIT:
            firstIndex = bestFit(size);
            break;
        case ALGORITHM_FIRST_FIT:
            firstIndex = firstFit(size);
            break;
        case ALGORITHM_NEXT_FIT:
            firstIndex = nextFit(size);
            break;
        case ALGORITHM_WORST_FIT:
            firstIndex = worstFit(size);
            break;
        default:
            break;
    }

    int index = firstIndex;
    int count = 0;
    NODE *firstElement = head;
    while(firstElement->next != NULL && count != firstIndex) {
        firstElement = firstElement->next;
        count++;
    }

    NODE *currentFitElement = firstElement;
    while(currentFitElement->next != NULL && index != firstIndex + size) {
        currentFitElement->data = newData;
        currentFitElement->name = newName;
        index++;
        currentFitElement = currentFitElement->next;
    }
}

/**
 * @brief Sucht den ersten freien Speicherplatz der gross genug ist
 * @param size Die grösse des Prozesses
 * @return Gibt die Position der ersten freien Position an
 */
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

/**
 * @brief Fängt beim erstem Durchlauf, an der ersten Stelle der LinkedList an, merkt sich dann aber wo die Suche aufgehört hat, und startet die nächste Suche von dieser Stelle aus
 * @param size Die grösse des Prozesses
 * @return Gibt die Position der ersten freien Position an
 */
int nextFit(unsigned int size) {
    if(lastElement == NULL) {
        lastElement = head;
    }
    static int i = 0;
    int blockSize = 0;

    for (NODE *current = lastElement->next; current != lastElement; current = current->next) {
        if(current->next != NULL) {
            if (blockSize < size) {
                if (strcmp(current->name, "Hole") == 0) {
                    blockSize++;
                } else {
                    blockSize = 0;
                }
                i++;
            } else {
                lastElement = current;
                break;
            }
        } else {
            current = head;
            i = 0;
        }
    }
    return i - size;
}

/**
 * @brief Sucht die kleinst mögliche Lücke die entweder gleich gross oder größer ist als der angeforderte Speicher
 * @param size Die grösse des Prozesses
 * @return Gibt die Position der ersten freien Position an
 */
int bestFit(unsigned int size) {
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
            while (tmp != NULL && strcmp(tmp->name, "Hole") == 0 && blockSize < size) {
                blockSize++;
                tmp = tmp->next;
                j++;
            }
            // This if block checks if the block size is greater than or equal to the requested size and smaller than the current smallest block size found so far
            // If the condition is true, the smallest block size is updated and the index of the first block of the smallest size is also saved
            if (blockSize >= size && (smallestBlockSize == 0 || blockSize < smallestBlockSize)) {
                bestBlockIndex = index;
                smallestBlockSize = blockSize;
            }
        }
        index++;
    }
    // Returns the index of the first block of the smallest size found
    return bestBlockIndex;
}

/**
 * @brief Sucht den größtmöglichen freien Speicherplatz
 * @param size Die grösse des Prozesses
 * @return Gibt die Position der ersten freien Position an
 */
int worstFit(unsigned int size) {
    int worstBlockIndex = -1;
    int largestBlockSize = 0;
    int index = 0;
    for(NODE *current = head; current != NULL; current = current->next) {
        if (current->data == 0) {
            int blockSize = 0;
            int j = index;
            while (j != MEMORY_SIZE && current->data == 0) {
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

/**
 * @brief Gibt die Liste aus
 */
void printList() {
    NODE *current = head;
    int i = 0;
    while(current != NULL) {
        i++;
        printf("Nr. %d: Name: %s | Inhalt: %d | Addresse: %p\n", i, current->name, current->data, current);
        current = current->next;
    }
}

/**
 * @brief Löscht einen bestimmten Prozess
 * @param pName Name des Prozesses
 */
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

/**
 * @brief Schaut nach ob der angegebene Prozess bereits existiert
 * @param pName Name des Prozesses
 * @return 0 Wenn der Prozess nicht existiert
 */
int processExists(char *pName) {
    int exists = 0;
    for(NODE *current = head; current != NULL; current = current->next) {
        if(strcmp(current->name, pName) == 0) {
            exists = 1;
            break;
        }
    }
    return exists;
}

/**
 * @brief Berechnet wie viel noch Speicherplatz verfügbar ist
 * @return Gibt den verfügbaren Speicherplatz zurück
 */
int getFreeMemSize() {
    int freeMemSize = 0;
    for(NODE *current = head; current != NULL; current = current->next) {
        if(strcmp(current->name, "Hole") == 0) {
            freeMemSize++;
        }
    }
    return freeMemSize;
}

/**
 * @brief De-allokiert die LinkedList und schliesst das Programm mit EXIT_SUCCESS
 */
void freeAndExit() {
    NODE *current;
    while (head != NULL) {
        current = head;
        head = head->next;
        free(current);
    }
    exit(EXIT_SUCCESS);
}