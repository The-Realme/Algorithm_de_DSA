#include <stdio.h>

#define MAX 50

void lcs(char X[], char Y[], int m, int n) {
    // 1. Create DP[m+1][n+1]
    int DP[MAX][MAX];
    int i, j;

    // 2. For i = 0 to m: DP[i][0] = 0
    for (i = 0; i <= m; i++) {
        DP[i][0] = 0;
    }

    // 3. For j = 0 to n: DP[0][j] = 0
    for (j = 0; j <= n; j++) {
        DP[0][j] = 0;
    }

    // 4. Fill the DP table
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            } else {
                if (DP[i - 1][j] > DP[i][j - 1]) {
                    DP[i][j] = DP[i - 1][j];
                } else {
                    DP[i][j] = DP[i][j - 1];
                }
            }
        }
    }

    // 5. Length = DP[m][n]
    int length = DP[m][n];

    // 6. Trace back from DP[m][n] to obtain the LCS
    char result[MAX];
    int index = length;
    result[index] = '\0'; // Null-terminate the string

    i = m;
    j = n;
    while (i > 0 && j > 0) {
        // If characters match, include in LCS and move diagonally up-left
        if (X[i - 1] == Y[j - 1]) {
            result[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }
        // Otherwise, move in the direction of the larger value
        else if (DP[i - 1][j] > DP[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // 7. Print the LCS and its length
    printf("LCS: %s\n", result);
    printf("Length of LCS: %d\n", length);
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = 0, n = 0;

    // Find lengths m and n without <string.h>
    while (X[m] != '\0') {
        m++;
    }
    while (Y[n] != '\0') {
        n++;
    }

    lcs(X, Y, m, n);

    return 0;
}
