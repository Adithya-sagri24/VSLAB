#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//wap to check for balanced parentheses using stack


// A structure to represent a stack
typedef struct Stack {
    int top;
    unsigned capacity;
    char* array;
} Stack;
 
// Function to create a stack of given capacity.
Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}


int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}
 
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Push to stack
void push(Stack* stack, char c) {
    if (isFull(stack)) return;
    stack->array[++stack->top] = c;
}

// Pop from stack
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        return '\0'; // Represents an empty stack pop
    }
    return stack->array[stack->top--];
}

// Check matching pair
int isMatchingPair(char open, char close) {
    return ((open == '(' && close == ')') ||
            (open == '{' && close == '}') ||
            (open == '[' && close == ']'));
}

// Check balanced parentheses
int isBalanced(const char* expr) {
    int len = strlen(expr);
    Stack* stack = createStack(len);

    for (int i = 0; i < len; i++) {
        char c = expr[i]; 

        if (c == '(' || c == '{' || c == '[') {
            push(stack, c);
        } 
        else if (c == ')' || c == '}' || c == ']') {
            // If a closing bracket appears first, it's not balanced.
            if (isEmpty(stack)) {
                free(stack->array);
                free(stack);
                return 0; 
            }
            char popped = pop(stack);
            if (!isMatchingPair(popped, c)) {
                free(stack->array);
                free(stack);
                return 0; // not balanced
            }
        }
    }
    int result = isEmpty(stack); // balanced if stack is empty at the end
    free(stack->array);
    free(stack);
    return result;
}

int main() {
    char expr[101]; // +1 for null terminator
    printf("Enter an expression: ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = 0; // Remove trailing newline from fgets

    if (isBalanced(expr))
        printf("Balanced Expression \n");
    else
        printf("Not Balanced \n");

    return 0;
}
