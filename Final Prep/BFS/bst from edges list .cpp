#include <iostream> // Include the iostream library for input and output operations
#include <vector>   // Include the vector library to use dynamic arrays
#include <queue>    // Include the queue library for BFS traversal
using namespace std; // Use the standard namespace to avoid prefixing std::

/**
 * Function to perform Breadth-First Search (BFS) on the graph
 * @param startNode - The node from where BFS traversal starts
 * @param adjList - The adjacency list representing the graph
 */
void BFS(int startNode, vector<vector<int>>& adjList) {
    vector<bool> visited(adjList.size(), false); // To track whether a node is visited, initialize all to false
    queue<int> q;                                // Queue to facilitate BFS traversal

    visited[startNode] = true;  // Mark the start node as visited
    q.push(startNode);          // Enqueue the start node into the queue

    cout << "BFS: "; // Print the BFS traversal order
    while (!q.empty()) { // Loop until the queue becomes empty
        int currentNode = q.front(); // Get the front element of the queue
        q.pop(); // Dequeue the current node
        cout << currentNode << " "; // Process the current node (print it)

        // Traverse all adjacent nodes of the current node
        for (int neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {      // If the neighbor has not been visited
                visited[neighbor] = true; // Mark the neighbor as visited
                q.push(neighbor);         // Enqueue the neighbor into the queue
            }
        }
    }
    cout << endl; // Print a newline after the BFS traversal
}

int main() {
    int nodes, edges; // Declare variables for the number of nodes and edges
    cout << "Enter the number of nodes and edges: "; // Prompt user for graph size
    cin >> nodes >> edges; // Input the number of nodes and edges

    // Create an adjacency list to represent the graph
    vector<vector<int>> adjList(nodes);

    cout << "Enter all edges (u v):" << endl; // Prompt the user to input edges
    for (int i = 0; i < edges; i++) {
        int u, v; // Variables to store edge endpoints
        cin >> u >> v; // Input the edge between node u and node v
        adjList[u].push_back(v); // Add edge u -> v to the adjacency list
        adjList[v].push_back(u); // Add edge v -> u (since the graph is undirected)
    }

    int startNode; // Variable to store the starting node for BFS
    cout << "Enter the starting node: "; // Prompt the user for the starting node
    cin >> startNode; // Input the starting node

    // Perform BFS traversal starting from the given node
    BFS(startNode, adjList);

    return 0; // Indicate successful program execution
}
