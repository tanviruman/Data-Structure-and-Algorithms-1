#include <iostream> // Include the iostream library for input and output operations
#include <vector>   // Include the vector library to use dynamic arrays
#include <queue>    // Include the queue library for BFS traversal
using namespace std; // Use the standard namespace to avoid prefixing std::

/**
 * Function to check if the graph is bipartite using Breadth-First Search (BFS)
 * @param startNode - The node to start BFS traversal
 * @param adjList - The adjacency list representation of the graph
 * @return - Returns true if the graph is bipartite, false otherwise
 */
bool isBipartite(int startNode, vector<vector<int>>& adjList)
{
    int n = adjList.size();           // Get the number of nodes in the graph
    vector<int> color(n, -1);         // Initialize a color array (-1 = uncolored, 0 and 1 represent two colors)
    queue<int> q;                     // Queue to facilitate BFS traversal

    color[startNode] = 0;             // Assign the first color (0) to the start node
    q.push(startNode);                // Enqueue the start node

    while (!q.empty())                // Continue BFS while the queue is not empty
    {
        int currentNode = q.front();  // Get the front node of the queue
        q.pop();                      // Dequeue the current node

        // Traverse all adjacent nodes of the current node
        for (size_t i = 0; i < adjList[currentNode].size(); ++i)
        {
            int neighbor = adjList[currentNode][i]; // Get the neighbor node
            if (color[neighbor] == -1)             // If the neighbor is not colored
            {
                color[neighbor] = 1 - color[currentNode]; // Assign it the opposite color
                q.push(neighbor);                        // Enqueue the neighbor node
            }
            else if (color[neighbor] == color[currentNode]) // If the neighbor has the same color
            {
                return false; // Graph is not bipartite
            }
        }
    }
    return true; // If all nodes are successfully colored, the graph is bipartite
}

int main()
{
    int nodes, edges; // Variables for the number of nodes and edges in the graph
    cout << "Enter the number of nodes and edges: "; // Prompt user to input graph size
    cin >> nodes >> edges; // Read the number of nodes and edges

    // Create an adjacency list to represent the graph
    vector<vector<int>> adjList(nodes);

    // Input all edges of the graph
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v; // Variables for edge endpoints
        cin >> u >> v; // Input edge between node u and node v
        adjList[u].push_back(v); // Add edge u -> v to the adjacency list
        adjList[v].push_back(u); // Add edge v -> u (since the graph is undirected)
    }

    int startNode; // Variable to store the starting node for BFS
    cout << "Enter the start node for BFS: "; // Prompt user to input the start node
    cin >> startNode; // Read the starting node

    // Check if the graph is bipartite
    if (isBipartite(startNode, adjList))
    {
        cout << "The graph is bipartite." << endl; // Output if the graph is bipartite
    }
    else
    {
        cout << "The graph is not bipartite." << endl; // Output if the graph is not bipartite
    }

    return 0; // Indicate successful program execution
}
