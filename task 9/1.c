#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
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
    printf("NULL\n");
    printf("Length = %d\n", length);
}

int main() {
   
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    // Print the list and its length
    printListAndLength(head);

    return 0;
}
