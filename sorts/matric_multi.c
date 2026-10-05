#include <stdio.h>

int main() {
    int n;
    printf("Enter the size of the square matrices (N x N): ");
    scanf("%d", &n);

    int arr1[n][n];
    int arr2[n][n];
    int final[n][n];

    printf("Enter elements for Matrix 1:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("Enter elements for Matrix 2:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            final[i][j] = 0; // Crucial step: Clear garbage values
            
            // The 'k' loop travels across Row i of arr1 and down Column j of arr2
            for(int k = 0; k < n; k++) {                                                //inner extra loop
                final[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    // 4. Print the Result
    printf("\nResultant Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", final[i][j]);
        }
        printf("\n");
    }

    return 0;
}
