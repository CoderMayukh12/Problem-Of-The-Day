#include <bits/stdc++.h>
using namespace std;
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int col)
    {
        // Base case: if the current cell is out of bounds or already visited, or no fish is there
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || visited[row][col] || grid[row][col] == 0)
        {
            return 0; // Return 0 as there is no fish to add
        }

        // Mark the current cell as visited
        visited[row][col] = true;

        // Explore all 4 directions (up, down, left, right)
        int fishCount = grid[row][col];
        fishCount += dfs(grid, visited, row - 1, col); // Up
        fishCount += dfs(grid, visited, row + 1, col); // Down
        fishCount += dfs(grid, visited, row, col - 1); // Left
        fishCount += dfs(grid, visited, row, col + 1); // Right

        return fishCount; // Return the total fish count for this connected region
    }

public:
    int findMaxFish(vector<vector<int>> &grid)
    {
        int n = grid.size();                                     // Number of rows
        int m = grid[0].size();                                  // Number of columns
        vector<vector<bool>> visited(n, vector<bool>(m, false)); // Visited grid

        int maxFish = 0;

        // Traverse the grid
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (grid[i][j] > 0 && !visited[i][j])
                {                                                     // If there is fish and the cell is not visited
                    maxFish = max(maxFish, dfs(grid, visited, i, j)); // Update max fish count
                }
            }
        }

        return maxFish; // Return the maximum fish count found in any connected region
    }
};
