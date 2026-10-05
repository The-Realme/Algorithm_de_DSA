#include <stdio.h>
#include <stdlib.h>

struct queue {
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct queue *ptr) {
    if (ptr->f == ptr->r) {
        return 1;
    }
    return 0;
}

int isFull(struct queue *ptr) {
    // MODIFIED: Checks if the next slot of 'r' hits 'f'
    if ((ptr->r + 1) % ptr->size == ptr->f) {
        return 1;
    }
    return 0;
}

void enque(struct queue *ptr, int val) {
    if (isFull(ptr)) {
        printf("Queue overflow\n");
    } else {
        // MODIFIED: Circular increment
        ptr->r = (ptr->r + 1) % ptr->size;
        ptr->arr[ptr->r] = val;
    }
}

int dequeue(struct queue *ptr) {
    int a = -1;
    if (isEmpty(ptr)) {
        printf("Queue is Empty, nothing to pop\n");
        return 0;
    } else {
        // MODIFIED: Circular increment
        ptr->f = (ptr->f + 1) % ptr->size;
        a = ptr->arr[ptr->f];
    }
    return a;
}

int main() {
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->size = 10;
    q->r = -1;
    q->f = -1;
    q->arr = (int *) malloc(q->size * sizeof(int));

    if (isEmpty(q)) {
        printf("Queue is empty\n");
    }

    enque(q, 56);
    enque(q, 57);
    
    printf("Dequeing element: %d\n", dequeue(q)); // Pops 56
    
    if (isFull(q)) {
        printf("Queue is Full\n");
    }
    
    return 0;
}
    