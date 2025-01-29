#include <iostream>   // Include the standard input-output library
#include <vector>     // Include the vector container from the Standard Template Library (STL)
#include <queue>      // Include queue for BFS traversal
using namespace std;  // Use the standard namespace to avoid prefixing std::

/*
 * Function to determine the minimum number of minutes required for all oranges to rot.
 * @param grid: 2D vector representing the grid where:
 *              0 - Empty cell
 *              1 - Fresh orange
 *              2 - Rotten orange
 * @return The minimum number of minutes required, or -1 if all oranges cannot rot.
 */
int orangesRotting(vector<vector<int>>& grid) {
    if (grid.empty()) return 0; // Edge case: If the grid is empty, return 0
    
    int rows = grid.size();    // Number of rows in the grid
    int cols = grid[0].size(); // Number of columns in the grid
    int days = 0;              // Variable to track the number of minutes (days)
    int totalOranges = 0;      // Total number of oranges in the grid
    int rottenCount = 0;       // Count of rotten oranges over time
    
    queue<pair<int, int>> rottenQueue; // Queue to store the coordinates of rotten oranges
    
    // Traverse the grid to count the total oranges and add initial rotten ones to the queue
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] != 0) totalOranges++;  // Count non-empty cells (total oranges)
            if (grid[i][j] == 2) rottenQueue.push({i, j}); // Enqueue initial rotten oranges
        }
    }

    // Directions for moving in 4 possible adjacent cells (right, left, down, up)
    int dx[4] = {0, 0, 1, -1};  
    int dy[4] = {1, -1, 0, 0};  
    
    // Perform BFS traversal to spread rot to fresh oranges
    while (!rottenQueue.empty()) {
        int currentLevelSize = rottenQueue.size(); // Number of rotten oranges at the current level
        rottenCount += currentLevelSize;           // Update the count of processed rotten oranges
        
        while (currentLevelSize--) { // Process all rotten oranges in the current level
            int x = rottenQueue.front().first;  // Get the row index
            int y = rottenQueue.front().second; // Get the column index
            rottenQueue.pop(); // Remove the processed rotten orange
            
            // Visit all 4 possible adjacent cells
            for (int i = 0; i < 4; ++i) {
                int newX = x + dx[i]; // Calculate new row index
                int newY = y + dy[i]; // Calculate new column index
                
                // Check if the adjacent cell is within bounds and contains a fresh orange
                if (newX >= 0 && newY >= 0 && newX < rows && newY < cols && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2; // Mark the fresh orange as rotten
                    rottenQueue.push({newX, newY}); // Add the newly rotten orange to the queue
                }
            }
        }
        
        // Increase the time (days) if there are still rotten oranges in the queue
        if (!rottenQueue.empty()) days++;
    }
    
    // If all oranges have been processed, return the total time, otherwise return -1
    return totalOranges == rottenCount ? days : -1;
}

/*
 * Main function to test the orangesRotting function.
 */
int main() {
    // Define the grid representing the orange states
    vector<vector<int>> grid{
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    // Call the function and store the result
    int rottingTime = orangesRotting(grid);

    // Print the minimum number of minutes required
    cout << "Minimum Number of Minutes Required: " << rottingTime << endl;

    return 0; // Indicate successful execution
}
