#include <stdio.h>

void merge_sort(int arr[], int len) {
    if (len > 1) {
        int mid = len / 2;
        int n1 = mid;
        int n2 = len - mid;
        int L[n1], R[n2];
        for (int i = 0; i < n1; i++) {
            L[i] = arr[i];
        }
        for (int j = 0; j < n2; j++) {
            R[j] = arr[mid + j];
        }
        //ya understood
        merge_sort(L, n1);
        merge_sort(R, n2);
        //ok
        int i = 0, j = 0, k = 0;
        while (i < n1 && j < n2) {
            if (L[i] < R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
}

int main() {
    int arr[] = {14, 5, 6, 455, 4, 1}; 
    int size = sizeof(arr) / sizeof(arr[0]);

    merge_sort(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}