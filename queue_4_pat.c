#include <stdio.h>
#include <stdlib.h>
struct queue{
    int size;
    int f,r;
    int* arr;
};
int isempty(struct queue* ptr){
    if(ptr->f==ptr->r){
        return 1;
    }
    return 0;
}
int isfull(struct queue* ptr){
    if(ptr->r==ptr->size-1){
        return 1;
    }
    return 0;
}
void enqueue(struct queue* ptr,int data){
    if(isfull(ptr)){
        printf("Queue Overflow\n");
    }
    else{
        ptr->r++;
        ptr->arr[ptr->r]=data;
    }
}

int dequeue(struct queue* ptr){
    int a=-1;
    if(isempty(ptr)){
        printf("Queue is empty\n");
    }
    else{
        ptr->f++;
        a=ptr->arr[ptr->f];
    }
    return a;
}
int main() {
    struct queue* ptr=(struct queue*)malloc(sizeof(struct queue));
    ptr->size=6;
    ptr->f=-1;
    ptr->r=-1;
    ptr->arr = (int *) malloc (ptr->size * sizeof(int)); 
    enqueue(ptr,10);
    enqueue(ptr,10);
    enqueue(ptr,10);
    enqueue(ptr,10);
    enqueue(ptr,10);
    enqueue(ptr,10);
    enqueue(ptr,10);
    return 0;
}