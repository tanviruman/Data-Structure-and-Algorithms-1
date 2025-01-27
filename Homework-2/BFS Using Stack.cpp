#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void BFS(int start_node, const vector<vector<int>>& adjList)

{
    vector<bool> visited(adjList.size(), false);
    stack<int> s;

    s.push(start_node);
    visited[start_node] = true;

    cout << "BFS Traversal: ";


    while (!s.empty())


        {
        int current_node = s.top();
        s.pop();
        cout << current_node << " ";

        for (int neighbor : adjList[current_node])



        {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                s.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main()

{
    int nodes, edges;
    cout << "Enter the number of nodes and edges: ";
    cin >> nodes >> edges;

    vector<vector<int>> adjList(nodes);

    cout << "Enter the edges (u v):" << endl;


    for (int i = 0; i < edges; i++)


        {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int start_node;
    cout << "Enter the start node for BFS: ";
    cin >> start_node;

    BFS(start_node, adjList);

    return 0;
}
