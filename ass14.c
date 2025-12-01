#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
// Design a Hash Table that uses chaining with linked lists to resolve collisions. Your task is to implement insert, delete, and search operations. The hash function should be key % size, where size is the number of buckets in the hash table.

// Node structure for chaining
struct Node {
    int data;
    struct Node* next;
};

struct Node* hashTable[SIZE];

// Create a new node
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = NULL;
    return newNode;
}

// Hash function
int hashFunction(int key) {
    return key % SIZE;
}

// Insert key
void insert(int key) {
    int index = hashFunction(key);
    struct Node* newNode = createNode(key);

    // Insert at beginning of linked list
    newNode->next = hashTable[index];
    hashTable[index] = newNode;

    printf("Inserted %d at index %d\n", key, index);
}

// Search key
void search(int key) {
    int index = hashFunction(key);
    struct Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->data == key) {
            printf("%d found at index %d\n", key, index);
            return;
        }
        temp = temp->next;
    }
    printf("%d not found!\n", key);
}

// Delete key
void delete(int key) {
    int index = hashFunction(key);
    struct Node *temp = hashTable[index], *prev = NULL;

    while (temp != NULL) {
        if (temp->data == key) {
            if (prev == NULL)
                hashTable[index] = temp->next;
            else
                prev->next = temp->next;
            free(temp);
            printf("%d deleted from index %d\n", key, index);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("%d not found to delete!\n", key);
}

// Display hash table
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("[%d]: ", i);
        struct Node* temp = hashTable[i];
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, key;

    for (int i = 0; i < SIZE; i++)
        hashTable[i] = NULL;

    while (1) {
        printf("\n--- Hash Table Operations ---\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            insert(key);
            break;
        case 2:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            delete(key);
            break;
        case 3:
            printf("Enter key to search: ");
            scanf("%d", &key);
            search(key);
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
