#include <stdio.h>

#define MAX 50

int present[MAX] = {0};

void search(int k, int current_sum, int remaining_sum, int S[], int n, int target) {
    int i;

    // 1. If CurrentSum == Target, print Present and return
    if (current_sum == target) {
        printf("{ ");
        for (i = 0; i < n; i++) {
            if (present[i] == 1) {
                printf("%d ", S[i]);
            }
        }
        printf("}\n");
        return;
    }

    // 2. Bounding Condition 1: CurrentSum exceeded Target
    if (current_sum > target) {
        return;
    }

    // 3. Bounding Condition 2: Even adding all remaining elements cannot reach Target
    if (current_sum + remaining_sum < target) {
        return;
    }

    // 4. All elements considered
    if (k == n) {
        return;
    }

    // 5. Include S[k]
    present[k] = 1;
    search(k + 1, current_sum + S[k], remaining_sum - S[k], S, n, target);
    present[k] = 0; // Backtrack: remove S[k] from Present

    // 6. Exclude S[k]
    search(k + 1, current_sum, remaining_sum - S[k], S, n, target);
}

void subset_sum(int S[], int n, int target) {
    int i;
    int total_sum = 0;

    // 1. Calculate total sum of all elements
    for (i = 0; i < n; i++) {
        total_sum += S[i];
        present[i] = 0; // 2. Initialize Present = {}
    }

    // 3. Call Search(0, CurrentSum, RemainingSum)
    printf("Subsets with sum %d:\n", target);
    search(0, 0, total_sum, S, n, target);
}

int main() {
    int S[] = {5, 10, 12, 13, 15, 18};
    int n = 6;
    int target = 30;

    subset_sum(S, n, target);

    return 0;
}
