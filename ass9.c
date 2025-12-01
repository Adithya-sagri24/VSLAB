// 9A. Circular Queue Rotate the circular queue to the right by k positions.

#include <stdio.h>

#define SIZE 100

int main() {
    int cq[SIZE], n, k, i;
    printf("Enter number of elements in circular queue: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &cq[i]);
    }

    printf("Enter k (rotate right by k): ");
    scanf("%d", &k);

    k = k % n;  

    int rotated[SIZE];
    for (i = 0; i < n; i++) {
        rotated[(i + k) % n] = cq[i];
    }

    printf("Circular Queue after rotation: ");
    for (i = 0; i < n; i++) {
        printf("%d ", rotated[i]);
    }

    return 0;
}