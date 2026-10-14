#include <stdio.h>

int visited[7] = {0,0,0,0,0,0,0};
int A[7][7] = {
    {0,1,1,1,0,0,0},
    {1,0,1,0,0,0,0},
    {1,1,0,1,1,0,0},
    {1,0,1,0,1,0,0},
    {0,0,1,1,0,1,1},
    {0,0,0,0,1,0,0},
    {0,0,0,0,1,0,0}
};

void BFS(int start) {
    int queue[7];
    int f = 0, r = 0; // Front and Rear pointers for the queue

    // Enqueue start node
    printf("%d ", start);
    visited[start] = 1;
    queue[r++] = start; 

    while (f < r) {
        int node = queue[f++]; // Dequeue
        
        for (int j = 0; j < 7; j++) {
            if (A[node][j] == 1 && !visited[j]) {
                printf("%d ", j);
                visited[j] = 1;
                queue[r++] = j; // Enqueue
            }
        }
    }
}

int main() {
    BFS(0);
    return 0;
}
