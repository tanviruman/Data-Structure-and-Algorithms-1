#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS
void DFS(int currentNode, const vector<vector<int>>& adjMatrix, vector<bool>& visited, int nodes) {
    visited[currentNode] = true; // Mark the current node as visited
    cout << currentNode << " "; // Print the current node

    // Traverse all nodes to find neighbors
    for (int i = 0; i < nodes; ++i) {
        if (adjMatrix[currentNode][i] == 1 && !visited[i]) {
            DFS(i, adjMatrix, visited, nodes); // Recursively visit the neighbor
        }
    }
}

int main() {
    int nodes;
    cout << "Enter the number of nodes: ";
    cin >> nodes;

    // Adjacency matrix representation of the graph
    vector<vector<int>> adjMatrix(nodes, vector<int>(nodes));

    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            cin >> adjMatrix[i][j]; // Read the adjacency matrix
        }
    }

    int startNode;
    cout << "Enter the start node for DFS: ";
    cin >> startNode;

    // To keep track of visited nodes
    vector<bool> visited(nodes, false);

    // Perform DFS
    cout << "DFS Traversal: ";
    DFS(startNode, adjMatrix, visited, nodes);
    cout << endl;

    return 0;
}