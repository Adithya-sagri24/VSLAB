//Assignment 8(B) Queue using Linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue
void enqueue(struct Queue* q, int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    if(q->rear == NULL) { 
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Dequeue
int dequeue(struct Queue* q) {
    if(q->front == NULL) return -1; 
    struct Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if(q->front == NULL) q->rear = NULL; 
    free(temp);
    return val;
}

// Display
void display(struct Queue* q) {
    struct Node* temp = q->front;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Rotate k times
void rotateQueue(struct Queue* q, int k) {
    for(int i=0; i<k; i++) {
        if(q->front == NULL) return; 
        int val = dequeue(q);
        enqueue(q, val);
    }
}

int main() {
    struct Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    printf("Original Queue: ");
    display(q);

    int k = 2;
    rotateQueue(q, k);

    printf("Queue after rotating %d times: ", k);
    display(q);

    return 0;
}