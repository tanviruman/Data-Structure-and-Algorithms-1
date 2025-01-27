#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS
void DFS(int currentNode, const vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[currentNode] = true; // Mark the current node as visited

    // Traverse all adjacent nodes
    for (size_t i = 0; i < adjList[currentNode].size(); ++i) {
        int neighbor = adjList[currentNode][i];
        if (!visited[neighbor]) {
            DFS(neighbor, adjList, visited); // Recursively visit the neighbor
        }
    }
}

int main() {
    int nodes, edges;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges;

    // Adjacency list representation of the graph
    vector<vector<int>> adjList(nodes);

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v); // Add edge u -> v
        adjList[v].push_back(u); // Add edge v -> u (since the graph is undirected)
    }

    // To keep track of visited nodes
    vector<bool> visited(nodes, false);

    int connectedComponents = 0; // Counter for connected components

    // Traverse all nodes to find connected components
    for (int i = 0; i < nodes; ++i) {
        if (!visited[i]) {
            DFS(i, adjList, visited); // Perform DFS for unvisited nodes
            connectedComponents++; // Increment the connected components counter
        }
    }

    // Output the number of connected components
    cout << "Connected Components: " << connectedComponents << endl;

    return 0;
}