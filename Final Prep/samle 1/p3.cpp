//Problem 3: Finding the Path in a Graph
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find the path using Depth-First Search (DFS)
bool findPath(unordered_map<string, vector<string>>& graph, string start, string end, vector<string>& path) {
    path.push_back(start); // Add the current node to the path

    if (start == end) {
        return true; // If we reach the destination, return true
    }

    // Traverse all neighbors of the current node
    for (string neighbor : graph[start]) {
        if (findPath(graph, neighbor, end, path)) {
            return true; // If a path is found, return true
        }
    }

    path.pop_back(); // Remove the current node if no path is found
    return false;
}

int main() {
    // Define the graph as an adjacency list
    unordered_map<string, vector<string>> graph = {
        {"Badda", {"Mouchak"}},
        {"Mouchak", {"Mailbagh"}},
        {"Mailbagh", {"Khilgaon"}},
        {"Khilgaon", {"Rampura"}},
        {"Rampura", {}}
    };

    vector<string> path; // To store the path

    // Find the path from Badda to Rampura via Mailbagh
    if (findPath(graph, "Badda", "Rampura", path)) {
        cout << "Path: ";
        for (string node : path) {
            cout << node << " -> ";
        }
        cout << "Destination reached." << endl;
    } else {
        cout << "No path found." << endl;
    }

    return 0;
}