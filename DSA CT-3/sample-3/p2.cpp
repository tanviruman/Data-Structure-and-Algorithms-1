//Question 2: Finding the k-th Largest Element in a BST
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
        return new TreeNode(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// Reverse in-order traversal to find the k-th largest element
void findKthLargestHelper(TreeNode* root, int& k, int& result) {
    if (root == nullptr || k <= 0) {
        return;
    }

    // Traverse the right subtree first
    findKthLargestHelper(root->right, k, result);

    // Decrement k and check if the current node is the k-th largest
    k--;
    if (k == 0) {
        result = root->data;
        return;
    }

    // Traverse the left subtree
    findKthLargestHelper(root->left, k, result);
}

// Function to find the k-th largest element in the BST
int findKthLargest(TreeNode* root, int k) {
    int result = -1;
    findKthLargestHelper(root, k, result);
    return result;
}

int main() {
    TreeNode* root = nullptr;

    // Insert elements into the BST
    root = insert(root, 8);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);

    // Test findKthLargest()
    cout << "3rd largest element: " << findKthLargest(root, 3) << endl; // Should return 8
    cout << "1st largest element: " << findKthLargest(root, 1) << endl; // Should return 12
    cout << "4th largest element: " << findKthLargest(root, 4) << endl; // Should return 5

    return 0;
}