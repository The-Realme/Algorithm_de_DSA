#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};
void linked_list(struct node * ptr){
    while(ptr!=NULL){
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}
struct node* insert_in_beginning(struct node* head,int data){
    struct node * ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
}

struct node* insert_in_between(struct node* index1,int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=index1->next;
    index1->next=ptr;
    return ptr;
}

int main() {
    struct node * first;
    struct node * second;
    struct node * third;
    struct node * zeroth;
    struct node * end1;
    struct node * btw;
    first=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    zeroth=(struct node*)malloc(sizeof(struct node));
    end1=(struct node*)malloc(sizeof(struct node));
    btw=(struct node*)malloc(sizeof(struct node));
    zeroth->data=0;
    zeroth->next=first;
    first->data=1;
    first->next=second;
    second->data=2;
    second->next=btw;
    btw->data=100;
    btw->next=third;
    third->data=3;
    third->next=end1;
    end1->data=4;
    end1->next=NULL;
    linked_list(zeroth);
    printf("After function\n");
    btw=insert_in_between(btw,1000);
    zeroth=insert_in_beginning(zeroth,-1);
    linked_list(zeroth);

    return 0;
}