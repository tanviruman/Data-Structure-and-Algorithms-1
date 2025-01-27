#include <iostream> // Includes the standard input/output stream library
using namespace std; // Allows us to use standard library objects without prefixing 'std::'

// Structure definition for a TreeNode
struct TreeNode {
    int key; // Key or value of the node
    TreeNode* parent; // Pointer to the parent node
    TreeNode* left; // Pointer to the left child
    TreeNode* right; // Pointer to the right child
};

// Global pointer to the root of the binary search tree (BST)
TreeNode* root = NULL;

// Function to create a new node
TreeNode* createNode(int value) {
    TreeNode* newNode = new TreeNode(); // Dynamically allocate memory for the new node
    newNode->key = value; // Assign the value to the key
    newNode->parent = NULL; // Initialize parent pointer to NULL
    newNode->left = NULL; // Initialize left child pointer to NULL
    newNode->right = NULL; // Initialize right child pointer to NULL
    return newNode; // Return the created node
}

// Function to insert a value into the BST
void insertInBST(int value) {
    TreeNode* z = createNode(value); // Create a new node with the given value
    TreeNode* y = NULL; // Temporary pointer to track the parent during insertion
    TreeNode* x = root; // Start traversing from the root

    while (x != NULL) { // Traverse the tree until a leaf node is found
        y = x; // Update the parent node
        if (z->key < x->key) { // If the value is less, go to the left subtree
            x = x->left;
        } else { // If the value is greater or equal, go to the right subtree
            x = x->right;
        }
    }

    z->parent = y; // Set the parent of the new node
    if (y == NULL) { // If the tree is empty, make the new node the root
        root = z;
    } else if (z->key < y->key) { // If the value is less than the parent, insert as the left child
        y->left = z;
    } else { // Otherwise, insert as the right child
        y->right = z;
    }
}

// Function for pre-order traversal (root, left, right)
void preOrder(TreeNode* ptr) {
    if (ptr == NULL) return; // Base case: if node is NULL, return
    cout << ptr->key << " "; // Visit the root node and print its key
    preOrder(ptr->left); // Recurse on the left subtree
    preOrder(ptr->right); // Recurse on the right subtree
}

// Function for in-order traversal (left, root, right)
void inOrder(TreeNode* ptr) {
    if (ptr == NULL) return; // Base case: if node is NULL, return
    inOrder(ptr->left); // Recurse on the left subtree
    cout << ptr->key << " "; // Visit the root node and print its key
    inOrder(ptr->right); // Recurse on the right subtree
}

// Function for post-order traversal (left, right, root)
void postOrder(TreeNode* ptr) {
    if (ptr == NULL) return; // Base case: if node is NULL, return
    postOrder(ptr->left); // Recurse on the left subtree
    postOrder(ptr->right); // Recurse on the right subtree
    cout << ptr->key << " "; // Visit the root node and print its key
}

// Function to find the minimum value in a subtree
TreeNode* minimum(TreeNode* x) {
    if (x == NULL) return NULL; // If the node is NULL, return NULL
    while (x->left != NULL) { // Traverse to the leftmost node
        x = x->left;
    }
    return x; // Return the leftmost node
}

// Function to find the maximum value in a subtree
TreeNode* maximum(TreeNode* x) {
    if (x == NULL) return NULL; // If the node is NULL, return NULL
    while (x->right != NULL) { // Traverse to the rightmost node
        x = x->right;
    }
    return x; // Return the rightmost node
}

// Function to find the K-th smallest element in the BST
TreeNode* findKthSmallest(TreeNode* node, int& k) {
    if (node == NULL) return NULL; // Base case: if node is NULL, return NULL

    TreeNode* left = findKthSmallest(node->left, k); // Search in the left subtree
    if (left != NULL) return left; // If found in the left subtree, return it

    k--; // Decrement K since we are visiting the current node
    if (k == 0) return node; // If K reaches 0, the current node is the K-th smallest

    return findKthSmallest(node->right, k); // Search in the right subtree
}

// Function to display the minimum and maximum values in the BST
void displayMinMax() {
    TreeNode* maxNode = maximum(root); // Find the maximum value
    TreeNode* minNode = minimum(root); // Find the minimum value
    if (maxNode) cout << "Maximum value: " << maxNode->key << endl; // Print the maximum value
    if (minNode) cout << "Minimum value: " << minNode->key << endl; // Print the minimum value
}

// Main function
int main() {
    int n, value, k; // Declare variables for the number of nodes, node value, and K

    cout << "Enter the number of nodes to insert: "; // Prompt user for the number of nodes
    cin >> n; // Input the number of nodes

    for (int i = 0; i < n; ++i) { // Loop to insert 'n' nodes
        cout << "Enter value for node " << i + 1 << ": "; // Prompt user for the node value
        cin >> value; // Input the node value
        insertInBST(value); // Insert the value into the BST
    }

    cout << "\nPre-order traversal: "; // Print pre-order traversal
    preOrder(root); // Perform pre-order traversal
    cout << endl;

    cout << "In-order traversal: "; // Print in-order traversal
    inOrder(root); // Perform in-order traversal
    cout << endl;

    cout << "Post-order traversal: "; // Print post-order traversal
    postOrder(root); // Perform post-order traversal
    cout << endl;

    displayMinMax(); // Display the minimum and maximum values in the BST

    cout << "\nEnter the value of K to find the K-th smallest node: "; // Prompt user for K
    cin >> k; // Input the value of K

    TreeNode* kthNode = findKthSmallest(root, k); // Find the K-th smallest node
    if (kthNode != NULL) { // If K-th smallest node exists
        cout << "The K-th smallest node value is: " << kthNode->key << endl; // Print the value
    } else { // If K is invalid
        cout << "The value of K is invalid!" << endl; // Print error message
    }

    return 0; // Return 0 to indicate successful program execution
}
