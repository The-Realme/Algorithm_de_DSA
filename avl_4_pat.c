#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    int *left,*right;
    int height;
};
int getheight(struct node* ptr){
    if(ptr==NULL){
        return NULL;
    }
    return ptr->height;
}

int balancefactor(struct node* ptr){
    if(ptr==NULL){
        return NULL;
    }
    return height(ptr->left)-height(ptr->right);
}

int max(int x,int y){
    return (x>y)?x:y;
}

struct node* createnode(int data){
    struct node* ptr=(struct node)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->right=NULL;
    ptr->left=NULL;
    return ptr;
}
struct node* rightrotate(struct node* y){
    struct node* x=y->left;
    struct node* T2=y->left->right;
    x->right=y;
    y->left=T2;
    y->height=max(getheight(y->right),getheight(y->left))+1;
    x->height=max(getheight(x->right),getheight(x->left))+1;
    return x;
}
struct node* leftrotate(struct node* x){
    struct node* y=x->right;
    struct node* T2=y->left;
    y->left=x;
    x->right=T2;
    x->height=max(getheight(x->right),getheight(x->left))+1;
    y->height=max(getheight(y->right),getheight(y->left))+1;
    return y;

}
struct node* insert(struct node* root,int data){
    if(root==NULL){
        return createnode(data);
    }
    if(root->data>data){
        root->left=insert(root->left,data);
    }
    else if(root->data<data){
        root->right=insert(root->right,data);
    }

    node->height=getheight(root);
    int bf=balancefactor(root);
    
    //left left
    if(bf>1 && root->left->data>data){
        return rightrotate(root);
    }
    //left right
    else if(bf>1 && root->left->data<data){
        return rightrotate(root);
    }
    
    //right right
    if(bf<-1 && root->right->data<data){
        return leftrotate(root);
    }
    //right left
    else if(bf<-1 && root->right->data>data){
        return leftrotate(root);
    }
    
}

int main() {
    struct node* root=NULL;
    root=insert(root);
    return 0;
}