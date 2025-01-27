#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform BFS and find the farthest node
int findFarthestNode(int startNode, vector<vector<int>>& adjList)
{
    vector<bool> visited(adjList.size(), false); // To keep track of visited nodes
    vector<int> distance(adjList.size(), 0);     // To store the distance from the start node
    queue<int> q;                                // Queue for BFS traversal

    visited[startNode] = true;  // Mark the start node as visited
    q.push(startNode);          // Enqueue the start node

    while (!q.empty())
    {
        int currentNode = q.front();
        q.pop(); // Dequeue the current node

        // Traverse all adjacent nodes
        for (size_t i = 0; i < adjList[currentNode].size(); ++i)
        {
            int neighbor = adjList[currentNode][i];
            if (!visited[neighbor])
            {
                visited[neighbor] = true; // Mark the neighbor as visited
                distance[neighbor] = distance[currentNode] + 1; // Update the distance
                q.push(neighbor);         // Enqueue the neighbor
            }
        }
    }

    // Find the node with the maximum distance
    int farthestNode = startNode;
    for (size_t i = 0; i < distance.size(); ++i)
    {
        if (distance[i] > distance[farthestNode])
        {
            farthestNode = i;
        }
    }

    return farthestNode;
}

int main()
{
    int nodes, edges;
    cout << "Enter the number of nodes: ";
    cin >> nodes;

    // Adjacency list representation of the graph
    vector<vector<int>> adjList(nodes);

    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v); // Add edge u -> v
        adjList[v].push_back(u); // Add edge v -> u (since the graph is undirected)
    }

    int startNode;
    cout << "Enter the start node: ";
    cin >> startNode;

    // Find the farthest node
    int farthestNode = findFarthestNode(startNode, adjList);
    cout << "Farthest node from node " << startNode << " is: " << farthestNode << endl;

    return 0;
}