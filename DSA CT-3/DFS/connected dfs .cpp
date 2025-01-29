//Use DFS to check if all nodes in an undirected graph are connected.  

#include <iostream>  // Include the input/output library
#include <vector>    // Include the vector library for dynamic arrays
using namespace std; // Use the standard namespace for simpler syntax

// Function to perform Depth-First Search (DFS)
void DFS(int currentNode, const vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[currentNode] = true; // Mark the current node as visited

    // Traverse all adjacent nodes of the current node
    for (size_t i = 0; i < adjList[currentNode].size(); ++i) {
        int neighbor = adjList[currentNode][i]; // Get the neighbor node
        if (!visited[neighbor]) {              // If the neighbor is not visited
            DFS(neighbor, adjList, visited);   // Recursively visit the neighbor
        }
    }
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

    // Perform DFS starting from node 0
    DFS(0, adjList, visited);

    // Check if all nodes are visited to determine if the graph is connected
    bool isConnected = true; // Assume the graph is connected initially
    for (int i = 0; i < nodes; ++i) { // Loop through all nodes
        if (!visited[i]) { // If any node is not visited
            isConnected = false; // The graph is not connected
            break;               // No need to check further
        }
    }

    // Output whether the graph is connected or not
    if (isConnected) {
        cout << "Is Connected: Yes" << endl; // Graph is connected
    } else {
        cout << "Is Connected: No" << endl;  // Graph is not connected
    }

    return 0; // Indicate successful program termination
}
