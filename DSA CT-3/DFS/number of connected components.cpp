//Use DFS to count the number of connected components in a given undirected graph. 
#include <iostream> // Include the iostream library for input and output operations
#include <vector>   // Include the vector library to use dynamic arrays
using namespace std; // Use the standard namespace to avoid prefixing std::

/**
 * Function to perform Depth First Search (DFS) on the graph
 * @param currentNode - The node currently being visited
 * @param adjList - The adjacency list representing the graph
 * @param visited - A vector to keep track of visited nodes
 */
void DFS(int currentNode, const vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[currentNode] = true; // Mark the current node as visited

    // Traverse all adjacent nodes of the current node
    for (size_t i = 0; i < adjList[currentNode].size(); ++i) {
        int neighbor = adjList[currentNode][i]; // Get the neighbor node
        if (!visited[neighbor]) { // If the neighbor is not visited
            DFS(neighbor, adjList, visited); // Recursively visit the neighbor node
        }
    }
}

int main() {
    int nodes, edges; // Declare variables to store the number of nodes and edges
    cout << "Enter the number of nodes and edges: "; // Prompt the user to enter the graph's size
    cin >> nodes >> edges; // Take input for the number of nodes and edges

    // Create an adjacency list to represent the graph
    vector<vector<int>> adjList(nodes);

    // Prompt the user to input all the edges
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v; // Variables to store the two endpoints of an edge
        cin >> u >> v; // Input an edge between node u and node v
        adjList[u].push_back(v); // Add edge u -> v to the adjacency list
        adjList[v].push_back(u); // Add edge v -> u since the graph is undirected
    }

    // Create a vector to keep track of visited nodes, initialized to false
    vector<bool> visited(nodes, false);

    int connectedComponents = 0; // Counter to track the number of connected components

    // Iterate through all nodes to find connected components
    for (int i = 0; i < nodes; ++i) {
        if (!visited[i]) { // If the node is not visited yet
            DFS(i, adjList, visited); // Perform a DFS starting from this node
            connectedComponents++; // Increment the counter for connected components
        }
    }

    // Output the total number of connected components in the graph
    cout << "Connected Components: " << connectedComponents << endl;

    return 0; // Indicate successful program execution
}
