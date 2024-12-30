#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
    }
}

// Pop an element from the stack
int pop(Stack *stack) {
    if (!is_empty(stack)) {
        return stack->arr[stack->top--];
    }
    return 0;  // Return 0 if the stack is empty (should not occur here)
}

// Function to evaluate a postfix expression
int evaluate_postfix(const char *postfix) {
    Stack stack;
    initialize_stack(&stack);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        // If the character is an operand, push it onto the stack
        if (isdigit(ch)) {
            push(&stack, ch - '0');  // Convert char to int
        }
        // If the character is an operator, pop two elements and perform the operation
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int b = pop(&stack);  // Second operand
            int a = pop(&stack);  // First operand

            switch (ch) {
                case '+':
                    push(&stack, a + b);
                    break;
                case '-':
                    push(&stack, a - b);
                    break;
                case '*':
                    push(&stack, a * b);
                    break;
                case '/':
                    push(&stack, a / b);
                    break;
            }
        }
    }

    // The final result is the only element left in the stack
    return pop(&stack);
}

// Main function for testing
int main() {
    char postfix[MAX];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    int result = evaluate_postfix(postfix);

    printf("Result: %d\n", result);

    return 0;
}
