#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};
struct node* createnode(int data){
    struct node* ptr=(struct node)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;
}

struct node* insert(struct node* ptr,int data){
    if(ptr==NULL){
        return createnode(int data);
    }
    else if(ptr->data>data){
        return insert(ptr->left,data);
    }
    else{
        return insert(ptr->right,data);
    }
}
//The most important Checking if a given tree is a BST or not
int isBST(struct node* ptr){
    static struct node* prev=NULL;
    if(ptr!=NULL){
        if(!isBST(ptr->left)){
            return 0;
        }
        else(prev!=NULL && prev->data>=root->data){
            return 0;
        }
        // prev=ptr->right;
        // return root;
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

// left rotaion
// right rotaion


int main() {
    struct node * ptr=NULL;
    insert(ptr,100);
    insert(ptr,200);
    insert(ptr,300);
    insert(ptr,400);
    return 0;
}