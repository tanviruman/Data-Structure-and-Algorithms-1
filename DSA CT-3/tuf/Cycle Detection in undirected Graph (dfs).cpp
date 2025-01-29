#include <iostream>   // Standard input-output library
#include <vector>     // For using the vector container
using namespace std;

class Solution {
  private: 
    /*
     * Function to detect a cycle in an undirected graph using DFS
     * @param node: The current node being visited
     * @param parent: The parent node of the current node
     * @param vis: Array to track visited nodes
     * @param adj: Adjacency list representation of the graph
     * @return True if a cycle is detected, otherwise False
     */
    bool detectCycleDFS(int node, int parent, vector<int>& vis, vector<int> adj[]) {
        vis[node] = 1; // Mark the current node as visited
        
        // Traverse all adjacent nodes
        for (auto adjacentNode : adj[node]) {
            // If the adjacent node is not visited, perform DFS
            if (!vis[adjacentNode]) {
                if (detectCycleDFS(adjacentNode, node, vis, adj)) 
                    return true; // Cycle detected
            }
            // If the adjacent node is visited and is not the parent, a cycle exists
            else if (adjacentNode != parent) {
                return true;
            }
        }
        return false; // No cycle found
    }

  public:
    /*
     * Function to check if there is a cycle in an undirected graph
     * @param V: Number of vertices
     * @param adj: Adjacency list representation of the graph
     * @return True if a cycle exists, otherwise False
     */
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0); // Visited array initialized to 0 (unvisited)

        // Traverse all components of the graph
        for (int i = 0; i < V; i++) {
            if (!vis[i]) { // If the node is not visited
                if (detectCycleDFS(i, -1, vis, adj)) { // Call DFS to detect cycle
                    return true; // Cycle found
                }
            }
        }
        return false; // No cycle detected
    }
};

int main() {
    int V = 4; // Number of vertices
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}}; // Adjacency list representation

    Solution obj;
    bool hasCycle = obj.isCycle(V, adj); // Check if the graph contains a cycle

    // Output the result
    if (hasCycle)
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0; // Successful program termination
}
