#include <stdio.h>
//4A. Merge Sort
//Given an array, count the number of inversions in it. An inversion is a pair (i, j) such that i < j and arr[i] > arr[j].Modify merge sort to count while merging.

int mergeSort(int arr[], int temp[], int left, int right) {
    int mid, i, j, k;
    int inv_count = 0;

    if (right > left) {
        mid = (left + right) / 2;

       
        inv_count += mergeSort(arr, temp, left, mid);

       
        inv_count += mergeSort(arr, temp, mid + 1, right);

        // Merge both halves and count cross inversions
        i = left;      
        j = mid + 1;   
        k = left;      
        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                inv_count += (mid - i + 1); 
            }
        }

        while (i <= mid)
            temp[k++] = arr[i++];
        while (j <= right)
            temp[k++] = arr[j++];

        
        for (i = left; i <= right; i++)
            arr[i] = temp[i];
    }

    return inv_count;
}

int main() {
    int arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[n];

    int invCount = mergeSort(arr, temp, 0, n - 1);

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nNumber of inversions: %d\n", invCount);
    return 0;
}
