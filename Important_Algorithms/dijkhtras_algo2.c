#include <stdio.h>
#include <stdbool.h>
#define V 4  // Total number of stations (Vertices)
#define INF 99999 // A large number to act as Infinity
void dijkstra(int graph[V][V], int start) {
    int distance[V];   
    bool visited[V];  
    for (int i = 0; i < V; i++) {
        distance[i] = INF;
        visited[i] = false;
    }
    distance[start] = 0;
    for (int i = 0; i < V - 1; i++) {
        int min = INF;
        int current_node;
        for (int j = 0; j < V; j++) {
            if (visited[i] == false && distance[i] <= min) {
                min = distance[j];
                current_node = j;
            }
        }
        visited[current_node] = true;
        for (int k = 0; k < V; k++) {
            if (!visited[k] && graph[current_node][k] != 0 && distance[current_node] != INF) {
                int new_distance = distance[current_node] + graph[current_node][k];
                if (new_distance < distance[k]) {
                    distance[k] = new_distance; 
                }
            }
        }
    }
    printf("Station \t Shortest Time from A\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d minutes\n", i, distance[i]);
    }
}
int main() {
    int graph[V][V] = {
        {0, 4, 2, 0},
        {4, 0, 1, 5}, 
        {2, 1, 0, 8}, 
        {0, 5, 8, 0} 
    };

    dijkstra(graph, 0); // Start from station 0 (A)
    return 0;
}