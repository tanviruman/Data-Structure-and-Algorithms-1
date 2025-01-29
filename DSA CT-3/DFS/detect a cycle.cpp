
//Use DFS to detect a cycle in a graph. 
#include <iostream>  // Include the input/output library
#include <vector>    // Include the vector library for dynamic arrays
using namespace std; // Use the standard namespace for simpler syntax

// Function to perform DFS and detect cycle
bool DFSCycle(int currentNode, int parent, const vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[currentNode] = true; // Mark the current node as visited

    // Traverse all adjacent nodes of the current node
    for (size_t i = 0; i < adjList[currentNode].size(); ++i) {
        int neighbor = adjList[currentNode][i]; // Get the neighbor node

        if (!visited[neighbor]) { // If the neighbor is not visited
            if (DFSCycle(neighbor, currentNode, adjList, visited)) { // Recursively check for cycles
                return true; // Cycle detected
            }
        } else if (neighbor != parent) { // If the neighbor is visited but is not the parent node
            return true; // Cycle detected
        }
    }
    return false; // No cycle detected
}

int main() {
    int nodes, edges; // Variables to store the number of nodes and edges in the graph
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges; // Input the number of nodes and edges

    // Create an adjacency list representation of the graph
    vector<vector<int>> adjList(nodes); // Initialize the adjacency list with 'nodes' empty vectors

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; i++) { // Loop through each edge
        int u, v;                     // Variables to store the endpoints of an edge
        cin >> u >> v;                // Input the endpoints of the edge
        adjList[u].push_back(v);      // Add an edge from u to v
        adjList[v].push_back(u);      // Add an edge from v to u (since the graph is undirected)
    }

    // Create a vector to keep track of visited nodes, initialized to 'false'
    vector<bool> visited(nodes, false);

    // Variable to check if a cycle is detected in the graph
    bool cycleDetected = false;

    // Loop through all nodes to check for cycles
    for (int i = 0; i < nodes; ++i) {
        if (!visited[i]) { // If the node is not visited
            if (DFSCycle(i, -1, adjList, visited)) { // Perform DFS to detect cycles
                cycleDetected = true; // Mark that a cycle is detected
                break; // No need to check further
            }
        }
    }

    // Output the result
    if (cycleDetected) {
        cout << "Cycle Detected: Yes" << endl; // Output if a cycle is detected
    } else {
        cout << "Cycle Detected: No" << endl;  // Output if no cycle is detected
    }

    return 0; // Indicate successful program termination
}
