#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List Node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert node at beginning
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    newNode->next = *head; // Point to old head

    if (*head != NULL)
        (*head)->prev = newNode; // Link back from old head

    *head = newNode; // Update head
}

// Print the list forward
void printForward(struct Node* head) {
    printf("Forward: ");
    while (head != NULL) {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
