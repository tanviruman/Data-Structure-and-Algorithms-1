
//Implement DFS to print the traversal of an undirected graph starting from a given starting node from adjacency matrix. 
#include <iostream> // Include the standard input/output library
#include <vector>   // Include the vector library for dynamic arrays
using namespace std; // Use the standard namespace to simplify syntax

// Function to perform Depth-First Search (DFS)
void DFS(int currentNode, const vector<vector<int>>& adjMatrix, vector<bool>& visited, int nodes) {
    visited[currentNode] = true; // Mark the current node as visited
    cout << currentNode << " "; // Print the current node to display the traversal

    // Traverse all nodes to find neighbors of the current node
    for (int i = 0; i < nodes; ++i) {
        if (adjMatrix[currentNode][i] == 1 && !visited[i]) { // Check if there's an edge and the neighbor is not visited
            DFS(i, adjMatrix, visited, nodes); // Recursively visit the neighbor
        }
    }
}

int main() {
    int nodes; // Variable to store the number of nodes in the graph
    cout << "Enter the number of nodes: ";
    cin >> nodes; // Input the number of nodes

    // Create an adjacency matrix to represent the graph
    vector<vector<int>> adjMatrix(nodes, vector<int>(nodes)); // Initialize a 2D vector of size `nodes x nodes`

    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < nodes; i++) { // Loop through each row
        for (int j = 0; j < nodes; j++) { // Loop through each column
            cin >> adjMatrix[i][j]; // Input the value for the adjacency matrix
        }
    }

    int startNode; // Variable to store the starting node for the DFS
    cout << "Enter the start node for DFS: ";
    cin >> startNode; // Input the starting node

    // Create a vector to track visited nodes, initialized to `false`
    vector<bool> visited(nodes, false);

    // Perform DFS starting from the given node
    cout << "DFS Traversal: ";
    DFS(startNode, adjMatrix, visited, nodes); // Call the DFS function
    cout << endl; // Print a newline at the end of the traversal

    return 0; // Indicate that the program executed successfully
}
