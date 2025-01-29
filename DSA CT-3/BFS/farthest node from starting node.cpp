#include <iostream>  // Include the input/output library
#include <vector>    // Include the vector library for dynamic arrays
#include <queue>     // Include the queue library for BFS traversal
using namespace std; // Use the standard namespace for simpler syntax

// Function to perform BFS and find the farthest node
int findFarthestNode(int startNode, vector<vector<int>>& adjList) {
    vector<bool> visited(adjList.size(), false); // To keep track of visited nodes
    vector<int> distance(adjList.size(), 0);     // To store the distance from the start node
    queue<int> q;                                // Queue for BFS traversal

    visited[startNode] = true;  // Mark the start node as visited
    q.push(startNode);          // Enqueue the start node

    // Perform BFS traversal
    while (!q.empty()) {
        int currentNode = q.front(); // Get the front node in the queue
        q.pop();                     // Dequeue the current node

        // Traverse all adjacent nodes of the current node
        for (size_t i = 0; i < adjList[currentNode].size(); ++i) {
            int neighbor = adjList[currentNode][i]; // Get the neighbor node
            if (!visited[neighbor]) {              // If the neighbor is not visited
                visited[neighbor] = true;          // Mark the neighbor as visited
                distance[neighbor] = distance[currentNode] + 1; // Update the distance of the neighbor
                q.push(neighbor);                  // Enqueue the neighbor
            }
        }
    }

    // Find the node with the maximum distance
    int farthestNode = startNode; // Initialize the farthest node as the start node
    for (size_t i = 0; i < distance.size(); ++i) { // Loop through all nodes
        if (distance[i] > distance[farthestNode]) { // If a node has a greater distance
            farthestNode = i; // Update the farthest node
        }
    }

    return farthestNode; // Return the farthest node
}

int main() {
    int nodes, edges; // Variables to store the number of nodes and edges in the graph
    cout << "Enter the number of nodes: ";
    cin >> nodes; // Input the number of nodes

    // Adjacency list representation of the graph
    vector<vector<int>> adjList(nodes); // Initialize the adjacency list with 'nodes' empty vectors

    cout << "Enter the number of edges: ";
    cin >> edges; // Input the number of edges

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; i++) { // Loop through each edge
        int u, v;                     // Variables to store the endpoints of an edge
        cin >> u >> v;                // Input the endpoints of the edge
        adjList[u].push_back(v);      // Add an edge from u to v
        adjList[v].push_back(u);      // Add an edge from v to u (since the graph is undirected)
    }

    int startNode; // Variable to store the starting node
    cout << "Enter the start node: ";
    cin >> startNode; // Input the starting node

    // Find the farthest node from the start node
    int farthestNode = findFarthestNode(startNode, adjList);
    cout << "Farthest node from node " << startNode << " is: " << farthestNode << endl;

    return 0; // Indicate successful program termination
}
