#include <stdio.h>

// Function A: Smallest subarray length with sum > target
int findMinSubarrayLength(int* array, int size, int target, int* minStart, int* minEnd) {
    int start = 0, end = 0, currentSum = 0;
    int minLength = size + 1;

    while (end < size) {
        currentSum += array[end];
        while (currentSum > target) {
            int windowSize = end - start + 1;
            if (windowSize < minLength) {
                minLength = windowSize;
                *minStart = start;
                *minEnd = end;
            }
            currentSum -= array[start];
            start++;
        }
        end++;
    }
    return (minLength == size + 1) ? -1 : minLength;
}

// Function B: Longest bitonic subarray length
int findLongestBitonic(int* array, int size) {
    int inc[size], dec[size];
    int i, maxLen = 1;

    inc[0] = 1;
    for (i = 1; i < size; i++)
        inc[i] = (array[i] > array[i - 1]) ? inc[i - 1] + 1 : 1;

    dec[size - 1] = 1;
    for (i = size - 2; i >= 0; i--)
        dec[i] = (array[i] > array[i + 1]) ? dec[i + 1] + 1 : 1;

    for (i = 0; i < size; i++) {
        int bitonicLen = inc[i] + dec[i] - 1;
        if (bitonicLen > maxLen)
            maxLen = bitonicLen;
    }
    return maxLen;
}

// Main menu
int main() {
    int size, choice;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int array[size];
    printf("Enter array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    do {
        printf("\n--- MENU ---\n");
        printf("1. Smallest subarray length with sum > k\n");
        printf("2. Longest bitonic subarray length\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int k, start, end;
            printf("Enter k: ");
            scanf("%d", &k);
            int len = findMinSubarrayLength(array, size, k, &start, &end);
            if (len == -1) {
                printf("No subarray found with sum > %d\n", k);
            } else {
                printf("Minimum subarray length: %d\n", len);
                printf("Subarray: ");
                for (int i = start; i <= end; i++)
                    printf("%d ", array[i]);
                printf("\n");
            }
        }
        else if (choice == 2) {
            printf("Length of longest bitonic subarray: %d\n", findLongestBitonic(array, size));
        }
        else if (choice != 3) {
            printf("Invalid choice! Try again.\n");
        }

    } while (choice != 3);

    return 0;
}
