#include <stdio.h>

#define MAX 20

int is_safe(int board[MAX][MAX], int row, int col, int n) {
    int i, j;

    // 1. Check column above
    for (i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return 0;
        }
    }

    // 2. Check upper-left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return 0;
        }
    }

    // 3. Check upper-right diagonal
    for (i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) {
            return 0;
        }
    }

    return 1;
}

int solve_nqueens(int board[MAX][MAX], int row, int n) {
    int col;
    if (row == n) {
        return 1;
    }

    for (col = 0; col < n; col++) {
        if (is_safe(board, row, col, n)) {
            board[row][col] = 1; // Place queen

            if (solve_nqueens(board, row + 1, n)) {
                return 1;
            }

            board[row][col] = 0; // Backtrack
        }
    }
    return 0;
}

int main() {
    int n = 4;
    int board[MAX][MAX] = {0};
    int i, j;

    if (solve_nqueens(board, 0, n)) {
        printf("Solution for %d-Queens:\n", n);
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}
