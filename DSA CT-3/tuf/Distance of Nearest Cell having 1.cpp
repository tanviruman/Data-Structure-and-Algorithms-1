#include <iostream>   // Include the standard input-output library
#include <vector>     // Include the vector container from the Standard Template Library (STL)
#include <queue>      // Include the queue container for BFS traversal
using namespace std;  // Use the standard namespace to avoid prefixing std::

/*
 * Class Solution containing a function to find the distance of the nearest '1' in a binary grid.
 */
class Solution {
public:
    /*
     * Function to compute the distance of the nearest '1' for each cell in the grid.
     * @param grid: 2D binary matrix where 1 represents an occupied cell and 0 represents an empty cell.
     * @return A 2D matrix where each cell contains the shortest distance to the nearest '1'.
     */
    vector<vector<int>> nearest(vector<vector<int>> grid) {
        int n = grid.size();   // Number of rows in the grid
        int m = grid[0].size(); // Number of columns in the grid
        
        // Matrices to store visited cells and distances
        vector<vector<int>> vis(n, vector<int>(m, 0));  // Visited matrix, initially set to 0 (unvisited)
        vector<vector<int>> dist(n, vector<int>(m, 0)); // Distance matrix, initially set to 0
        
        // Queue for BFS traversal, storing cell coordinates and step count
        queue<pair<pair<int, int>, int>> q;

        // Traverse the grid to find all '1' cells and initialize BFS from them
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) { // If the cell contains '1', it's a BFS starting point
                    q.push({{i, j}, 0}); // Push the coordinates and initial step count (0)
                    vis[i][j] = 1;       // Mark this cell as visited
                } else {
                    vis[i][j] = 0; // Mark '0' cells as unvisited
                }
            }
        }

        // Direction vectors for moving in 4 directions: up, right, down, left
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // Perform BFS traversal
        while (!q.empty()) {
            int row = q.front().first.first;  // Extract row index of current cell
            int col = q.front().first.second; // Extract column index of current cell
            int steps = q.front().second;     // Get the distance value
            q.pop(); // Remove the front element from the queue

            dist[row][col] = steps; // Store the shortest distance for this cell

            // Check all four possible directions
            for (int i = 0; i < 4; i++) {
                int newRow = row + delRow[i]; // Compute new row index
                int newCol = col + delCol[i]; // Compute new column index

                // Check if the new cell is within bounds and unvisited
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && vis[newRow][newCol] == 0) {
                    vis[newRow][newCol] = 1; // Mark it as visited
                    q.push({{newRow, newCol}, steps + 1}); // Push the new cell into the queue with incremented step count
                }
            }
        }

        return dist; // Return the final distance matrix
    }
};

/*
 * Main function to test the nearest function.
 */
int main() {
    // Define a sample binary grid
    vector<vector<int>> grid{
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 1}
    };

    Solution obj; // Create an instance of the Solution class

    // Call the nearest function and store the result
    vector<vector<int>> ans = obj.nearest(grid);

    // Print the resulting distance matrix
    cout << "Distance Matrix:\n";
    for (auto row : ans) {      // Iterate over each row
        for (auto cell : row) { // Iterate over each cell in the row
            cout << cell << " "; // Print the cell value
        }
        cout << "\n"; // Print a new line after each row
    }

    return 0; // Indicate successful execution
}
