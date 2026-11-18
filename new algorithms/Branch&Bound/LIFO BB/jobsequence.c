#include <stdio.h>

#define MAX 50

struct Node {
    int level;
    int profit;
    int remaining;
    int present[MAX]; // 1 if job is selected, 0 otherwise
};

// Check if all selected jobs can be scheduled before their deadlines
int is_feasible(int present[], int d[], int n, int dmax) {
    int slot[MAX] = {0};
    int i, j;

    // Jobs are already sorted in decreasing order of profit
    for (i = 0; i < n; i++) {
        if (present[i] == 1) {
            int placed = 0;
            // Find the latest free slot on or before job's deadline
            for (j = d[i]; j >= 1; j--) {
                if (j <= dmax && slot[j] == 0) {
                    slot[j] = 1;
                    placed = 1;
                    break;
                }
            }
            if (placed == 0) {
                return 0; // Cannot fit this job within its deadline
            }
        }
    }
    return 1;
}

void job_selection(int id[], int d[], int p[], int n) {
    int i, j, temp;
    int dmax = 0;
    int total_profit = 0;
    int best_profit = 0;
    int best_present[MAX] = {0};

    // 1. Sort jobs in decreasing order of profit
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (p[j] < p[j + 1]) {
                temp = p[j]; p[j] = p[j + 1]; p[j + 1] = temp;
                temp = d[j]; d[j] = d[j + 1]; d[j + 1] = temp;
                temp = id[j]; id[j] = id[j + 1]; id[j + 1] = temp;
            }
        }
    }

    // 2. Find maximum deadline Dmax & 3. Calculate total profit
    for (i = 0; i < n; i++) {
        if (d[i] > dmax) {
            dmax = d[i];
        }
        total_profit += p[i];
    }

    // 4. Initialize root node
    struct Node stack[MAX];
    int top = -1;

    struct Node root;
    root.level = 0;
    root.profit = 0;
    root.remaining = total_profit;
    for (i = 0; i < n; i++) {
        root.present[i] = 0;
    }

    // 5. Insert root node into the stack
    stack[++top] = root;

    // 6. While stack is not empty
    while (top >= 0) {
        struct Node curr = stack[top--];

        int ub = curr.profit + curr.remaining;

        // Prune the node if upper bound cannot beat best profit
        if (ub <= best_profit) {
            continue;
        }

        // If all jobs are considered, update best profit and selection
        if (curr.level == n) {
            best_profit = curr.profit;
            for (i = 0; i < n; i++) {
                best_present[i] = curr.present[i];
            }
            continue;
        }

        int idx = curr.level;

        // Reject the next job (pushed first so Select is popped first)
        struct Node reject = curr;
        reject.level = idx + 1;
        reject.remaining = curr.remaining - p[idx];
        reject.present[idx] = 0;

        if (reject.profit + reject.remaining > best_profit) {
            stack[++top] = reject;
        }

        // Select the next job
        struct Node select = curr;
        select.level = idx + 1;
        select.profit = curr.profit + p[idx];
        select.remaining = curr.remaining - p[idx];
        select.present[idx] = 1;

        if (is_feasible(select.present, d, n, dmax)) {
            stack[++top] = select;
        }
    }

    // 7. Print BestProfit and selected jobs
    printf("Best Profit: %d\n", best_profit);
    printf("Selected Jobs: ");
    for (i = 0; i < n; i++) {
        if (best_present[i] == 1) {
            printf("J%d ", id[i]);
        }
    }
    printf("\n");
}

int main() {
    int id[] = {1, 2, 3, 4};
    int d[] = {2, 1, 2, 1};
    int p[] = {100, 19, 27, 25};
    int n = 4;

    job_selection(id, d, p, n);

    return 0;
}
