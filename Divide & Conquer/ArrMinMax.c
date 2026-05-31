#include <stdio.h>
#include <stdlib.h>
void find_max_min(int arr[], int low, int high, int *max, int *min);
int main() {
    int n, i;
    int max, min;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Enter elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    find_max_min(arr, 0, n - 1, &max, &min);
    printf("Maximum element: %d\n", max);
    printf("Minimum element: %d\n", min);
    free(arr);
    return 0;
}
void find_max_min(int arr[], int low, int high, int *max, int *min) {
    int max1, min1, max2, min2;
    int mid;
    if (low == high) {
        *max = arr[low];
        *min = arr[low];
        return;
    }
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            *max = arr[low];
            *min = arr[high];
        } else {
            *max = arr[high];
            *min = arr[low];
        }
        return;
    }
    mid = low + (high - low) / 2;
    find_max_min(arr, low, mid, &max1, &min1);
    find_max_min(arr, mid + 1, high, &max2, &min2);
    if (max1 > max2) *max = max1;
    else *max = max2;
    if (min1 < min2) *min = min1;
    else *min = min2;
}
