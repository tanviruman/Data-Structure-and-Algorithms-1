#include <iostream> // Include the iostream library for input and output operations
#include <vector>   // Include the vector library to use dynamic arrays
#include <queue>    // Include the queue library for BFS traversal
using namespace std; // Use the standard namespace to simplify code

/**
 * Function to find the shortest path between two nodes using Breadth-First Search (BFS)
 * @param startNode - The starting node
 * @param targetNode - The target node
 * @param adjList - The adjacency list representation of the graph
 */
void findShortestPath(int startNode, int targetNode, vector<vector<int>>& adjList)
{
    int n = adjList.size();          // Get the number of nodes in the graph
    vector<bool> visited(n, false);  // Keep track of visited nodes, initialize all as unvisited
    vector<int> parent(n, -1);       // To store the parent of each node in the BFS tree
    queue<int> q;                    // Queue for BFS traversal

    visited[startNode] = true;       // Mark the start node as visited
    q.push(startNode);               // Enqueue the start node

    // BFS loop
    while (!q.empty())
    {
        int currentNode = q.front(); // Get the front node of the queue
        q.pop();                     // Dequeue the current node

        // If we reach the target node, stop the search
        if (currentNode == targetNode)
            break;

        // Traverse all adjacent nodes
        for (int neighbor : adjList[currentNode])
        {
            if (!visited[neighbor]) // If the neighbor is not visited
            {
                visited[neighbor] = true;        // Mark the neighbor as visited
                parent[neighbor] = currentNode; // Record the parent node for backtracking the path
                q.push(neighbor);               // Enqueue the neighbor node
            }
        }
    }

    // Reconstruct the shortest path from startNode to targetNode
    vector<int> path;
    for (int at = targetNode; at != -1; at = parent[at]) // Traverse backward using the parent array
        path.push_back(at);                              // Add each node to the path
    reverse(path.begin(), path.end());                  // Reverse the path to get the correct order

    // Print the shortest path
    if (path[0] == startNode) // Check if the path starts from the startNode
    {
        cout << "Shortest Path: ";
        for (int i = 0; i < path.size(); i++)
        {
            if (i > 0)
                cout << " -> "; // Add an arrow between nodes
            cout << path[i];    // Print the current node
        }
        cout << endl;
    }
    else
    {
        // If the first node in the reconstructed path is not the startNode, no path exists
        cout << "No path exists between " << startNode << " and " << targetNode << endl;
    }
}

int main()
{
    int nodes, edges; // Variables for the number of nodes and edges
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges; // Read the number of nodes and edges

    // Adjacency list representation of the graph
    vector<vector<int>> adjList(nodes);

    // Input the edges of the graph
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v;           // Edge endpoints
        cin >> u >> v;      // Read an edge between node u and node v
        adjList[u].push_back(v); // Add edge u -> v
        adjList[v].push_back(u); // Add edge v -> u (for an undirected graph)
    }

    int startNode, targetNode; // Variables for the start and target nodes
    cout << "Enter the starting node: ";
    cin >> startNode; // Read the starting node
    cout << "Enter the targeted node: ";
    cin >> targetNode; // Read the target node

    // Find the shortest path using BFS
    findShortestPath(startNode, targetNode, adjList);

    return 0; // Indicate successful program execution
}
