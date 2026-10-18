#include <stdio.h>

#define MAX_EDGES 15

struct Edge {
    int src, dest, weight;
};

// Simplified find function to trace the root parent of a node
int findRoot(int i, int parent[]) {
    while (parent[i] != -1)
        i = parent[i];
    return i;
}

// Simplified union function to link two subsets
void unionSubsets(int i, int j, int parent[]) {
    parent[i] = j;
}

void kruskalMST(struct Edge edges[], int numVertices, int numEdges) {
    struct Edge result[numVertices]; // To store the final MST edges
    int parent[numVertices];
    
    // Initialize parent array tracking paths
    for (int i = 0; i < numVertices; i++) {
        parent[i] = -1;
    }

    // Step 1: Sort all edges using simple Bubble Sort
    for (int i = 0; i < numEdges - 1; i++) {
        for (int j = 0; j < numEdges - i - 1; j++) {
            if (edges[j].weight > edges[j+1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j+1];
                edges[j+1] = temp;
            }
        }
    }

    int edgeCount = 0; // Index for result[]
    int i = 0;         // Index for sorted edges[]

    // Number of edges in MST must be V-1
    while (edgeCount < numVertices - 1 && i < numEdges) {
        struct Edge nextEdge = edges[i++];

        int x = findRoot(nextEdge.src, parent);
        int y = findRoot(nextEdge.dest, parent);

        // If including this edge doesn't cause a cycle
        if (x != y) {
            result[edgeCount++] = nextEdge;
            unionSubsets(x, y, parent);
        }
    }

    // Print the constructed MST
    printf("Edges in the constructed MST:\n");
    int totalCost = 0;
    for (i = 0; i < edgeCount; ++i) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        totalCost += result[i].weight;
    }
    printf("Total Cost of MST: %d\n", totalCost);
}

int main() {
    int numVertices = 4;
    int numEdges = 5;
    struct Edge edges[MAX_EDGES] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskalMST(edges, numVertices, numEdges);
    return 0;
}
