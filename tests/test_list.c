#include "../src/list.h"
#include <assert.h>

int main() {
    Node* head = NULL;

    insertAtBeginning(&head, "test1");
    insertAtBeginning(&head, "test2");
    insertAtBeginning(&head, "test3");
    insertAtBeginning(&head, "test4");

    assert(isValInlist("test", head) == 0);
    assert(isValInlist("test1", head) == 1);

    freeList(&head);
}
