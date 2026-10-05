#include <stdio.h>
#include <stdlib.h>

struct deque {
    int size;
    int f;
    int r;
    int *arr;
};

// Check if deque is empty
int isEmpty(struct deque *ptr) {
    if (ptr->f == ptr->r) {
        return 1;
    }
    return 0;
}

// Check if deque is full
int isFull(struct deque *ptr) {
    if ((ptr->r + 1) % ptr->size == ptr->f) {
        return 1;
    }
    return 0;
}

// 1. Insert at Rear (Same as standard circular enqueue)
void insertRear(struct deque *ptr, int val) {
    if (isFull(ptr)) {
        printf("Deque Overflow: Cannot insert at rear\n");
    } else {
        ptr->r = (ptr->r + 1) % ptr->size;
        ptr->arr[ptr->r] = val;
        printf("Inserted %d at Rear\n", val);
    }
}

// 2. Insert at Front 
void insertFront(struct deque *ptr, int val) {
    if (isFull(ptr)) {
        printf("Deque Overflow: Cannot insert at front\n");
    } else {
        // Move front backward circularly. Adding ptr->size handles negative indexing.
        ptr->arr[ptr->f] = val; // Store value at current 'f' position
        ptr->f = (ptr->f - 1 + ptr->size) % ptr->size; 
        printf("Inserted %d at Front\n", val);
    }
}

// 3. Delete from Front (Same as standard circular dequeue)
int deleteFront(struct deque *ptr) {
    if (isEmpty(ptr)) {
        printf("Deque Underflow: Nothing to delete from front\n");
        return -1;
    } else {
        ptr->f = (ptr->f + 1) % ptr->size;
        int val = ptr->arr[ptr->f];
        return val;
    }
}

// 4. Delete from Rear
int deleteRear(struct deque *ptr) {
    if (isEmpty(ptr)) {
        printf("Deque Underflow: Nothing to delete from rear\n");
        return -1;
    } else {
        int val = ptr->arr[ptr->r];
        // Move rear backward circularly. Adding ptr->size handles negative indexing.
        ptr->r = (ptr->r - 1 + ptr->size) % ptr->size;
        return val;
    }
}

int main() {
    struct deque* dq = (struct deque*)malloc(sizeof(struct deque));
    dq->size = 5; // Max elements it can safely hold is 4 (size - 1)
    dq->f = 0;    // Starting both at 0 simplifies backward circular math
    dq->r = 0;
    dq->arr = (int *) malloc(dq->size * sizeof(int));

    printf("--- Testing Deque Operations ---\n");

    // Insert elements from both ends
    insertRear(dq, 10);  // Queue looks like: [ _ , 10, _ , _ , _ ]
    insertRear(dq, 20);  // Queue looks like: [ _ , 10, 20, _ , _ ]
    insertFront(dq, 30); // Queue looks like: [ 30, 10, 20, _ , _ ]

    // Try deleting from front
    printf("Deleted from Front: %d\n", deleteFront(dq)); // Should give 30
    
    // Try deleting from rear
    printf("Deleted from Rear: %d\n", deleteRear(dq));   // Should give 20

    // Clean up memory
    free(dq->arr);
    free(dq);
    return 0;
}
