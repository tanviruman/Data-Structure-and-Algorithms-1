#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to find the shortest path using BFS
void findShortestPath(int startNode, int targetNode, vector<vector<int>>& adjList)
{
    int n = adjList.size(); // Number of nodes
    vector<bool> visited(n, false); // To keep track of visited nodes
    vector<int> parent(n, -1);      // To store the parent of each node in the path
    queue<int> q;                   // Queue for BFS traversal

    visited[startNode] = true; // Mark the start node as visited
    q.push(startNode);         // Enqueue the start node

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
            if (!visited[neighbor])
            {
                visited[neighbor] = true;  // Mark the neighbor as visited
                parent[neighbor] = currentNode; // Store the parent of the neighbor
                q.push(neighbor);          // Enqueue the neighbor
            }
        }
    }

    // Reconstruct the shortest path from startNode to targetNode
    vector<int> path;
    for (int at = targetNode; at != -1; at = parent[at])
        path.push_back(at);
    reverse(path.begin(), path.end()); // Reverse the path to get the correct order

    // Print the shortest path
    if (path[0] == startNode)
    {
        cout << "Shortest Path: ";
        for (int i = 0; i < path.size(); i++)
        {
            if (i > 0)
                cout << " -> ";
            cout << path[i];
        }
        cout << endl;
    }
    else
    {
        cout << "No path exists between " << startNode << " and " << targetNode << endl;
    }
}

int main()
{
    int nodes, edges;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges;

    // Adjacency list representation of the graph
    vector<vector<int>> adjList(nodes);

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v); // Add edge u -> v
        adjList[v].push_back(u); // Add edge v -> u (undirected graph)
    }

    int startNode, targetNode;
    cout << "Enter the starting node: ";
    cin >> startNode;
    cout << "Enter the targeted node: ";
    cin >> targetNode;

    // Find the shortest path using BFS
    findShortestPath(startNode, targetNode, adjList);

    return 0;
}
