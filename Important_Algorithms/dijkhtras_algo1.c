#include <stdio.h>
#include <stdbool.h>
#define V 4 
#define INF 99999
void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%d", j);
        return;
    }
    printPath(parent, parent[j]);
    printf(" -> %d", j);
}
void dijkstra(int graph[V][V], int start) {
    int distance[V];   
    bool visited[V];  
    int parent[V];
    for (int i = 0; i < V; i++) {
        distance[i] = INF;
        visited[i] = false;
        parent[i] = -1; 
    }
    distance[start] = 0;
    for (int i = 0; i < V - 1; i++) {
        int min = INF;
        int current_node;
        for (int j = 0; j < V; j++) {
            if (visited[j] == false && distance[j] <= min) {
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
                    parent[k] = current_node; 
                }
            }
        }
    }
    printf("Station \t Distance \t Shortest Path\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d \t\t ", i, distance[i]);
        printPath(parent, i);
        printf("\n");
    }
}
int main() {
    int graph[V][V] = {
        {0, 4, 2, 0},
        {4, 0, 1, 5}, 
        {2, 1, 0, 8}, 
        {0, 5, 8, 0} 
    };
    dijkstra(graph, 0);
    return 0;
}


