#include <iostream>   // Header for input/output operations
#include <vector>     // Header for using the vector container
#include <queue>      // Header for using the queue container
using namespace std;  // Avoid writing 'std::' before standard functions like cout, cin, etc.

// Function to perform BFS (Breadth-First Search)
void BFS(int startNode, vector<vector<int>>& adjList)
{
    vector<bool> visited(adjList.size(), false); // Vector to keep track of visited nodes, initialized to 'false'
    queue<int> q;                                // Queue to manage the BFS traversal

    visited[startNode] = true;  // Mark the starting node as visited
    q.push(startNode);          // Add the starting node to the queue

    cout << "BFS Traversal: ";
    while (!q.empty())          // Loop until the queue is empty
    {
        int currentNode = q.front(); // Get the front node in the queue
        q.pop();                     // Remove the front node from the queue
        cout << currentNode << " ";  // Print the current node (process it)

        // Traverse all the neighbors of the current node
        for (size_t i = 0; i < adjList[currentNode].size(); ++i)
        {
            int neighbor = adjList[currentNode][i]; // Get the current neighbor
            if (!visited[neighbor])                // Check if the neighbor has not been visited
            {
                visited[neighbor] = true; // Mark the neighbor as visited
                q.push(neighbor);         // Add the neighbor to the queue
            }
        }
    }
    cout << endl; // End of BFS traversal
}

int main()
{
    int nodes, edges; // Variables to store the number of nodes and edges in the graph
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges; // Input the number of nodes and edges

    // Adjacency list representation of the graph
    vector<vector<int>> adjList(nodes); // A vector of vectors to store the adjacency list

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; i++) // Loop to input all the edges
    {
        int u, v; // Variables to store endpoints of the edge
        cin >> u >> v; // Input an edge between nodes u and v
        adjList[u].push_back(v); // Add an edge from u to v
        adjList[v].push_back(u); // Add an edge from v to u (for undirected graphs)
    }

    int startNode; // Variable to store the starting node for BFS
    cout << "Enter the start node for BFS: ";
    cin >> startNode; // Input the starting node

    // Perform BFS traversal from the given start node
    BFS(startNode, adjList);

    return 0; // Indicate successful program execution
}
