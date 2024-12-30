#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of the stack

// Stack structure
typedef struct Stack {
    int arr[MAX];
    int top;
} Stack;

// Initialize the stack
void initialize_stack(Stack *stack) {
    stack->top = -1;
}

// Check if the stack is empty
int is_empty(Stack *stack) {
    return stack->top == -1;
}

// Push an element onto the stack
void push(Stack *stack, int value) {
    if (stack->top < MAX - 1) {
        stack->arr[++stack->top] = value;
    } else {
        printf("Stack overflow\n");
    }
}

// Pop an element from the stack
int pop(Stack *stack) {
    if (!is_empty(stack)) {
        return stack->arr[stack->top--];
    }
    printf("Stack underflow\n");
    return -1;  // Return -1 if the stack is empty
}

// Peek at the top element of the stack
int peek(Stack *stack) {
    if (!is_empty(stack)) {
        return stack->arr[stack->top];
    }
    return -1;
}

// Insert an element at the bottom of the stack
void insert_at_bottom(Stack *stack, int value) {
    if (is_empty(stack)) {
        push(stack, value);
    } else {
        int top_element = pop(stack);
        insert_at_bottom(stack, value);
        push(stack, top_element);
    }
}

// Recursive function to reverse the stack
void reverse_stack(Stack *stack) {
    if (!is_empty(stack)) {
        int top_element = pop(stack);
        reverse_stack(stack);
        insert_at_bottom(stack, top_element);
    }
}

// Function to display the stack
void display_stack(Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty\n");
    } else {
        for (int i = 0; i <= stack->top; i++) {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}

// Main function for testing
int main() {
    Stack stack;
    initialize_stack(&stack);

    // Push some elements onto the stack
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);

    printf("Original stack: ");
    display_stack(&stack);

    // Reverse the stack
    reverse_stack(&stack);

    printf("Reversed stack: ");
    display_stack(&stack);

    return 0;
}
