#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
};

//linkedlisttraversal missing:1
void linkedlisttraversal(struct node* ptr){//thisisimportant for printing the whole linked list as an array
    while(ptr!=NULL)
    {
        printf(ptr->data);
        ptr=ptr->next;
    }

}

//insert in the first wrong XXX
struct node* insert(struct node* head,int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
        ptr->data=data;
        ptr->next=head//this is the issue1;
    return ptr;
}

struct node* insert_at_index(struct node* head,int index,int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* temp=head;
    //temp is missing
    int i=0;
    while(i!=index-1){
        temp=temp->next;
        i++;
    }
    //this is the second issue
    ptr->data=data;
    ptr->next=temp->next;
    temp->next=ptr;
    return head;
}

struct node* insert_end(struct node* head,int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* temp=head;
    while(temp->next!=NULL){
        temp->next=temp;
    }
    temp->next=ptr;
    ptr->data=data;
    ptr->next=NULL;
    return head;
}

struct node* delete_first(struct node* head){  //this isthe fourth issue
    
}
struct node* delete_at_index(struct node* head, int index){ //this is the 5th issue

}
struct node* delete_last(struct node* head){  //this is the 6th issue
struct node* temp=head;
while(temp->next!=NULL){
    temp=temp->next;
}
    temp=NULL;
    // or 
    free temp;
}

//or is these anything like delete at index   //issue 7

//issue 8: also the circular linked list

int main() {
    struct node* head=(struct node*)malloc(sizeof(struct node));
    struct node* first=(struct node*)malloc(sizeof(struct node));
    struct node* second=(struct node*)malloc(sizeof(struct node));
    struct node* third=(struct node*)malloc(sizeof(struct node));
    struct node* fourth=(struct node*)malloc(sizeof(struct node));
    head->data=1;
    head-next=first;




    return 0;
}