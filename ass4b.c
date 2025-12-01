#include <stdio.h>

//4B. Selection Sort
//Given an array of integers, sort the array using selection sort and return a new array where each element represents the final index of the element from the original array

void selectionSortWithIndex(int arr[], int n, int pos[]) {
    
    int original[n];
    for (int i = 0; i < n; i++)
        original[i] = arr[i];

   
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Swap
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }

   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (original[i] == arr[j]) {
                pos[i] = j;
                break;  
            }
        }
    }
}

int main() {
    int arr[] = {40, 10, 30, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int pos[n];

    selectionSortWithIndex(arr, n, pos);

    printf("Final index positions of original array:\n");
    for (int i = 0; i < n; i++)
        printf("%d -> %d\n", arr[i], pos[i]);

    return 0;
}
