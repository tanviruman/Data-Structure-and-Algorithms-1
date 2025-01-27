#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform BFS
void BFS(int startNode, vector<vector<int>>& adjMatrix) {
    int nodes = adjMatrix.size();          // Get the number of nodes from the adjacency matrix
    vector<bool> visited(nodes, false);   // To keep track of visited nodes
    queue<int> q;                         // Queue to manage BFS traversal

    visited[startNode] = true;            // Mark the start node as visited
    q.push(startNode);                    // Enqueue the start node

    cout << "BFS: ";
    while (!q.empty()) {
        int currentNode = q.front();      // Get the node at the front of the queue
        q.pop();                          // Remove it from the queue
        cout << currentNode << " ";       // Process (print) the current node

        // Traverse all neighbors of the current node
        for (int i = 0; i < nodes; i++) {
            // Check if there is an edge and the neighbor is not visited
            if (adjMatrix[currentNode][i] == 1 && !visited[i]) {
                visited[i] = true;        // Mark the neighbor as visited
                q.push(i);                // Enqueue the neighbor
            }
        }
    }
    cout << endl;                         // End the output after traversal
}

int main() {
    int nodes, edges;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges;

    // Initialize the adjacency matrix with zeros
    vector<vector<int>> adjMatrix(nodes, vector<int>(nodes, 0));

    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            cin >> adjMatrix[i][j];       // Read adjacency matrix input
        }
    }

    int startNode;
    cout << "Enter starting node: ";
    cin >> startNode;

    // Perform BFS traversal
    BFS(startNode, adjMatrix);

    return 0;
}
