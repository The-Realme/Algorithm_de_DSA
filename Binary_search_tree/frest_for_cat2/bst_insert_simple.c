#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *right,*left;
};

struct node* newNode(int data){
    struct node* ptr= (struct node*)malloc(sizeof(struct node));
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

void preorder_traversal(struct node* ptr){
    if(ptr!=NULL){
    printf("%d ", ptr->data);
    preorder_traversal(ptr->left);
    preorder_traversal(ptr->right);}
}

void inorder_traversal(struct node* ptr){
    if(ptr!=NULL){
    inorder_traversal(ptr->left);
    printf("%d ", ptr->data);
    inorder_traversal(ptr->right);}
}
void postorder_traversal(struct node* ptr){
    if(ptr!=NULL){
    postorder_traversal(ptr->left);
    postorder_traversal(ptr->right);}
    printf("%d ", ptr->data);
}

int main() {
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Inorder Traversal: ");
    inorder_traversal(root);
    printf("\n");
    // print_tree_vertical(root);
    return 0;
}