#include <stdio.h>
# define INF 10000
# define V 4
void dijkstra(int A[V][V],int start){
int distance [V];
int visited [V];
for(int i=0;i<V;i++){
    distance [i]=INF;
    visited [i]=0;
}
distance[start]=0;
// distance and visited arrays are ready now 

for(int i=0;i<V;i++){
    int min=INF;
    int current_node=-1;

    for(int j=0;j<V;j++){
        if(visited[j]==0 && distance[j]<=min){
            min=distance[j];
            current_node=j;
        }
    }
    visited[current_node]=1;
    
    //final loop
    for(int k=0;k<V;k++){
        if(visited[k]==0 && A[current_node][k]!=0 && distance[current_node]!=INF){
            int new_distance=distance[current_node]+A[current_node][k];
            if(new_distance<=distance[k]){
                distance[k]=new_distance;
            }
        }
    }
}
printf("Station \t Shortest distance from A\n");
int counter=0;
    for (int i = 0; i < V; i++) {
        counter+=distance[i];
        printf("%d \t\t %d units\n", i, distance[i]);
    }
    printf("Shortest distance: %d",counter);
}

int main() {
    int graph[V][V] = {
        {0, 4, 2, 0},
        {4, 0, 1, 5}, 
        {2, 1, 0, 8}, 
        {0, 5, 8, 0} 
    };
    dijkstra(graph,0);
    return 0;
}