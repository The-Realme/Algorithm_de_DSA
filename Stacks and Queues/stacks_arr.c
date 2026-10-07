#include<stdio.h>
#include<stdlib.h>
 //this is the dynamic arrray implementation
struct stack{
    int size;
    int r;
    int* arr;
};

int isEmpty(struct stack* ptr){
    if(ptr->r == -1){
            return 1;
        }
        else{
            return 0;
        }
}

int isFull(struct stack* ptr){
    if(ptr->r == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}
 
void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->r++;
        ptr->arr[ptr->r] = val;
    }
}
 
int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->r];
        ptr->r--;
        return val;
    }
}
 
int main(){
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10;
    sp->r = -1;
    // OR
//struct stack sp;
//sp.size = 10;
//sp.r = -1;
// and push /pop methods change as->
// push(&sp, 15);
// push(&sp, 23);
// printf("Popped element: %d\n", pop(&sp));
    

    sp->arr = (int *) malloc(sp->size * sizeof(int));
    // printf("Stack has been created successfully\n");
    push(sp, 1);
    push(sp, 23);
    push(sp, 99);
    push(sp, 75);
    push(sp, 3);
    push(sp, 64);
    push(sp, 57);
    push(sp, 46);
    push(sp, 89);
    push(sp, 6); // ---> Pushed 10 values 
    // push(sp, 46); // Stack Overflow since the size of the stack is 10
    // printf("After pushing, Full: %d\n", isFull(sp));
    // printf("After pushing, Empty: %d\n", isEmpty(sp));

    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
    printf("Popped %d from the stack\n", pop(sp)); // --> Last in first out!
 
    return 0;
}
