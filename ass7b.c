// Assignment 7B: Stack using Linked List - Palindrome Check
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* top = NULL;

void push(char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

char pop() {
    if (top == NULL) {
        return '\0';
    }
    Node* temp = top;
    char value = temp->data;
    top = top->next;
    free(temp);
    return value; 
}

int isStackEmpty() {
    return top == NULL;
}

int isPalindrome(char* str) {
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        push(str[i]);
    }

    for (int i = 0; i < len; i++) {
        if (pop() != str[i]) {
            
            while(!isStackEmpty()) pop();
            return 0; 
        }
    }
    return 1; 
}

int main() {
    char inputString[100];
    
    printf("--- Palindrome Checker using Stack ---\n");
    printf("Enter a string: ");
    scanf("%s", inputString);

    if (isPalindrome(inputString)) {
        printf("The string \"%s\" is a palindrome. \n", inputString);
    } else {
        printf("The string \"%s\" is NOT a palindrome. \n", inputString);
    }

    return 0;
}