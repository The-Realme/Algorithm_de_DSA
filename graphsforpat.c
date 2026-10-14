#include <stdio.h>
#include <stdlib.h>
//BFS
//DFS
//both are issues
// DFS no longer ins
int visited[7]={0,0,0,0,0,0,0};
int A[7][7]={{0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} };
void DFS(int i){
    printf("%d ",i);
    visited[i]=1;
    for(int j=0;j<7;j++){
        if(A[i][j]==1 && !visited[j]){
            DFS(j);
        }
    }
}
struct queue{
    int size;
    int f;
    int r;
    int * arr;
};

int isfull(struct queue* q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
int isEmpty(){
    if(q->f==q->r){
        return 1;
    }
    return 0;
}

void enqueue(struct queue* q;int data){
if(isfull(q)){
    printf("Queue overflow");
}
else{
    q->r++;
    q->arr[q->r]=val;
}
}

int dequeue(){
    int a=-1;
    if(isEmpty(q)){
        printf("Queue underflow");
    }
    else{
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}
int main() {
    // DFS(0);
    
    return 0;
}