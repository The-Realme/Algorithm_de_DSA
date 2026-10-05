#include <stdio.h>
void bubble_sort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                // arr[j],arr[j+1]=arr[j+1],arr[j];
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main() {
    int arr[] = {14, 5, 6, 455, 4, 1}; 
    int size = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}