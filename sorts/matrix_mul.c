#include <stdio.h>
void matrix_multiplication(int n,int arr1[n][n],int arr2[n][n]){
    int final[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
             final[i][j]=0;
            for(int k=0;k<n;k++){
                final[i][j]+=arr1[i][k]*arr2[k][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",final[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int n=3;
    // int arr1[n][n],arr2[n][n];
    int arr1[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int arr2[3][3]={{1,2,3},{4,5,6},{7,8,9}};   // an important lesson here we cant initialise n in curly braces like arr[n]={..}
    matrix_multiplication(3,arr1,arr2);
    return 0;
}