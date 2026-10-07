#include <stdio.h>
struct queue{
    int size;
    int f,r;
    int * arr;
};
int isempty(struct queue* ptr){
    if(ptr->f==ptr->r){
        return 1;
    }
    return 0;
}

int isfull(struct queue* ptr){
    // if(ptr->r=(ptr->f+1)%ptr->size){
    if ((ptr->r + 1) % ptr->size == ptr->f) {
        return 1;
    }
    return 0;
}

void enqueue(struct queue* ptr,int data){
    if(isfull(ptr)){
        printf("Circular queue overflow!");
    }
    else{
        ptr->r=(ptr->r+1)%ptr->size;
        ptr->arr[ptr->r]=data;

    }
}
int dequeue(struct queue* ptr){
    int a=-1;
    if(isempty(ptr)){
        printf("Circular queue underflowflow!");
        return 0;
    }
    else{
        ptr->f=(ptr->f+1)%ptr->size;
        a=ptr->arr[ptr->f];
    }
    return a;
}
int main() {
    struct queue* ptr=(struct queue*)malloc(sizeof(struct queue));
    ptr->size=6;
    ptr->f=-1;
    ptr->r=-1;
    ptr->arr=(int*)malloc(ptr->size*sizeof(int));
    enque(ptr,10);
    enque(ptr,10);
    enque(ptr,10);
    enque(ptr,10);
    return 0;
}