#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//Assignment 11 --
//Perform recursive and non-recursive traversal on binary tree. Inorder, Preorder, Postorder, and Labelwise traversal using these two methods


struct Node {
    int data;
    struct Node *left, *right;
};

// Queue for level order
struct Node* queue[MAX];
int front = -1, rear = -1;

void enqueue(struct Node* node) {
    queue[++rear] = node;
}

struct Node* dequeue() {
    return queue[++front];
}

int isQueueEmpty() {
    return front == rear;
}

// Stack for non-recursive traversals
struct Node* stack[MAX];
int top = -1;

void push(struct Node* node) {
    stack[++top] = node;
}

struct Node* pop() {
    return stack[top--];
}

int isStackEmpty() {
    return top == -1;
}

// Create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Recursive Traversals
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Non-Recursive Inorder
void inorderNonRecursive(struct Node* root) {
    struct Node* curr = root;
    while (curr != NULL || !isStackEmpty()) {
        while (curr != NULL) {
            push(curr);
            curr = curr->left;
        }
        curr = pop();
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

// Non-Recursive Preorder
void preorderNonRecursive(struct Node* root) {
    if (root == NULL) return;
    push(root);
    while (!isStackEmpty()) {
        struct Node* node = pop();
        printf("%d ", node->data);
        if (node->right) push(node->right);
        if (node->left) push(node->left);
    }
}

// Non-Recursive Postorder
void postorderNonRecursive(struct Node* root) {
    struct Node *curr = root, *temp;
    struct Node* out[MAX];
    int outTop = -1;

    if (root == NULL) return;
    push(root);

    while (!isStackEmpty()) {
        temp = pop();
        out[++outTop] = temp;
        if (temp->left) push(temp->left);
        if (temp->right) push(temp->right);
    }

    while (outTop >= 0)
        printf("%d ", out[outTop--]->data);
}

// Levelwise Traversal
void levelOrder(struct Node* root) {
    if (root == NULL) return;
    enqueue(root);
    while (!isQueueEmpty()) {
        struct Node* node = dequeue();
        printf("%d ", node->data);
        if (node->left) enqueue(node->left);
        if (node->right) enqueue(node->right);
    }
}

// Main
int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("\nRecursive Traversals:\n");
    printf("Inorder: "); inorder(root);
    printf("\nPreorder: "); preorder(root);
    printf("\nPostorder: "); postorder(root);

    printf("\n\nNon-Recursive Traversals:\n");
    printf("Inorder: "); inorderNonRecursive(root);
    printf("\nPreorder: "); preorderNonRecursive(root);
    printf("\nPostorder: "); postorderNonRecursive(root);

    printf("\n\nLevelwise Traversal: ");
    levelOrder(root);
    printf("\n");

    return 0;
}
