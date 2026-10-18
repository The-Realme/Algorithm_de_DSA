#include <stdio.h>
#include <stdlib.h>

struct MinHeapNode {
    char data;
    unsigned frequency;
    struct MinHeapNode *left, *right;
};

// Helper function to allocate a new tree node
struct MinHeapNode* createNode(char data, unsigned freq) {
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->frequency = freq;
    return temp;
}

// Function to print codes from the root of Huffman Tree
void printCodes(struct MinHeapNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    // If it's a leaf node, it contains a character
    if (!(root->left) && !(root->right)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

void buildHuffmanTree(char data[], int freq[], int size) {
    // Array of node pointers to simulate a collection of trees
    struct MinHeapNode* nodes[size];
    for (int i = 0; i < size; i++) {
        nodes[i] = createNode(data[i], freq[i]);
    }

    int activeSize = size;

    // Loop until only one combined root tree is left
    while (activeSize > 1) {
        // Find the two nodes with the lowest frequencies
        int min1 = 0, min2 = 1;
        if (nodes[min1]->frequency > nodes[min2]->frequency) {
            min1 = 1; min2 = 0;
        }

        for (int i = 2; i < activeSize; i++) {
            if (nodes[i]->frequency < nodes[min1]->frequency) {
                min2 = min1;
                min1 = i;
            } else if (nodes[i]->frequency < nodes[min2]->frequency) {
                min2 = i;
            }
        }

        // Create a new internal node with a frequency equal to sum of the two nodes
        struct MinHeapNode* internalNode = createNode('$', nodes[min1]->frequency + nodes[min2]->frequency);
        internalNode->left = nodes[min1];
        internalNode->right = nodes[min2];

        // Replace one node with the internal node and remove the other
        nodes[min1] = internalNode;
        for (int i = min2; i < activeSize - 1; i++) {
            nodes[i] = nodes[i + 1];
        }
        activeSize--;
    }

    // The single remaining node is the root of the Huffman Tree
    int arr[100], top = 0;
    printf("Huffman Codes:\n");
    printCodes(nodes[0], arr, top);
}

int main() {
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(arr) / sizeof(arr[0]);

    buildHuffmanTree(arr, freq, size);
    return 0;
}
