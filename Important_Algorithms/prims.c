#include <stdio.h>
#define V 5 
#define INF 999999
int findMinKey(int key[], int inMST[]) {
    int min = INF;
    int min_index = -1;

    for (int i = 0; i < V; i++) {
        if (inMST[i] == 0 && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}
void primMST(int graph[V][V]) {
    int parent[V];  // Stores the final edges of the MST
    int key[V];     // Keeps track of the lowest weight to connect each vertex
    int inMST[V];   // Custom tracker: 1 if inside MST, 0 if not

    // Initialize all tracking arrays
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        inMST[i] = 0; // 0 means "not yet included"
    }
    key[0] = 0;     
    parent[0] = -1; // Root node has no parent
    // The MST will grow until it connects all V vertices
        for (int i = 0; i < V; i++) {
        // 1. Find the best vertex to pick next using our helper function
        int u = findMinKey(key, inMST);
        // Safety check: stops if the remaining graph is completely disconnected
        if (u == -1) break;
        inMST[u] = 1;
        for (int j = 0; j < V; j++) {
            if (graph[u][j] != 0 && inMST[j] == 0 && graph[u][j] < key[j]) {
                parent[j] = u;
                key[j] = graph[u][j];
            }
        }
    }

    // Print the final MST results
    printf("Edge \tWeight\n");
    int totalCost = 0;
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }
    printf("Total Cost of MST: %d\n", totalCost);
}

int main() {
    // The input graph (Adjacency Matrix)
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    // Run the algorithm
    primMST(graph);
    
    return 0;
}
