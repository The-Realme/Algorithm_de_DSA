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
// -----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue * ptr) {
    if (ptr->f == ptr->r) {
        return 1;
    }
    return 0;
}

int isFull(struct queue *ptr) {
    // CHANGE 1: Since r starts at 0, it reaches the capacity boundary at 'size' rather than 'size - 1'
    if (ptr->r == ptr->size) {
        return 1;
    }
    return 0;
}

void enque(struct queue *ptr, int val) {
    if (isFull(ptr)) {
        printf("Queue overflow\n");
    }
    else {
        // CHANGE 2: Insert the element at the current 'r' position first, THEN increment 'r'
        ptr->arr[ptr->r] = val;
        ptr->r++;
    }
}

int dequeue(struct queue *ptr) {
    int a = -1;
    if (isEmpty(ptr)) {
        printf("Queue is Empty nothing to pop\n"); // Fixed typo 'nothig'
        return 0;
    }
    else {
        // CHANGE 3: Extract the element at the current 'f' position first, THEN increment 'f'
        a = ptr->arr[ptr->f];
        ptr->f++;
    }
    return a;
}

int main() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));   
    q->size = 10;
    
    // CHANGE 4: Initialize both front and rear to 0
    q->r = 0;
    q->f = 0;
    
    q->arr = (int *) malloc(q->size * sizeof(int));          
    
    if (isEmpty(q)) {
        printf("Queue is empty\n");
    }
    
    enque(q, 56);
    enque(q, 57);
    
    printf("Dequeing element: %d\n", dequeue(q));
    
    if (isFull(q)) {
        printf("Queue is Full\n");
    }
    
    // Clean up memory (Good practice!)
    free(q->arr);
    free(q);
    
    return 0;
}
