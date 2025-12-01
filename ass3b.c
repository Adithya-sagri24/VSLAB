#include <stdio.h>
//3B. Insertion Sort: Count the total number of shifts (not comparisons) required to sort an array using insertion sort.
int insertionSortCountShifts(int arr[], int n) {
    int shifts = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  // shift
            shifts++;
            j--;
        }
        arr[j + 1] = key;
        if (j + 1 != i) shifts++;  // placing key also counts as shift
    }
    return shifts;
}

int main() {
    int arr[] = {5, 3, 4, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    int totalShifts = insertionSortCountShifts(arr, n);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nTotal number of shifts: %d\n", totalShifts);
    return 0;
}
