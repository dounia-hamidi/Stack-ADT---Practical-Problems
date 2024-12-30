#include <stdio.h>
#include <ctype.h>
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
int is_empty(Stack *stack) {
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

// Peek at the top element of the stack
char peek(Stack *stack) {
    if (!is_empty(stack)) {
        return stack->arr[stack->top];
    }
    return '\0';
}

// Function to check operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

// Function to check if a character is an operator
int is_operator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Function to convert infix to postfix
void infix_to_postfix(const char *infix, char *postfix) {
    Stack stack;
    initialize_stack(&stack);
    int j = 0;  // Index for postfix expression

    for (int i = 0; i < strlen(infix); i++) {
        char ch = infix[i];

        // If the character is an operand, add it to the postfix expression
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // If the character is an opening parenthesis, push it onto the stack
        else if (ch == '(') {
            push(&stack, ch);
        }
        // If the character is a closing parenthesis
        else if (ch == ')') {
            while (!is_empty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack);  // Remove the opening parenthesis
        }
        // If the character is an operator
        else if (is_operator(ch)) {
            while (!is_empty(&stack) && precedence(peek(&stack)) >= precedence(ch)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, ch);
        }
    }

    // Pop all remaining operators from the stack
    while (!is_empty(&stack)) {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';  // Null-terminate the postfix expression
}

// Main function for testing
int main() {
    char infix[MAX];
    char postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infix_to_postfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
