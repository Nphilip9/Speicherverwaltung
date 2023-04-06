#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

NODE *head = NULL;

void createNewElement(int data, char *name);
void printList();

int main() {
    createNewElement(12, "Hallo");
    printList();
    return 0;
}

void createNewElement(int data, char *name) {
    NODE *newElement = malloc(sizeof(NODE));
    newElement->data = data;
    strcpy(newElement->name, name);

    if(head == NULL) {
        head = newElement;
    } else {
        NODE *current = head;
        while(current != NULL) {
            current = current->next;
        }
        current->next = newElement;
    }
}

void printList() {
    NODE *current = head;
    while(current != NULL) {
        printf("%s", current->name);
        current = current->next;
    }
}