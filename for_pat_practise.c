#include <stdio.h>
// // void merge(int arr[],int l,int mid,int r){
// //     int n1=mid-l+1;
// //     int n2=r-mid;
// //     int L[n1];
// //     int R[n2];
// //     for(int i=0;i<n1;i++){
// //         L[i]=arr[l+i];
// //     }
// //     for(int i=0;i<n2;i++){
// //         R[i]=arr[mid+i+1];
// //     }
        
// //     int i=0,j=0,k=l;
// //     while(i<n1 && j<n2){
// //         if(L[i]<=R[j]){
// //             arr[k]=L[i];
// //             i++;
// //         }
// //         else{
// //             arr[k]=R[j];
// //             j++;
// //         }
// //         k++;
// //     }
// //     while(i<n1){
// //         // if(L[i]<arr[i]){
// //         arr[k] = L[i];
// //         i++;
// //         k++;
// //     // }
// //     }
// //     while(j<n2){
// //         // if(R[j]<arr[j]){
// //         arr[k] = R[j];
// //         j++;
// //         k++;
// //     }
// //     // }

// // }
// // void mergesort(int arr[],int l,int r){
// //     if(l<r){
// //         int mid=l+(r-l)/2;
// //         mergesort(arr,l,mid);
// //         mergesort(arr,mid+1,r);
// //         merge(arr,l,mid,r);
// //     }
// // }
// void final(int arr,int n){
//     for(int i=0;i<n;i++){
//         int key=arr[i];  //first element key hai
//         int j=i-1;        //int j=i-1;
//         while(arr[j]>key && j>0){
//             arr[j+1]=arr[j];
//             j--;
//         }
//         arr[j+1]=key;
//     }
// }

// // int main() {
// //     int n;
// //     scanf("%d",&n);
// //     int arr[n];
// //     for(int i=0;i<n;i++){
// //         scanf("%d",&arr[i]);
// //     }
// //     mergesort(arr,0,n-1);
// //     for(int i=0;i<n;i++){
// //         printf("%d ",arr[i]);
// //     }
// //     return 0;
// // }

// #include <stdio.h>
// void insertionSort(int arr,int n){
//     for(int i=1;i<n;i++){
//         int key=arr[i];
//         int j=i-1;
//         while(j>0 && arr[j]>key){
//             arr[j+1]=arr[j];
//             j--;
//         }
//         arr[j+1]=key;
//     }
// }


// void jokey(int arr[],int n){
//     for(int i=0;i<n;i++){
//         int key=arr[i];
//         int j=i-1;
//         while(j>0 && arr[k]>key){
//             arr[j+1]=arr[j];
//             j--;
//         }
//         arr[j+1]=key;
//     }
// }


void finalinsertionsort(int arr[],int n){
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

void swap(int *a,int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min_idx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_idx]){
                // j=min_idx;
                min_idx=j;
            }
        }   //This inner for loop is for change detection
        if(min_idx!=i){
            swap(&arr[min_idx],&arr[i]);
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}


int main() {
    int arr[]={5,3,9,7,8,6,4};
    // finalinsertionsort(arr,sizeof(arr)/sizeof(arr[0]));
    selectionSort(arr,sizeof(arr)/sizeof(arr[0]));
    return 0;
}