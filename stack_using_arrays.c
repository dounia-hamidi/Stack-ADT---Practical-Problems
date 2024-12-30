#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100  // Maximum size of the stack

typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initialize_stack(Stack *stack) {
    stack->top = -1;
}

// Check if the stack is empty
bool is_empty(Stack *stack) {
    return stack->top == -1;
}

// Check if the stack is full
bool is_full(Stack *stack) {
    return stack->top == MAX - 1;
}

// Push an element onto the stack
void push(Stack *stack, int value) {
    if (is_full(stack)) {
        printf("Stack Overflow! Cannot push %d.\n", value);
        return;
    }
    stack->arr[++stack->top] = value;
    printf("Pushed %d onto the stack.\n", value);
}

// Pop an element from the stack
int pop(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;  // Return -1 to indicate an error
    }
    return stack->arr[stack->top--];
}

// Peek at the top element of the stack
int peek(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty! Cannot peek.\n");
        return -1;  // Return -1 to indicate an error
    }
    return stack->arr[stack->top];
}

// Display all elements in the stack
void display(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    Stack stack;
    initialize_stack(&stack);

    // Demonstrate stack operations
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    display(&stack);

    printf("Peek: %d\n", peek(&stack));

    printf("Popped: %d\n", pop(&stack));
    display(&stack);

    printf("Is stack empty? %s\n", is_empty(&stack) ? "Yes" : "No");
    printf("Is stack full? %s\n", is_full(&stack) ? "Yes" : "No");

    return 0;
}
