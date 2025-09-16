#ifndef LIST_H
#define LIST_H

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

Node* createNode(char* data);
void insertAtBeginning(Node** head, char* data);
void freeList(Node** head);
void printList(Node* head);

#endif // LIST_H
