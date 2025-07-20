#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at specific position (0-based index)
void insertAtPosition(struct Node** head, int value, int position) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        // First node in the circular list
        newNode->next = newNode;
        *head = newNode;
        return;
    }

    if (position == 0) {
        // Insert at beginning (special handling)
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        newNode->next = *head;
        last->next = newNode;
        *head = newNode;
        return;
    }

    // Insert at position > 0
    struct Node* temp = *head;
    int index = 0;

    while (index < position - 1 && temp->next != *head) {
        temp = temp->next;
        index++;
    }

    // Insert after 'temp'
    newNode->next = temp->next;
    temp->next = newNode;
}

// Print circular linked list once (stop when return to head)
void printCircularList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head)\n");
}
