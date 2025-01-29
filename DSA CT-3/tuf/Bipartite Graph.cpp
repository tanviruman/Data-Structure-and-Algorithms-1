#include <bits/stdc++.h> // Include all standard libraries
using namespace std;     // Use the standard namespace to avoid prefixing std::

class Solution {
private:
    /*
     * Helper function to perform DFS and check bipartiteness
     * @param node: The current node being processed
     * @param col: The color to assign to the current node (0 or 1)
     * @param color: Array to store the color of each node
     * @param adj: Adjacency list representation of the graph
     * @return: True if the graph is bipartite, False otherwise
     */
    bool dfs(int node, int col, int color[], vector<int> adj[]) {
        color[node] = col; // Assign the current color to the node

        // Traverse all adjacent nodes
        for (auto it : adj[node]) {
            // If the adjacent node is uncolored
            if (color[it] == -1) {
                // Recursively call DFS with the opposite color
                if (dfs(it, !col, color, adj) == false) {
                    return false; // If any subgraph is not bipartite, return false
                }
            }
            // If the adjacent node is already colored and has the same color
            else if (color[it] == col) {
                return false; // The graph is not bipartite
            }
        }

        return true; // The graph is bipartite
    }

public:
    /*
     * Function to check if a graph is bipartite
     * @param V: Number of vertices in the graph
     * @param adj: Adjacency list representation of the graph
     * @return: True if the graph is bipartite, False otherwise
     */
    bool isBipartite(int V, vector<int> adj[]) {
        int color[V]; // Array to store the color of each node
        for (int i = 0; i < V; i++) {
            color[i] = -1; // Initialize all nodes as uncolored
        }

        // Check all connected components of the graph
        for (int i = 0; i < V; i++) {
            // If the node is uncolored, start DFS from it
            if (color[i] == -1) {
                if (dfs(i, 0, color, adj) == false) {
                    return false; // If any component is not bipartite, return false
                }
            }
        }

        return true; // The graph is bipartite
    }
};

/*
 * Function to add an undirected edge to the adjacency list
 * @param adj: Adjacency list representation of the graph
 * @param u: First endpoint of the edge
 * @param v: Second endpoint of the edge
 */
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v); // Add edge from u to v
    adj[v].push_back(u); // Add edge from v to u (since the graph is undirected)
}

int main() {
    // Number of vertices (V) = 4
    vector<int> adj[4]; // Adjacency list for the graph

    // Add edges to the graph
    addEdge(adj, 0, 2); // Edge between node 0 and node 2
    addEdge(adj, 0, 3); // Edge between node 0 and node 3
    addEdge(adj, 2, 3); // Edge between node 2 and node 3
    addEdge(adj, 3, 1); // Edge between node 3 and node 1

    Solution obj; // Create an object of the Solution class
    bool ans = obj.isBipartite(4, adj); // Check if the graph is bipartite

    // Output the result
    if (ans) {
        cout << "1\n"; // The graph is bipartite
    } else {
        cout << "0\n"; // The graph is not bipartite
    }

    return 0; // Indicate successful program execution
}