#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to check if the graph is bipartite using BFS
bool isBipartite(int startNode, vector<vector<int>>& adjList)
{
    int n = adjList.size();
    vector<int> color(n, -1); // -1 indicates no color, 0 and 1 represent two colors
    queue<int> q;

    color[startNode] = 0; // Assign the first color to the start node
    q.push(startNode);

    while (!q.empty())
    {
        int currentNode = q.front();
        q.pop();

        // Traverse all adjacent nodes
        for (size_t i = 0; i < adjList[currentNode].size(); ++i)
        {
            int neighbor = adjList[currentNode][i];
            if (color[neighbor] == -1) // If the neighbor is not colored
            {
                color[neighbor] = 1 - color[currentNode]; // Assign alternate color
                q.push(neighbor);
            }
            else if (color[neighbor] == color[currentNode]) // If the neighbor has the same color
            {
                return false; // Graph is not bipartite
            }
        }
    }
    return true; // Graph is bipartite
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
        adjList[v].push_back(u); // Add edge v -> u (since the graph is undirected)
    }

    int startNode;
    cout << "Enter the start node for BFS: ";
    cin >> startNode;

    // Check if the graph is bipartite
    if (isBipartite(startNode, adjList))
    {
        cout << "The graph is bipartite." << endl;
    }
    else
    {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}