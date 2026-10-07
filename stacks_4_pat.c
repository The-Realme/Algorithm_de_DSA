#include <stdio.h>
#include <stdlib.h>
struct stack{
    int size;
    int r;
    int * arr;
};
int isfull(struct stack* ptr){
    if(ptr->r==ptr->size-1){
        return 1;
    }
    return 0;
}
int isempty(struct stack* ptr){
    if(ptr->r==-1){
        return 1;
    }
    return 0;
}

void push_back(struct stack* ptr,int data){
    if(isfull(ptr)){
        printf("Stack overflow!!");
    }
    ptr->r++;
    ptr->arr[ptr->r]=data;
}
int pop_back(struct stack* ptr){
    if(isempty(ptr)){
        printf("Stack is empty and nothing is there to pop");
    }
    else{
        int a=ptr->arr[ptr->r];
        ptr->r--;
        return a;
    }
}

int main() {
    struct stack* ptr=(struct stack*)malloc(sizeof(struct stack));
    ptr->r=-1;
    ptr->size=3;
    ptr->arr=(int*)malloc(ptr->size*sizeof(int));
    // isempty(ptr);
    push_back(ptr,10);
    push_back(ptr,10);
    push_back(ptr,10);
    push_back(ptr,10);
    return 0;
}