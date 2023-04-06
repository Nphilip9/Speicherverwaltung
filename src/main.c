#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

NODE *head = NULL;

void createNewElement(int, char *);
void printList();

int main() {
    printf("64-byte Ram-Verwaltung\n");
    printf("1. Prozess hinzufuegen\n");
    printf("2. Prozess loeschen\n");
    printf("3. BitMap ausgeben\n");

    int selected;
    scanf("%d", &selected);
    switch (selected) {
        case 1:
            printf("Wie viel Speicher moechtest du verwenden: ");
            int name, size, algorithm;
            scanf("%d", &size);
            printf("\nWie soll der Prozess heissen (waehle eine Zahl als Name): ");
            scanf("%d", &name);
            printf("\n 1. Best Fit");
            printf("\n 2. First Fit");
            printf("\n 3. Next Fit");
            printf("\n 4. Worst Fit");
            printf("\nWelchen algorithmus moechten sie verwenden: ");
            scanf("%d", &algorithm);
            break;
        case 2:
            printf("\nWelchen Prozess möchtest du aus dem Speicher entfernen: ");
            int pName;
            scanf("%d", &pName);
            break;
        case 3:
            printList();
            break;
        default:
            break;
    }
    printList();
    return 0;
}

// TODO:
void addProcess(int size, int data, char *name) {
    NODE **tmp = malloc(size * sizeof(NODE));
    for(int i = 0; i <= size; i++) {
        createNewElement(data, name);
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

void printList() {
    NODE *current = head;
    while(current != NULL) {
        printf("%s\n", current->name);
        current = current->next;
    }
}