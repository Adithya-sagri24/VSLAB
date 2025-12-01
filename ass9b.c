//  9B. Priority Queue- Implement priority queue using linked list

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    int priority;
    struct Node* next;
};

// Insert by priority
void enqueue(struct Node** front, int data, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    if (*front == NULL || priority < (*front)->priority) {
        newNode->next = *front;
        *front = newNode;
    } else {
        struct Node* temp = *front;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Dequeue (remove highest priority)
void dequeue(struct Node** front) {
    if (*front == NULL) {
        printf("Priority Queue is empty!\n");
        return;
    }
    struct Node* temp = *front;
    *front = (*front)->next;
    free(temp);
}

// Display queue
void display(struct Node* front) {
    while (front != NULL) {
        printf("Value: %d Priority: %d\n", front->data, front->priority);
        front = front->next;
    }
}

int main() {
    struct Node* front = NULL;

    enqueue(&front, 10, 2);
    enqueue(&front, 20, 1);
    enqueue(&front, 30, 3);

    printf("Priority Queue:\n");
    display(front);

    printf("\nAfter Dequeue:\n");
    dequeue(&front);
    display(front);

    return 0;
}