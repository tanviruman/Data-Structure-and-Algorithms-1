//Problem 2: Printing Leaf Nodes of a Binary Search Tree (BST)
#include <iostream>
using namespace std;

// Define the structure of a tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    // Constructor to initialize a node
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert a node into the BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val); // Create a new node if the tree is empty
    }
    if (val < root->data) {
        root->left = insert(root->left, val); // Insert into the left subtree
    } else {
        root->right = insert(root->right, val); // Insert into the right subtree
    }
    return root;
}

// Function to print leaf nodes of the BST
void printLeafNodes(TreeNode* root) {
    if (root == nullptr) {
        return; // Base case: if the tree is empty, return
    }
    if (root->left == nullptr && root->right == nullptr) {
        cout << root->data << " "; // Print the node if it is a leaf node
    }
    printLeafNodes(root->left);  // Recursively check the left subtree
    printLeafNodes(root->right); // Recursively check the right subtree
}

int main() {
    TreeNode* root = nullptr; // Initialize the root of the tree as null

    // Insert elements into the BST
    root = insert(root, 18);
    root = insert(root, 9);
    root = insert(root, 30);
    root = insert(root, 25);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 48);
    root = insert(root, 40);

    // Print the leaf nodes
    cout << "Leaf nodes: ";
    printLeafNodes(root);
    cout << endl;

    return 0;
}