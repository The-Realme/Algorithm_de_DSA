#include <stdio.h>

#define MAX 50
#define INFINITY 999999

// Helper function to print the optimal parenthesization using table s
void print_optimal_parens(int s[MAX][MAX], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        print_optimal_parens(s, i, s[i][j]);
        print_optimal_parens(s, s[i][j] + 1, j);
        printf(")");
    }
}

void matrix_chain(int p[], int n) {
    // 1. Create m[n][n] and s[n][n] (using 1-based indexing up to n)
    int m[MAX][MAX] = {0};
    int s[MAX][MAX] = {0};
    int i, j, k, L, q;

    // 2. For i = 1 to n: m[i][i] = 0
    for (i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    // 3. Fill tables for chain lengths L = 2 to n
    for (L = 2; L <= n; L++) {
        for (i = 1; i <= n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INFINITY;

            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + (p[i - 1] * p[k] * p[j]);

                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    // 4. Output m[1][n] and optimal parenthesization from s
    printf("Minimum Multiplications (m[1][%d]): %d\n", n, m[1][n]);
    printf("Optimal Parenthesization: ");
    print_optimal_parens(s, 1, n);
    printf("\n");
}

int main() {
    // 3 matrices: A1 (10x20), A2 (20x30), A3 (30x40)
    // p has n + 1 elements (from p[0] to p[n])
    int p[] = {10, 20, 30, 40};
    int n = 3; // Number of matrices

    matrix_chain(p, n);

    return 0;
}
