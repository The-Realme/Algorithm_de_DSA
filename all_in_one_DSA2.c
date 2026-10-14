// Linkedlist
// trees
// graph
#include <stdio.h>
#include <stdlib.h>
struct ll{ //for linkedlist
    int data;
    struct ll* next;
};
struct node1{  //for BST
    int data;
    struct node1 *left,*right;
};
struct node2{  //for AVL
    int data;
    struct node2 *left,*right;
    int height;
};

void linkedlisttraversal(struct ll* ptr){
    while(ptr!=0){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

struct ll* ll_insersion_front(struct ll* head,int data){  
    struct ll* ptr=(struct ll*)malloc(sizeof(struct ll));
    ptr->data=data;
    ptr->next=head;
    return ptr;
}

struct ll* ll_insersion_at_index(struct ll* head,int data,int index){
    struct ll* ptr=(struct ll*)malloc(sizeof(struct ll));
    struct ll* temp=head;
    int n=0;
    while(n<index-1){
        temp=temp->next;
        n++;
    }
    ptr->next=temp->next;
    ptr->data=data;
    temp->next=ptr;
    return head;
}

struct ll* ll_insersion_at_end(struct ll* head,int data){       
    struct ll* ptr=(struct ll*)malloc(sizeof(struct ll));
    struct ll* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=ptr;
    ptr->data=data;
    ptr->next=NULL;
    return head;
}

struct ll* ll_insersion_after_a_node(struct ll* prev,int data){
    struct ll* ptr=(struct ll*)malloc(sizeof(struct ll));
    ptr->data=data;
    ptr->next=prev->next;
    prev->next=ptr;
    return prev;
}

// int ll_deletion(struct ll* head){
    // does this also have front, mid and end?
// }                                //--------------------1.
// circular and doubly linked list

struct node1* createnewnode(int data){
    struct node1* ptr=(struct node1*)malloc(sizeof(struct node1));
    ptr->data=data;
    ptr->right=NULL;
    ptr->left=NULL;
    return ptr;
}

struct node1* insersion(struct node1* root,int data ){
    if(root==NULL){
        return createnewnode(data);
    }
    if(root->data>data){
        root->left=insersion(root->left,data);
    }
    if(root->data<data){
        root->right=insersion(root->right,data);
    }
    return root;
}

int isBST(struct node1* ptr){
    static struct node1* prev=NULL;
    if(ptr!=NULL){
        if(!isBST(ptr->left)){
            return 0;
        }
        else if(prev!=NULL && ptr->data<=prev->data) {
            return 0;
        }
        prev=ptr;
        return isBST(ptr->right);
    }
    else{
        return 1;
    }
}
// treetraversals
void preorder(struct node1* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node1* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void postorder(struct node1* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int search_recur(struct node1* ptr,int target){
    if(ptr!=NULL){
        return -1;
    }
    else if(ptr->data==target){
        return 1;
    }
    else if(ptr->data>target){
        return search_recur(ptr->left,target);
    }
    return search_recur(ptr->right,target);
}
int search_iter(struct node1* ptr,int target){
    while(ptr!=NULL){
    else if(ptr->data==target){
        return 1;
    }
    else if(ptr->data>target){
        ptr=(ptr->left,target);
    }
    ptr=(ptr->right,target);
}
return -1;
}

// Deletion is the major issue here          2.

int max(int a,int b){
    return(a>b)?a:b;
}
struct node2* createAVLnode(int data){
    struct node2* ptr=(struct node2*)malloc(sizeof(struct node2));
    ptr->left=NULL;
    ptr->right=NULL;
    ptr->data=data;
    ptr->height=1;
    return ptr;
}
int getheight(struct node2* ptr){
    return ptr->height;
}
int bf(struch node2* ptr){
    return ptr->left->height-ptr->right->height;
}
struct node2 right_rotate(struct node* y){
    struct node2* x=y->left;
    struct node2* T2=x->right;
    x->right=y;
    y->left=T2;
    y->height=max(getheight(y->right),getheight(y->left))+1;
    x->height=max(getheight(x->right),getheight(x->left))+1;
    return x;
}
struct node2 left_rotate(struct node* x){
    struct node2* y=x->right;
    struct node2* T2=y->left;
    y->left=x;
    x->right=T2;
    x->height=max(getheight(x->right),getheight(x->left))+1;
    y->height=max(getheight(y->right),getheight(y->left))+1;
    return y;

}
struct node2* insersion_AVL(struct node* root,int data){
    if(root==NULL){
        return createnewnode(data);
    }
    if(data<root->data){
        return insersion_AVL(root->left,data);
    }        
    else if(data>root->data){
        return insersion_AVL(root->right,data);
        
    }
    int bf=bf(root);
    root->height=max(getheight(root->right),getheight(root->left))+1;

    if(bf<-1 && data>root->left->data){
        return left_rotate(root);
    }
    if(bf>1 && data<root->left->data){
        return right_rotate(root);
    }

    
    if(bf<-1 && data<root->left->data){
        root->right=right_rotate(root->right);
        return left_rotate(root);
    }
    if(bf>1 && data>root->left->data){
        root->left=left_rotate(root->left);
        return right_rotate(root);
    }
    return root;
}

//This full AVL is pending                          3.

// Report for revision 1: 
// 1.Circular and double linked list with deletion
// 2. deletion is the BST
// 3. AVL trees
// 4. Full graph


// ok so lets start with DFS 
int visited[7]={0,0,0,0,0,0,0};
int A[7][7]={{0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} };
    void DFS(int i){
        printf("%d ",i);
        visited[i]=1;
        for(int j=0;j<7;j++){
            if(A[i][j]==1 && !visited[j]){
                DFS(j);
            }
        }
    }

int main() {
    //For the linked list
    struct ll* head=(struct ll*)malloc(sizeof(struct ll));
    struct ll* second=(struct ll*)malloc(sizeof(struct ll));
    struct ll* third=(struct ll*)malloc(sizeof(struct ll));
    struct ll* final=(struct ll*)malloc(sizeof(struct ll));
    head->data=10;
    head->next=second;
    second->data=120;
    second->next=third;
    third->data=1330;
    third->next=final;
    final->data=1230;
    final->next=NULL;
    // linkedlisttraversal(head);
    // ll_insersion_at_end(head,999);
    // ll_insersion_after_a_node(second,111); //perfect
    // ll_insersion_at_index(head,786,2);   //perfect
    // ll_insersion_front(head,125);
    // printf("\nafter inserting after the node-\n");
    // linkedlisttraversal(head);
// ---------------------------------------------linkedlist-------------DONE--------------

//for the trees

    struct node1* root=NULL;
    root=insersion(root,122);
    insersion(root,15);
    insersion(root,82);
    insersion(root,135);
    insersion(root,100);
    insersion(root,10);
    inorder(root);
    int f = isBST(root);
    if(f==1){
        printf("\nThis is the correct BST algo u have written USER");

    }
    else{
        printf("Check the algo u have written ");
    }

    DFS(0);


    return 0;
}
