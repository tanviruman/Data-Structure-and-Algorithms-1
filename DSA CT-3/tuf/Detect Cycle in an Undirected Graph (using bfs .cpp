#include <iostream>   // Standard input-output library
#include <vector>     // For using the vector container
#include <queue>      // For using the queue container
using namespace std;

class Solution {
  private: 
    /*
     * Function to detect a cycle in an undirected graph using BFS
     * @param src: The starting node for BFS traversal
     * @param adj: The adjacency list representation of the graph
     * @param vis: Array to keep track of visited nodes
     * @return True if a cycle is detected, otherwise False
     */
    bool detectCycleBFS(int src, vector<int> adj[], vector<int>& vis) {
        vis[src] = 1;  // Mark the source node as visited
        queue<pair<int, int>> q; // Queue to store <node, parent>
        q.push({src, -1});  // Push the source node with a dummy parent (-1)

        // Process nodes in the queue
        while (!q.empty()) {
            int node = q.front().first;   // Current node
            int parent = q.front().second; // Parent node
            q.pop();

            // Traverse all adjacent nodes
            for (auto adjacentNode : adj[node]) {
                if (!vis[adjacentNode]) {   // If the neighbor is not visited
                    vis[adjacentNode] = 1;  // Mark as visited
                    q.push({adjacentNode, node}); // Push to queue with the current node as parent
                }
                // If the adjacent node is visited and is not the parent of the current node, cycle detected
                else if (adjacentNode != parent) {
                    return true;  // Cycle found
                }
            }
        }
        return false;  // No cycle detected
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
            if (!vis[i]) {  // If the node is not visited
                if (detectCycleBFS(i, adj, vis)) {  // Call BFS to detect cycle
                    return true;  // Cycle found
                }
            }
        }
        return false;  // No cycle detected in any component
    }
};

int main() {
    int V = 4; // Number of vertices
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}}; // Adjacency list representation of the graph

    Solution obj;
    bool hasCycle = obj.isCycle(V, adj); // Check if the graph contains a cycle

    // Output the result
    if (hasCycle)
        cout << "Cycle Detected\n";
    else
        cout << "No Cycle\n";

    return 0; // Successful program termination
}
