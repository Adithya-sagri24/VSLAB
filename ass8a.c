//Assignment 8(A)Queue using Array.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

void enqueue(Queue* q, int x) {
    if(q->rear == MAX-1) { printf("Queue Full\n"); return; }
    q->rear++;
    q->data[q->rear] = x;
}

int dequeue(Queue* q) {
    if(q->front > q->rear) { printf("Queue Empty\n"); return -1; }
    return q->data[q->front++];
}

int size(Queue* q) {
    return q->rear - q->front + 1;
}

void reverseK(Queue* q, int k) {
    int stack[MAX], top = -1;
    
    // push first k elements onto stack
    for(int i=0; i<k; i++) {
        stack[++top] = dequeue(q);
    }

    // enqueue them back from stack
    while(top >= 0) {
        enqueue(q, stack[top--]);
    }

    // move the remaining elements to back
    int rem = size(q) - k;
    for(int i=0; i<rem; i++) {
        enqueue(q, dequeue(q));
    }
}

void display(Queue* q) {
    for(int i=q->front; i<=q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    q.front = 0; q.rear = -1;

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 6);
    enqueue(&q, 7);

    printf("Original Queue: ");
    display(&q);

    int k = 3;
    reverseK(&q, k);

    printf("Queue after reversing first %d elements: ", k);
    display(&q);

    return 0;
}