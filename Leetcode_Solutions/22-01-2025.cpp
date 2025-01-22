#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int n = isWater.size();
        int m = isWater[0].size();
        vector<vector<int>> height(
            n,
            vector<int>(m, -1)); // Initialize with -1 to denote unvisited cells
        queue<pair<int, int>> q;

        // Start with water cells (height 0)
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (isWater[i][j] == 1)
                {
                    height[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Directions for moving up, down, left, and right
        int r0[] = {0, -1, 0, 1};
        int c0[] = {-1, 0, 1, 0};

        // BFS to calculate heights
        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = r + r0[i];
                int ncol = c + c0[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    height[nrow][ncol] == -1)
                {
                    height[nrow][ncol] = height[r][c] + 1;
                    q.push({nrow, ncol});
                }
            }
        }

        return height;
    }
};
