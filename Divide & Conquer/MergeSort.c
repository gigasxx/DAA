#include <stdio.h>
#include <stdlib.h>
void mergesort(int arr[], int l, int r);
void merge_inplace(int arr[], int l, int m, int r);
int main() {
    int n, i;
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
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    mergesort(arr, 0, n - 1);
    printf("After sorting: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}
void mergesort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge_inplace(arr, l, m, r);
    }
}
void merge_inplace(int arr[], int l, int m, int r) {
    int start1 = l;
    int start2 = m + 1;
    if (arr[m] <= arr[start2]) return;
    while (start1 <= m && start2 <= r) {
        if (arr[start1] <= arr[start2]) {
            start1++;
        } 
        else {
            int value = arr[start2];
            int index = start2;
            while (index != start1) {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[start1] = value;
            start1++;
            m++;
            start2++;
        }
    }
}
