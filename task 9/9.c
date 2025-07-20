#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

struct Queue {
    char items[SIZE];
    int front;
    int rear;
};

// Initialize queue
void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = -1;
}

// Check if empty
int isEmpty(struct Queue* q) {
    return q->front > q->rear;
}

// Check if full
int isFull(struct Queue* q) {
    return q->rear == SIZE - 1;
}

// Enqueue
void enqueue(struct Queue* q, char value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    q->items[++(q->rear)] = value;
}

// Dequeue
char dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return '\0';
    }
    return q->items[(q->front)++];
}

// Print queue (for testing)
void printQueue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue (Front → Rear): ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%c ", q->items[i]);
    }
    printf("\n");
}
