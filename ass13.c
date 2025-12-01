#include <stdio.h>
#include <stdlib.h>

#define MAX 20

//Write a program for graph traversals using BFS and DFS. Print intermediate outputs too. Return the order of nodes visited in each traversal. Additionally, print intermediate states of the traversal to track visited nodes and queue/stack content after each step.

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX], front = -1, rear = -1;
int stack[MAX], top = -1;
int n;

// Enqueue function for BFS
void enqueue(int v) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = v;
}

// Dequeue function for BFS
int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

// Push function for DFS
void push(int v) {
    stack[++top] = v;
}

// Pop function for DFS
int pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}

// Display queue
void displayQueue() {
    if (front == -1 || front > rear) {
        printf("Queue: []\n");
        return;
    }
    printf("Queue: [");
    for (int i = front; i <= rear; i++) {
        printf("%d", queue[i]);
        if (i < rear) printf(", ");
    }
    printf("]\n");
}

// Display stack
void displayStack() {
    if (top == -1) {
        printf("Stack: []\n");
        return;
    }
    printf("Stack: [");
    for (int i = 0; i <= top; i++) {
        printf("%d", stack[i]);
        if (i < top) printf(", ");
    }
    printf("]\n");
}

// BFS Traversal
void BFS(int start) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    printf("\nBFS Traversal starting from vertex %d:\n", start);

    while (front <= rear) {
        int current = dequeue();
        printf("Visited: ");
        for (int i = 0; i < n; i++)
            if (visited[i]) printf("%d ", i);
        printf("\n");

        displayQueue();

        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }

    printf("\nBFS Order: ");
    for (int i = 0; i < n; i++)
        if (visited[i]) printf("%d ", i);
    printf("\n");
}

// DFS Traversal
void DFS(int start) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    push(start);
    printf("\nDFS Traversal starting from vertex %d:\n", start);

    while (top != -1) {
        int current = pop();
        if (!visited[current]) {
            visited[current] = 1;
            printf("Visited: ");
            for (int i = 0; i < n; i++)
                if (visited[i]) printf("%d ", i);
            printf("\n");

            displayStack();

            for (int i = n - 1; i >= 0; i--) {
                if (adj[current][i] == 1 && !visited[i])
                    push(i);
            }
        }
    }

    printf("\nDFS Order: ");
    for (int i = 0; i < n; i++)
        if (visited[i]) printf("%d ", i);
    printf("\n");
}

int main() {
    int edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    BFS(start);
    DFS(start);

    return 0;
}
