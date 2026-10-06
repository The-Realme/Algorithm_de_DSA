#include<stdio.h>
#include<stdlib.h>
 
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev; // 1. Added a previous pointer
};
 
// Traversal changes from a do-while loop to a standard while loop
void linkedlisttraversal(struct node* ptr){//thisisimportant for printing the whole linked list as an array
    while(ptr!=NULL)
    {
        printf(ptr->data);
        ptr=ptr->next;
    }
}
 
struct Node * insertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = NULL; //extra
    ptr->next = head; 
    head->prev = ptr; //extra
    return ptr;      
}
 
int main(){
    
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
 
    // Memory allocation looks identical
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
 
    // 5. Linking now requires setting BOTH next and prev pointers
    head->data = 4;
    head->prev = NULL;   // First node's prev is NULL
    head->next = second;
 
    second->data = 3;
    second->prev = head; // Points back to head
    second->next = third;
 
    third->data = 6;
    third->prev = second; // Points back to second
    third->next = fourth;
 
    fourth->data = 1;
    fourth->prev = third; // Points back to third
    fourth->next = NULL;  // 6. Terminates at NULL instead of looping back to head
 
    // Test the insertion and traversal
    head = insertAtFirst(head, 9);
    linkedListTraversal(head);
 
    return 0;
}
