#include <stdio.h>

#define MAX_SIZE 100  // Maximum size of the tree

// Array to hold the tree nodes
int tree[MAX_SIZE];

// Function to insert a value in the BST
void insert(int data) {
    int loc = 1; // Start from root, which is index 1

    while (loc < MAX_SIZE) {
        if (tree[loc] == 0) {
            tree[loc] = data;  // Insert data if the position is empty
            return;
        } else if (data < tree[loc]) {
            loc = loc * 2;  // Move to left child
        } else if (data > tree[loc]) {
            loc = loc * 2 + 1;  // Move to right child
        } else {
            printf("Duplicate value %d ignored.\n", data);
            return;
        }
    }
    printf("Tree overflow! Unable to insert %d.\n", data);  // If tree exceeds max size
}

// Function to perform inorder traversal
void inorder(int loc) {
    if (loc >= MAX_SIZE || tree[loc] == 0) return;  // Check if position is valid
    inorder(loc * 2);  // Visit left child
    printf("%d ", tree[loc]);  // Visit current node
    inorder(loc * 2 + 1);  // Visit right child
}

int main() {
    // Initialize the tree with 0 (empty)
    for (int i = 0; i < MAX_SIZE; i++) {
        tree[i] = 0;
    }

    // Example data to insert into the BST
    int data[] = {6, 9, 5, 2, 8,15, 24, 14, 7, 8, 5, 2};
    int n = sizeof(data) / sizeof(data[0]);

    // Insert elements into the tree
    for (int i = 0; i < n; i++) {
        insert(data[i]);
    }

    // Print inorder traversal (sorted order for BST)
    printf("Inorder Traversal: ");
    inorder(1);  // Start from the root at index 1
    printf("\n");

    return 0;
}
