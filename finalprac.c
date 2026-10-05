// #include <stdio.h>
// void merge(int arr[],int l,int mid,int r){
//     int n1=mid-l+1;
//     int n2=r-mid;
//     int L[n1];
//     int R[n2];
//     for(int i=0;i<n1;i++){
//         L[i]=arr[l+i];
//     }
//     for(int i=0;i<n2;i++){
//         R[i]=arr[mid+i+1];

//     }
//     int i=0,j=0,k=l;
//     while(i<n1 && j<n2){
//         if(L[i]<=R[j]){
//             arr[k]=L[i];
//             i++;
//         }
//         else{
//             arr[k]=R[j];
//             j++;
//         }
//         k++;
//     }
//     while (i < n1) {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }

//     while (j < n2) {
//         arr[k] = R[j];
//         j++;
//         k++;
//     }
// }
// void merge_sort(int arr[],int l,int r){
//     if(l<r){
//         int mid=l+(r-l)/2;
//         merge_sort(arr,l,mid);
//         merge_sort(arr,mid+1,r);
//         merge(arr,l,mid,r);
//     }
// }
    


// int main() {
//     int n;
//     scanf("%d",&n);
//     int arr[n];
//     for(int i=0;i<n;i++){
//         scanf("%d",&arr[i]);
//     }
//     merge_sort(arr,0,n-1);
//     for(int i=0;i<n;i++){
//         printf("%d ",arr[i]);
//     }
//     return 0;
// }

#include <stdio.h>
void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
int main() {
    int arr[]={4,2,1,5,8,7};
    insertionSort(arr,sizeof(arr)/sizeof(arr[0]));
    return 0;
}