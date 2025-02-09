// Problem Link---> https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/?envType=daily-question&envId=2024-12-13
//  Optimal Approach:
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long findScore(vector<int> &nums)
    {
        // Min-Heap with value-index pairs
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int n = nums.size();

        // Populate the heap with (value, index) pairs
        for (int i = 0; i < n; i++)
        {
            pq.push({nums[i], i});
        }

        vector<bool> visited(n, false); // Tracks visited indices
        long long score = 0;

        while (!pq.empty())
        {
            // auto &[int value, idx] = pq.top();
            int value = pq.top().first;
            int idx = pq.top().second;
            pq.pop();

            // Skip if already visited
            if (visited[idx])
                continue;

            // Add to score and mark as visited
            score += value;
            visited[idx] = true;

            // Mark neighbors as visited
            if (idx > 0 && !visited[idx - 1])
                visited[idx - 1] = true;
            if (idx < n - 1 && !visited[idx + 1])
                visited[idx + 1] = true;
        }

        return score;
    }
};

// Brute-Force Approach:
class Solution
{
public:
    long long findScore(vector<int> &nums)
    {
        // Brute-Force Approach
        int count = nums.size();
        int n = nums.size();
        long long score = 0;
        int mini = INT_MAX, idx = -1;
        vector<bool> visited(n, false);
        while (count != 0)
        {
            for (int i = 0; i < n; i++)
            {
                if (!visited[i] && mini > nums[i])
                {
                    mini = nums[i];
                    idx = i;
                }
            }
            // We Got the Minimum Element
            count -= 1;
            score += nums[idx];
            visited[idx] = true;
            if (idx != 0)
            {
                visited[idx - 1] = true;
                count--;
            }
            if (idx != n - 1)
            {
                visited[idx + 1] = true;
                count--;
            }
        }
        return score;
    }
};

// Better Solution with Detailed Explanation:
class Solution
{
public:
    long long findScore(vector<int> &nums)
    {
        // Minimum-Heap
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, vector<int>> mpp;
        int n = nums.size();

        // Populate the heap and map
        for (int i = 0; i < n; i++)
        {
            pq.push(nums[i]);
            mpp[nums[i]].push_back(i);
        }

        vector<bool> visited(n, false); // Tracks visited indices
        long long score = 0;

        while (!pq.empty())
        {
            int x = pq.top();
            pq.pop();

            // Check all indices associated with the current value
            for (int idx : mpp[x])
            {
                if (!visited[idx])
                {
                    // Add to score
                    score += nums[idx];

                    // Mark the current index and its neighbors as visited
                    visited[idx] = true;
                    if (idx > 0 && !visited[idx - 1])
                        visited[idx - 1] = true;
                    if (idx < n - 1 && !visited[idx + 1])
                        visited[idx + 1] = true;

                    // Break after processing the first unvisited index for the value
                    break;
                }
            }
        }

        return score;
    }
};
