//Question 3: The Maze of Mysteries
#include <iostream>
#include <vector>
using namespace std;

// Function to check if we can find 2 treasures within 6 moves
bool canFindTreasures(vector<vector<int>>& maze, int x, int y, int moves, int treasuresFound) {
    // Base cases
    if (x < 0 || y < 0 || x >= maze.size() || y >= maze[0].size() || maze[x][y] == 1) {
        return false; // Out of bounds or hit a wall
    }
    if (moves > 6) {
        return false; // Exceeded the move limit
    }
    if (maze[x][y] == 2) {
        treasuresFound++; // Found a treasure
    }
    if (treasuresFound == 2) {
        return true; // Found 2 treasures
    }

    // Mark the current cell as visited
    int temp = maze[x][y];
    maze[x][y] = 1;

    // Explore all 4 directions
    bool result = canFindTreasures(maze, x + 1, y, moves + 1, treasuresFound) ||
                  canFindTreasures(maze, x - 1, y, moves + 1, treasuresFound) ||
                  canFindTreasures(maze, x, y + 1, moves + 1, treasuresFound) ||
                  canFindTreasures(maze, x, y - 1, moves + 1, treasuresFound);

    // Backtrack: unmark the current cell
    maze[x][y] = temp;

    return result;
}

int main() {
    // Maze 1
    vector<vector<int>> maze1 = {
        {0, 1, 0, 0, 2},
        {0, 0, 0, 1, 0},
        {3, 3, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0}
    };

    // Maze 2
    vector<vector<int>> maze2 = {
        {0, 1, 0, 0, 2},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 3, 3}
    };

    // Test Maze 1
    if (canFindTreasures(maze1, 1, 0, 0, 0)) {
        cout << "Eureka, I am rich" << endl;
    } else {
        cout << "Treasure hunt is boring" << endl;
    }

    // Test Maze 2
    if (canFindTreasures(maze2, 1, 0, 0, 0)) {
        cout << "Eureka, I am rich" << endl;
    } else {
        cout << "Treasure hunt is boring" << endl;
    }

    return 0;
}
