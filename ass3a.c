#include <stdio.h>
//3A. Implement modified bubble sort on even indices 

void modifiedBubbleSortEven(int arr[], int n) {
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < n - 2; j += 2) {
            if (arr[j] > arr[j + 2]) {
                int temp = arr[j];
                arr[j] = arr[j + 2];
                arr[j + 2] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {9, 8, 7, 6, 5, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    modifiedBubbleSortEven(arr, n);

    printf("Array after modified bubble sort on even indices:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
