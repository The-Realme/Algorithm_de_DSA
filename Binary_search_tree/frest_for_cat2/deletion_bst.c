#include<stdio.h>
#include<malloc.h>
 
struct node{
    int data;
    struct node* left;
    struct node* right;
};
 
struct node* createNode(int data){
    struct node *n; // creating a node pointer
    n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data; // Setting the data
    n->left = NULL; // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created node
}
 
void preOrder(struct  node* root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
 
void postOrder(struct  node* root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
 
void inOrder(struct  node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
 
int isBST(struct  node* root){
    static struct node *prev = NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data <= prev->data){
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}
 
struct node * searchIter(struct node* root, int key){
    while(root!=NULL){
        if(key == root->data){
            return root;
        }
        else if(key<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return NULL;
}
 
void insert(struct node *root, int key){
    struct node *prev = NULL;
    while(root!=NULL){
        prev = root;
        if(key==root->data){
            printf("Cannot insert %d, already in BST", key);
            return;
        }
        else if(key<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    struct node* new = createNode(key);
    if(key<prev->data){
        prev->left = new;
    }
    else{
        prev->right = new;
    }
}

struct node *inOrderPredecessor(struct node* root){
    // Go left once, then all the way right
    root = root->left;
    while (root != NULL && root->right != NULL) {
        root = root->right;
    }
    return root;
}
struct node *deleteNode(struct node *root, int value){
    if (root == NULL){
        return NULL; 
    }
    if (value < root->data){
        root->left = deleteNode(root->left, value);
    } 
    else if (value > root->data){
        root->right = deleteNode(root->right, value);
    } 
    else {
        // CASE 1 & 2: Node has 0 children or only 1 child
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp; // Connects parent directly to right child
        } 
        else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp; // Connects parent directly to left child
        }
        // CASE 3: Node has 2 children
        struct node* iPre = inOrderPredecessor(root);
        // Copy the predecessor's data to this node
        root->data = iPre->data;
        // Delete the old predecessor node from the left subtree
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}

 
int main(){
     
    // Constructing the root node - Using Function (Recommended)
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    // Finally The tree looks like this:
    //      5
    //     / \
    //    3   6
    //   / \
    //  1   4  
 
    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    inOrder(p);
    printf("\n");
    deleteNode(p, 3);
    inOrder(p);

    return 0;
}
