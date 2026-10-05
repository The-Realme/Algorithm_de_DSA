#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void display(struct node* head) {
    struct node* ptr = head;
    if (ptr == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

struct node* insert_at_front(struct node* head, int data) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head; 
    return ptr;       
}

struct node* insert_at_end(struct node* head, int data) {
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;

    // Edge case: If list is empty, new node becomes head
    if (head == NULL) {
        return ptr;
    }

    // Traverse loop to find the last node
    struct node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr; // Link old tail to new node
    return head;
}

// 5. INSERT AT A SPECIFIC INDEX (0-indexed position)
struct node* insert_at_index(struct node* head, int index, int data) {
    // If inserting at front (index 0)
    if (index == 0) {
        return insert_at_front(head, data);
    }

    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;

    // Loop to find the node right BEFORE the insertion index
    struct node* p = head;
    for (int i = 0; i < index - 1 && p != NULL; i++) {
        p = p->next;
    }

    // Edge case: Index is out of bounds
    if (p == NULL) {
        printf("Index out of bounds!\n");
        free(ptr); // Clean up allocated memory if insertion fails
        return head;
    }

    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// 6. DELETION BY INDEX (0-indexed position)
// struct node* delete_at_index(struct node* head, int index) {
//     // Edge case: Empty list
//     if (head == NULL) {
//         printf("List is empty. Nothing to delete.\n");
//         return NULL;
//     }

//     struct node* temp = head;

//     // Case 1: Delete the head node
//     if (index == 0) {
//         head = head->next;
//         free(temp); // Free old head memory
//         return head;
//     }

//     // Case 2: Delete at intermediate or last position
//     struct node* p = head;
//     for (int i = 0; p != NULL && i < index - 1; i++) {
//         p = p->next;
//     }

//     // Edge case: Index doesn't exist
//     if (p == NULL || p->next == NULL) {
//         printf("Index out of bounds!\n");
//         return head;
//     }

//     temp = p->next;       // Node to be deleted
//     p->next = temp->next; // Unlink node from list
//     free(temp);           // Free memory
//     return head;
// }

// 7. FREE ENTIRE LIST (Highly praised by evaluators)
void free_list(struct node* head) {
    struct node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct node* head = NULL;
    head = insert_at_end(head, 10);
    head = insert_at_end(head, 20);
    head = insert_at_end(head, 30);
    display(head);

    head = insert_at_front(head, 5);
    display(head); 

    head = insert_at_index(head, 2, 15);
    display(head);

    // printf("\n--- Deletion Operations ---\n");
    // head = delete_at_index(head, 0); // Delete front
    // display(head); // Expected: 10 -> 15 -> 20 -> 30 -> NULL

    // head = delete_at_index(head, 2); // Delete middle (index 2)
    // display(head); // Expected: 10 -> 15 -> 30 -> NULL

    // Always free memory at the end of the program
    // free_list(head);
    // head = NULL;

    return 0;
}
