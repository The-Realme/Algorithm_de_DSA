#include <stdio.h>
#include <stdlib.h>
struct queue{
    int size;
    int f;
    int r;
    int *arr;
};
int isEmpty(struct queue * ptr){
    if(ptr->f==ptr->r){
        return 1;
    }
    return 0;
}
int isFull(struct queue *ptr){
    if(ptr->r==ptr->size-1){
        return 1;
    }
    return 0;
}
void enque(struct queue *ptr,int val){
    if(isFull(ptr)){
        printf("Queue overflow\n");
    }
    else{
        ptr->r++;
        ptr->arr[ptr->r] = val;
    }
}
int dequeue(struct queue *ptr){
    int a=-1;
    if(isEmpty(ptr)){
        printf("Queue is Empty nothig to pop");
        return 0;
    }
    else{
        ptr->f++;
        a=ptr->arr[ptr->f];

    }
    return a;
}
int main() {

    struct queue* q=(struct queue*)malloc(sizeof(struct queue));   //birth of queue
    q->size = 10;
    q->r = -1;
    q->f = -1;
    q->arr = (int *) malloc(q->size * sizeof(int));          //birth of the array in it
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    enque(q,56);
    enque(q,57);
    printf("Dequeing element: %d",dequeue(q));
    if(isFull(q)){
        printf("Queue is Full\n");
    }
    return 0;
}