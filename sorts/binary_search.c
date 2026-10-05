#include <stdio.h>
int binary_search(int arr[],int target,int n){
    int l=0;
    int r=n-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(target==arr[mid]){
            return mid;
        }
        else if(target>arr[mid]){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
}
int main() {
    int arr[]={1,2,3,4,5,6};
    printf("%d",binary_search(arr,3,6));
    return 0;
}