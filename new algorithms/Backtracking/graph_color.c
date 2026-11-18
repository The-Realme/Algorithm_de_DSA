#include <stdio.h>

#define MAX 20

int is_safe(int v, int graph[MAX][MAX], int color[], int c, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (graph[v][i] == 1 && color[i] == c) {
            return 0;
        }
    }
    return 1;
}

int solve_coloring(int graph[MAX][MAX], int m, int color[], int v, int n) {
    int c;
    if (v == n) {
        return 1;
    }

    for (c = 1; c <= m; c++) {
        if (is_safe(v, graph, color, c, n)) {
            color[v] = c;

            if (solve_coloring(graph, m, color, v + 1, n)) {
                return 1;
            }

            color[v] = 0; // Backtrack
        }
    }
    return 0;
}

int main() {
    int n = 4; // Number of vertices
    int m = 3; // Number of colors
    int graph[MAX][MAX] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int color[MAX] = {0};
    int i;

    if (solve_coloring(graph, m, color, 0, n)) {
        printf("Assigned Colors:\n");
        for (i = 0; i < n; i++) {
            printf("Vertex %d -> Color %d\n", i, color[i]);
        }
    } else {
        printf("Solution does not exist.\n");
    }

    return 0;
}
