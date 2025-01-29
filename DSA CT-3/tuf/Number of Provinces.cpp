#include <iostream>   // Include the standard input-output library
#include <vector>     // Include the vector container from the Standard Template Library (STL)
using namespace std;  // Use the standard namespace to avoid prefixing std::

/*
 * Class Solution containing a function to count the number of provinces in an undirected graph.
 */
class Solution {
private:
    /*
     * Depth-First Search (DFS) traversal function.
     * @param node: Current node being visited.
     * @param adjList: Adjacency list representation of the graph.
     * @param visited: Array to track visited nodes.
     */
    void dfs(int node, vector<int> adjList[], vector<int>& visited) {
        visited[node] = 1; // Mark the current node as visited
        
        // Recursively visit all unvisited adjacent nodes
        for (auto neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adjList, visited); 
            }
        }
    }

public:
    /*
     * Function to count the number of provinces (connected components) in the graph.
     * @param adjMatrix: Adjacency matrix representation of the graph.
     * @param V: Number of vertices in the graph.
     * @return Number of provinces (connected components).
     */
    int numProvinces(vector<vector<int>> adjMatrix, int V) {
        vector<int> adjList[V]; // Adjacency list representation of the graph

        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // If there is an edge and it's not a self-loop
                if (adjMatrix[i][j] == 1 && i != j) {
                    adjList[i].push_back(j); // Add edge i → j
                    adjList[j].push_back(i); // Add edge j → i (for undirected graph)
                }
            }
        }

        vector<int> visited(V, 0); // Vector to track visited nodes, initialized to 0
        int provinceCount = 0;     // Variable to count the number of provinces

        // Traverse all nodes
        for (int i = 0; i < V; i++) {
            if (!visited[i]) { // If the node is not visited, it starts a new province
                provinceCount++; // Increment province count
                dfs(i, adjList, visited); // Perform DFS traversal for this component
            }
        }

        return provinceCount; // Return the total number of provinces
    }
};

/*
 * Main function to test the numProvinces function.
 */
int main() {
    // Define an adjacency matrix representing the graph
    vector<vector<int>> adjMatrix{
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    Solution obj; // Create an instance of the Solution class

    // Call the numProvinces function and print the result
    cout << "Number of Provinces: " << obj.numProvinces(adjMatrix, 3) << endl;

    return 0; // Indicate successful execution
}
