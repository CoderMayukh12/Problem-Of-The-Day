//
// I Didn't Understood The Problem Statement as well as the Solution.
// Need to read the article:

// https://www.geeksforgeeks.org/find-smallest-range-containing-elements-from-k-lists/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val, row, col;
    bool operator>(const Node &other) const
    {
        return val > other.val;
    }
};
class Solution
{
    struct Node
    {
        int val, row, col;
        bool operator>(const Node &other) const
        {
            return val > other.val;
        }
    };

public:
    vector<int> findSmallestRange(vector<vector<int>> &arr)
    {

        struct Node
        {
            int val, row, col;
            bool operator>(const Node &other) const
            {
                return val > other.val;
            }
        };
        int N = arr.size();    // Number of rows
        int K = arr[0].size(); // Number of columns (same for each row)
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        int maxVal = INT_MIN;

        // Push the first element of each list into the min-heap
        for (int i = 0; i < N; i++)
        {
            pq.push({arr[i][0], i, 0});
            maxVal = max(maxVal, arr[i][0]);
        }

        int minRange = INT_MAX, minEl, maxEl;

        while (true)
        {
            Node curr = pq.top();
            pq.pop();
            int minVal = curr.val;

            // Update range if better
            if (maxVal - minVal < minRange)
            {
                minRange = maxVal - minVal;
                minEl = minVal;
                maxEl = maxVal;
            }

            // If we've reached the end of a list, break
            if (curr.col + 1 == K)
                break;

            // Push next element from the same list
            int nextVal = arr[curr.row][curr.col + 1];
            pq.push({nextVal, curr.row, curr.col + 1});
            maxVal = max(maxVal, nextVal);
        }

        return {minEl, maxEl};
    }
};

int main()
{

    return 0;
}
