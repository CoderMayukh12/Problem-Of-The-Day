#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long gridGame(vector<vector<int>> &arr)
    {
        int n = arr.size();
        int m = arr[0].size();
        vector<vector<long long>> grid(n, vector<long long>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                grid[i][j] = arr[i][j];
            }
        }
        for (int i = 1; i < m; i++)
        {
            grid[0][i] += grid[0][i - 1];
            grid[1][i] += grid[1][i - 1];
        }
        long long ans = LLONG_MAX;
        for (int i = 0; i < m; i++)
        {
            long long top = grid[0][m - 1] - grid[0][i];
            long long bottom = (i == 0 ? 0 : grid[1][i - 1]);
            ans = min(ans, max(top, bottom));
        }
        return ans;
    }
};