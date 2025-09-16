#include <stdio.h>
#include <stdlib.h>
#include <list.h>


Node* createNode(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL ) {
        perror("Failed to allocate memory for new node");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, char* data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}


void freeList(Node** head) {
    Node* current = *head;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    *head = NULL;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}


