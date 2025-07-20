#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure
struct Stack {
    int items[MAX];
    int top;
};

// Initialize stack
void init(struct Stack* s) {
    s->top = -1;
}

// Check if stack is full
int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

// Check if stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Push operation
void push(struct Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->items[++(s->top)] = value;
}

// Pop operation
int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        return -1;
    }
    return s->items[(s->top)--];
}

// Peek top value
int peek(struct Stack* s) {
    if (isEmpty(s)) return -1;
    return s->items[s->top];
}
