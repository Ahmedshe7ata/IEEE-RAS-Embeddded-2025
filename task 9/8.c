#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack {
    int items[MAX];
    int top;
};

// Initialize
void init(struct Stack* s) {
    s->top = -1;
}

// Check empty/full
int isEmpty(struct Stack* s) {
    return s->top == -1;
}
int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

// Push
void push(struct Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = value;
}

// Pop
int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->items[(s->top)--];
}

// Peek
int peek(struct Stack* s) {
    if (isEmpty(s)) return -1;
    return s->items[s->top];
}

// Print stack (top to bottom)
void printStack(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack (Top → Bottom): ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->items[i]);
    }
    printf("\n");
}

// Swap top two elements
void swapTopTwo(struct Stack* s) {
    if (s->top < 1) {
        printf("Cannot swap: Less than 2 elements.\n");
        return;
    }
    int temp = s->items[s->top];
    s->items[s->top] = s->items[s->top - 1];
    s->items[s->top - 1] = temp;
}
