#include <stdio.h>

#define V 4       // Total number of stations (Vertices)
#define INF 99999 // A large number to act as Infinity

void dijkstra(int graph[V][V], int start) {
    int distance[V];   // Stores the shortest distance from start to node i
    int visited[V];    // Custom tracker: 1 if processed, 0 if not
    
    // 1. Initialize tracking arrays
    for (int i = 0; i < V; i++) {
        distance[i] = INF; // Start assuming everything is infinitely far away
        visited[i] = 0;    // 0 means "not yet visited/processed"
    }
    
    // Distance from the starting station to itself is always 0
    distance[start] = 0;
    
    // 2. Main Dijkstra's Loop
    for (int i = 0; i < V ; i++) {
        // Step A: Find the unvisited vertex with the minimum distance value
        int min = INF;
        int current_node = -1;

        for (int j = 0; j < V; j++) {
            if (visited[j] == 0 && distance[j] <= min) {
                min = distance[j];
                current_node = j;
            }
        }
        // Step B: Mark the picked vertex as processed
        visited[current_node] = 1;
        // Step C: Update the distance values of the adjacent vertices
        for (int k = 0; k < V; k++) {
            // Check if:
            // 1. The neighbor 'k' hasn't been visited yet
            // 2. There is a valid track connecting them (graph[current_node][k] != 0)
            // 3. The current node itself is reachable (distance[current_node] != INF)
            if (visited[k] == 0 && graph[current_node][k] != 0 && distance[current_node] != INF) {
                
                int new_distance = distance[current_node] + graph[current_node][k];
                
                // If the new path through 'current_node' is shorter, update it!
                if (new_distance < distance[k]) {
                    distance[k] = new_distance; 
                }
            }
        }
    }
    
    // 3. Print the final shortest paths
    printf("Station \t Shortest Time from A\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d minutes\n", i, distance[i]);
    }
}

int main() {
    // The input transit network (Adjacency Matrix)
    int graph[V][V] = {
        {0, 4, 2, 0},
        {4, 0, 1, 5}, 
        {2, 1, 0, 8}, 
        {0, 5, 8, 0} 
    };

    // Run the algorithm starting from station 0
    dijkstra(graph, 0); 
    
    return 0;
}
