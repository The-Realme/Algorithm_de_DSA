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
    for (int i = 0; i < V - 1; i++) {
        
        // 1. Find the best vertex to pick next using our helper function
        int u = findMinKey(key, inMST);

        // 2. Put this vertex into our MST
        inMST[u] = 1;

        // 3. Update the tracking keys for all neighbors of vertex 'u'
        for (int i = 0; i < V; i++) {
            // Check if:
            // - There is a valid connection (graph[u][i] != 0)
            // - The neighbor is not already in the tree (inMST[i] == 0)
            // - This new pathway is cheaper than its current known pathway
            if (graph[u][i] != 0 && inMST[i] == 0 && graph[u][i] < key[i]) {
                parent[i] = u;
                key[i] = graph[u][i];
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
