#include <iostream> // Include the standard input-output library
#include <vector>   // Include the vector container from the Standard Template Library (STL)
using namespace std; // Use the standard namespace to avoid prefixing std::

/*
 * Function to perform Depth-First Search (DFS)
 * @param currentNode: The current node being visited
 * @param adjList: Adjacency list representation of the graph
 * @param visited: Vector to track visited nodes
 */
void DFS(int currentNode, const vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[currentNode] = true; // Mark the current node as visited
    cout << currentNode << " ";  // Process (print) the current node

    // Traverse all nodes adjacent to the current node
    for (size_t i = 0; i < adjList[currentNode].size(); ++i) {
        int neighbor = adjList[currentNode][i]; // Get the adjacent node
        if (!visited[neighbor]) {              // Check if the neighbor is not visited
            DFS(neighbor, adjList, visited);   // Recursively perform DFS on the neighbor
        }
    }
}

int main() {
    int nodes, edges; // Variables to store the number of nodes and edges
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges; // Take input for the number of nodes and edges

    // Create an adjacency list to represent the graph
    vector<vector<int>> adjList(nodes);

    cout << "Enter the edges (u v):" << endl;
    // Input all edges of the graph
    for (int i = 0; i < edges; i++) {
        int u, v; // Variables to store the two endpoints of an edge
        cin >> u >> v;          // Input the endpoints of the edge
        adjList[u].push_back(v); // Add edge u -> v
        adjList[v].push_back(u); // Add edge v -> u (for undirected graph)
    }

    int startNode; // Variable to store the starting node for DFS
    cout << "Enter the start node for DFS: ";
    cin >> startNode; // Input the starting node

    // Create a vector to track visited nodes, initialized to `false`
    vector<bool> visited(nodes, false);

    // Perform DFS starting from the specified node
    cout << "DFS Traversal: ";
    DFS(startNode, adjList, visited); // Call the DFS function
    cout << endl; // Print a new line after DFS traversal is complete

    return 0; // Exit the program
}
s