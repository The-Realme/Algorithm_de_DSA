#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *right,*left;
};

struct node* newNode(int data){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
}

struct node* insert(struct node* ptr,int data){
    if(ptr==NULL){
        return newNode(data);
    }
    if(data<ptr->data){
        ptr->left=insert(ptr->left,data);
    }
    else if(data>ptr->data){
        ptr->right=insert(ptr->right,data);
    }
    return ptr;
}

void inorder_traversal(struct node* ptr){
    if(ptr!=NULL){
        inorder_traversal(ptr->left);
        printf("%d ",ptr->data);
        inorder_traversal(ptr->right);
    }
}

struct node* search(struct node* ptr,int key){
    if(ptr==NULL){
        return NULL;
    }
    if(ptr->data==key){
        return ptr;
    }
    else if(ptr->data>key){
        return search(ptr->left,key);
    }
    else{
        return search(ptr->right,key);
    }
}

struct node* search_iter(struct node* ptr,int key){
    while(ptr!=NULL){
        if(ptr->data==key){
            return ptr;
        }
        else if(ptr->data>key){
            ptr=ptr->left;
        }
        else{
            ptr=ptr->right;
        }
    }
    return NULL;
}   

int main() {
    struct node* root=NULL;
    root=insert(root,10);
    insert(root,20);
    insert(root,30);
    insert(root,50);
    insert(root,1);
    insert(root,90);
    inorder_traversal(root);
    // struct node* tem=search(root,50);
    insert(root,510);
    struct node* tem=search_iter(root,510);
    if(tem!=NULL){
        printf("element found: %d",tem->data);
    }
    else{
        printf("element not found");
    }
    return 0;
}