#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at position (0-based index)
void insertAtPosition(struct Node** head, int value, int position) {
    struct Node* newNode = createNode(value);

    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    int index = 0;

    while (temp != NULL && index < position - 1) {
        temp = temp->next;
        index++;
    }

    if (temp == NULL) {
        printf("Position %d is out of bounds!\n", position);
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Get value at position (0-based index)
int getValueAtPosition(struct Node* head, int position) {
    int index = 0;
    while (head != NULL) {
        if (index == position)
            return head->data;
        head = head->next;
        index++;
    }
    printf("Position %d is out of bounds!\n", position);
    return -1; // Error value
}

// Print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Test everything
int main() {
    struct Node* head = NULL;

    insertAtPosition(&head, 10, 0); // [10]
    insertAtPosition(&head, 20, 1); // [10 -> 20]
    insertAtPosition(&head, 30, 2); // [10 -> 20 -> 30]
    insertAtPosition(&head, 15, 1); // [10 -> 15 -> 20 -> 30]

    printList(head);

    int pos = 2;
    int value = getValueAtPosition(head, pos);
    if (value != -1)
        printf("Value at position %d = %d\n", pos, value);

    // Insert a new node at same position
    insertAtPosition(&head, 99, pos);
    printList(head);

    return 0;
}
