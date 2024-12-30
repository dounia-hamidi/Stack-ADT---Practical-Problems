#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100  // Maximum size of the stack

// Stack structure
typedef struct Stack {
    char arr[MAX];
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

// Push an element onto the stack
void push(Stack *stack, char value) {
    if (stack->top < MAX - 1) {
        stack->arr[++stack->top] = value;
    }
}

// Pop an element from the stack
char pop(Stack *stack) {
    if (!is_empty(stack)) {
        return stack->arr[stack->top--];
    }
    return '\0';  // Return null character if stack is empty
}

// Function to check if the characters form a valid pair
bool is_matching_pair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

// Function to check if the expression has balanced parentheses
bool is_balanced(const char *expression) {
    Stack stack;
    initialize_stack(&stack);

    for (int i = 0; i < strlen(expression); i++) {
        char ch = expression[i];

        // Push opening parentheses onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        }
        // For closing parentheses, check for matching pair
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (is_empty(&stack) || !is_matching_pair(pop(&stack), ch)) {
                return false;  // Unbalanced if no match or stack is empty
            }
        }
    }

    // If stack is empty, parentheses are balanced
    return is_empty(&stack);
}

// Main function for testing
int main() {
    char expression1[] = "({[()]})";
    char expression2[] = "{[([))]}";

    printf("Expression: \"%s\" - %s\n", expression1, is_balanced(expression1) ? "Balanced" : "Unbalanced");
    printf("Expression: \"%s\" - %s\n", expression2, is_balanced(expression2) ? "Balanced" : "Unbalanced");

    return 0;
}

