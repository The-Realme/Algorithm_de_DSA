#include <stdio.h>

#define MAX 50

void knapsack(int weight[], int profit[], int n, int W) {
    // 1. Create DP[n+1][W+1]
    int DP[MAX][MAX];
    int selected[MAX] = {0};
    int i, w;

    // 2. Initialise DP[0][w] = 0 and DP[i][0] = 0
    for (w = 0; w <= W; w++) {
        DP[0][w] = 0;
    }
    for (i = 0; i <= n; i++) {
        DP[i][0] = 0;
    }

    // 3. Fill the DP table
    for (i = 1; i <= n; i++) {
        for (w = 1; w <= W; w++) {
            if (weight[i] <= w) {
                int exclude = DP[i - 1][w];
                int include = profit[i] + DP[i - 1][w - weight[i]];

                if (include > exclude) {
                    DP[i][w] = include;
                } else {
                    DP[i][w] = exclude;
                }
            } else {
                DP[i][w] = DP[i - 1][w];
            }
        }
    }

    // 4. MaximumProfit = DP[n][W]
    int max_profit = DP[n][W];

    // 5. Set w = W
    w = W;

    // 6. Trace back from i = n down to 1 to find selected items
    for (i = n; i >= 1; i--) {
        if (DP[i][w] != DP[i - 1][w]) {
            selected[i] = 1; // Select item i
            w = w - weight[i];
        }
    }

    // 7. Print selected items and MaximumProfit
    printf("Maximum Profit: %d\n", max_profit);
    printf("Selected Items: ");
    for (i = 1; i <= n; i++) {
        if (selected[i] == 1) {
            printf("Item %d ", i);
        }
    }
    printf("\n");
}

int main() {
    // Using 1-based indexing (index 0 is ignored) to match weight[i] and profit[i]
    int weight[] = {0, 2, 3, 4, 5};
    int profit[] = {0, 3, 4, 5, 6};
    int n = 4;
    int W = 5;

    knapsack(weight, profit, n, W);

    return 0;
}
