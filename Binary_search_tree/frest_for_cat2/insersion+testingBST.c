#include <stdio.h>
#include <stdlib.h>

// Define the tree node structure
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Helper function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Your original isBST function
int isBST(struct node* root) {
    static struct node *prev = NULL;
    if (root != NULL) {
        if (!isBST(root->left)) {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data) {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else {
        return 1;
    }
}

int main() {
    // Let's build the BROKEN tree from our example:
    //          20
    //        /    \
    //      10      30
    //     /  \    /
    //    5   15  12   <-- The Impostor!

    struct node* root = createNode(20);
    root->left = createNode(10);
    root->right = createNode(30);
    
    root->left->left = createNode(5);
    root->left->right = createNode(15);
    
    root->right->left = createNode(12); // This breaks the BST rule

    // Run the test
    printf("Checking if the tree is a valid BST...\n");
    if (isBST(root)) {
        printf("Result: This is a VALID Binary Search Tree!\n");
    } else {
        printf("Result: Invalid tree! (Function successfully returned 0)\n");
    }

    // Clean up memory (Good practice!)
    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
