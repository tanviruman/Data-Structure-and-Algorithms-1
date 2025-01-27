#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS and detect cycle
bool DFSCycle(int currentNode, int parent, const vector<vector<int>>& adjList, vector<bool>& visited) {
    visited[currentNode] = true; // Mark the current node as visited

    // Traverse all adjacent nodes
    for (size_t i = 0; i < adjList[currentNode].size(); ++i) {
        int neighbor = adjList[currentNode][i];
        if (!visited[neighbor]) {
            if (DFSCycle(neighbor, currentNode, adjList, visited)) {
                return true; // Cycle detected
            }
        } else if (neighbor != parent) {
            return true; // Cycle detected
        }
    }
    return false; // No cycle detected
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

    // Check for cycle in the graph
    bool cycleDetected = false;
    for (int i = 0; i < nodes; ++i) {
        if (!visited[i]) {
            if (DFSCycle(i, -1, adjList, visited)) {
                cycleDetected = true;
                break;
            }
        }
    }

    // Output the result
    if (cycleDetected) {
        cout << "Cycle Detected: Yes" << endl;
    } else {
        cout << "Cycle Detected: No" << endl;
    }

    return 0;
}