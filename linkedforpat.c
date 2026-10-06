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
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
}

//insert in the first wrong XXX
struct node* insert_first1(struct node* head,int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
        ptr->data=data;
        ptr->next=head;
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
    struct node* p=head;
    head=head->next;
    free(p);
    return head;
    
}


struct node* delete_at_index(struct node* head, int index){ //this is the 5th issue
    struct node* p=head;
    struct node* q=head->next;
    for(int i=0;i<index-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
    
}
struct node* delete_last(struct node* head){  //this is the 6th issue
    struct node* p=head;
    struct node* q=head->next;
    // for(int i=0;i<;i++){
    //     p=p->next;
    //     q=q->next;
    // }
    while(q->next!=NULL){
            p=p->next;
            q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;

}

// now the circularlinkedlist
void circularlinkedlistTraversal(struct node* head){
    struct node* ptr=head;
    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr->next!=head);
}

struct node* insert_first(struct node* head){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* p=head->next;
    while(p->next!=head){
        p=p->next;
    }
    p->next=ptr;
    ptr->data=100;
    ptr->next=head;
    return ptr;
}

int main() {
    struct node* head=(struct node*)malloc(sizeof(struct node));
    struct node* first=(struct node*)malloc(sizeof(struct node));
    struct node* second=(struct node*)malloc(sizeof(struct node));
    struct node* third=(struct node*)malloc(sizeof(struct node));
    struct node* fourth=(struct node*)malloc(sizeof(struct node));
    head->data=1;
    head-next=first;
    //use the manual way of creating the linked list
    linkedListTraversal(head);   //use this for checking the print
    head=insert_end(head,10);
    linkedListTraversal(head);


    return 0;
}