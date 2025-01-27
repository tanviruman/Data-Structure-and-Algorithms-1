#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS
void DFS(int currentNode, const vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[currentNode] = true; // Mark the current node as visited
    cout << currentNode << " "; // Print the current node

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

    int startNode;
    cout << "Enter the start node for DFS: ";
    cin >> startNode;

    // To keep track of visited nodes
    vector<bool> visited(nodes, false);

    // Perform DFS
    cout << "DFS Traversal: ";
    DFS(startNode, adjList, visited);
    cout << endl;

    return 0;
}