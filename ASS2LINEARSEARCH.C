#include <stdio.h>

// Function from your code
int linearSearchStepK(int arr[], int n, int k, int step) {
    for( int t = 0; t < step; t++ ) {
        for (int i = t; i < n; i += step) {
            if (arr[i] > k)
                break; 
            if (arr[i] == k) {
                return i;    
            }
        }
    }
    return -1; 
}

int main() {
    int arr[] = {10, 22, 15, 7, 30, 25, 18};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 25;
    int step = 3;

    int index = linearSearchStepK(arr, n, k, step);

    if (index != -1)
        printf("Element %d found at index %d\n", k, index);
    else
        printf("Element %d not found\n", k);

    return 0;
}
