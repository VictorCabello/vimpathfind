#include "../src/list.h"
#include <assert.h>
#include <stdio.h>

int main() {
    Node* head = NULL;

    insertAtBeginning(&head, "test1");
    insertAtBeginning(&head, "test2");
    insertAtBeginning(&head, "test3");
    insertAtBeginning(&head, "test4");

    int validator_counter = 0;

    printf("Validating the element number %d in the list\n",
           validator_counter + 1);
    if(strcmp(head->data, "test4")){
        fprintf(stderr, "Expect 'test%d' but got %s\n", validator_counter +
                1, head->data);
        return 1;
    }
    validator_counter++;
    head = head->next;
    printf("Validating the element number %d in the list\n",
           validator_counter + 1);
    if(strcmp(head->data, "test3")){
        fprintf(stderr, "Expect 'test%d' but got %s\n", validator_counter +
                1, head->data);
        return 1;
    }
    validator_counter++;
    head = head->next;
    printf("Validating the element number %d in the list\n",
           validator_counter + 1);
    if(strcmp(head->data, "test2")){
        fprintf(stderr, "Expect 'test%d' but got %s\n", validator_counter +
                1, head->data);
        return 1;
    }
    validator_counter++;
    head = head->next;
    printf("Validating the element number %d in the list\n",
           validator_counter + 1);
    if(strcmp(head->data, "test1")){
        fprintf(stderr, "Expect 'test%d' but got %s\n", validator_counter +
                1, head->data);
        return 1;
    }

    freeList(&head);
    return 0;
}
