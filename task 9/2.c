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

// Insert at the end
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Insert at the beginning
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

// Delete specific node by value
void deleteNode(struct Node** head, int value) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    // Node to delete is head
    if (temp != NULL && temp->data == value) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Search for node
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // Not found
    if (temp == NULL) {
        printf("Value %d not found.\n", value);
        return;
    }

    // Remove node
    prev->next = temp->next;
    free(temp);
}


void printListAndLength(struct Node* head) {
    int length = 0;
    struct Node* current = head;

    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        length++;
        current = current->next;
    }
    printf("NULL\nLength = %d\n", length);
}


int main() {
    struct Node* head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    printListAndLength(head);

    insertAtBeginning(&head, 5);
    printListAndLength(head);

    deleteNode(&head, 20);
    printListAndLength(head);

    deleteNode(&head, 99);  
    printListAndLength(head);

    return 0;
}
