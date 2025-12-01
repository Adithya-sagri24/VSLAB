#include <stdio.h>
#include <stdlib.h>
//3A. Implement modified bubble sort on even indices 
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble Sort with step-by-step output
void bubbleSort(int arr[], int n) {
    printf("\n--- Bubble Sort ---\n");
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
        printf("Pass %d: ", i + 1);
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        printArray(arr, n);
        if (!swapped) break;
    }
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    printf("\n--- Insertion Sort ---\n");
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        printf("After pass %d (inserted %d at position %d): ", i, key, j + 1);
        printArray(arr, n);
    }
}

// Selection Sort
void selectionSort(int arr[], int n) {
    printf("\n--- Selection Sort ---\n");
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
        printf("After pass %d (placed %d at position %d): ", i + 1, arr[i], i);
        printArray(arr, n);
    }
}

// Quick Sort partition
int partition(int arr[], int low, int high, int n, int *pass) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    (*pass)++;
    printf("After pass %d (pivot %d placed at position %d): ", *pass, pivot, i + 1);
    printArray(arr, n);

    return i + 1;
}

void quickSortHelper(int arr[], int low, int high, int n, int *pass) {
    if (low < high) {
        int pi = partition(arr, low, high, n, pass);
        quickSortHelper(arr, low, pi - 1, n, pass);
        quickSortHelper(arr, pi + 1, high, n, pass);
    }
}

void quickSort(int arr[], int n) {
    printf("\n--- Quick Sort ---\n");
    int pass = 0;
    quickSortHelper(arr, 0, n - 1, n, &pass);
}

// Main menu-driven program
int main() {
    int arr[100], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int choice;
    do {
        printf("\n--- Sorting Menu ---\n");
        printf("1. Bubble Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Selection Sort\n");
        printf("4. Quick Sort\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        int arrCopy[100];
        for (int i = 0; i < n; i++) arrCopy[i] = arr[i];

        switch (choice) {
            case 1:
                bubbleSort(arrCopy, n);
                printf("\nSorted array: ");
                printArray(arrCopy, n);
                break;
            case 2:
                insertionSort(arrCopy, n);
                printf("\nSorted array: ");
                printArray(arrCopy, n);
                break;
            case 3:
                selectionSort(arrCopy, n);
                printf("\nSorted array: ");
                printArray(arrCopy, n);
                break;
            case 4:
                quickSort(arrCopy, n);
                printf("\nSorted array: ");
                printArray(arrCopy, n);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
