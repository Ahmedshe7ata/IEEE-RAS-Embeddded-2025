// Free the entire linked list
void freeList(struct Node** head) {
    struct Node* current = *head;
    struct Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    *head = NULL; // Important: clear the head pointer
}
