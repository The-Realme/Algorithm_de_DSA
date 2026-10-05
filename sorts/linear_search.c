#include <stdio.h>
int linear_search(int arr[],int n,int target){
    // int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        if(arr[i]==target){
            return i;
        }
    }
}
int main() {
    int arr[]={15,45,87,65,48,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("The element is present at the index: %d ",linear_search(arr,n,87));
    return 0;
}