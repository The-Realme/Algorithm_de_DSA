#include <stdio.h>

#define MAX 50

struct Node {
    char ch;
    int freq;
    int left;
    int right;
    int merged; // 0 = available, 1 = already merged
};

struct Node tree[MAX];

// Print codes by walking from root to leaf (Left = 0, Right = 1)
void print_codes(int root, int code[], int top) {
    int i;

    if (tree[root].left != -1) {
        code[top] = 0;
        print_codes(tree[root].left, code, top + 1);
    }

    if (tree[root].right != -1) {
        code[top] = 1;
        print_codes(tree[root].right, code, top + 1);
    }

    // Leaf node reached: print character and its binary code
    if (tree[root].left == -1 && tree[root].right == -1) {
        printf("%c\t| %d\t\t| ", tree[root].ch, tree[root].freq);
        for (i = 0; i < top; i++) {
            printf("%d", code[i]);
        }
        printf("\n");
    }
}

void huffman_abdul_bari(char chars[], int freqs[], int n) {
    int i, j;
    int total_nodes = n;

    // 1. Create initial leaf nodes for all characters
    for (i = 0; i < n; i++) {
        tree[i].ch = chars[i];
        tree[i].freq = freqs[i];
        tree[i].left = -1;
        tree[i].right = -1;
        tree[i].merged = 0;
    }

    // 2. Optimal Merge Pattern: Repeat (n - 1) times
    for (i = 0; i < n - 1; i++) {
        int min1 = -1, min2 = -1;

        // Pick first smallest unmerged frequency (goes to LEFT child)
        for (j = 0; j < total_nodes; j++) {
            if (tree[j].merged == 0) {
                if (min1 == -1 || tree[j].freq < tree[min1].freq) {
                    min1 = j;
                }
            }
        }
        tree[min1].merged = 1;

        // Pick second smallest unmerged frequency (goes to RIGHT child)
        for (j = 0; j < total_nodes; j++) {
            if (tree[j].merged == 0) {
                if (min2 == -1 || tree[j].freq < tree[min2].freq) {
                    min2 = j;
                }
            }
        }
        tree[min2].merged = 1;

        // 3. Create new internal parent node with combined frequency
        tree[total_nodes].ch = '-';
        tree[total_nodes].freq = tree[min1].freq + tree[min2].freq;
        tree[total_nodes].left = min1;   // Smaller frequency on left (0)
        tree[total_nodes].right = min2;  // Next smallest on right (1)
        tree[total_nodes].merged = 0;

        total_nodes++;
    }

    // 4. Print the final Huffman table starting from the root (total_nodes - 1)
    int code[MAX];
    printf("Char\t| Frequency\t| Huffman Code\n");
    printf("----------------------------------------\n");
    print_codes(total_nodes - 1, code, 0);
}

int main() {
    // Classic lecture example: 5 characters with frequencies
    char chars[] = {'A', 'B', 'C', 'D', 'E'};
    int freqs[] = {3, 5, 6, 4, 2};
    int n = 5;

    huffman_abdul_bari(chars, freqs, n);

    return 0;
}
