#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        priority_queue<long long int, vector<long long int>, greater<long long int>> pq;
        for (int number : nums)
        {
            if (number <= k)
                pq.push(number);
        }
        int count = 0;
        while (true && !pq.empty())
        {
            long long int x = pq.top();
            pq.pop();
            long long int y = pq.top();
            pq.pop();
            if (x >= k && y >= k)
                return count;
            long long int n = min(x, y) * 2 + max(x, y);
            pq.push(n);
            count = count + 1;
        }
        return count;
    }
};
class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        priority_queue<long, vector<long>, greater<long>> min_heap(nums.begin(),
                                                                   nums.end());
        int num_operations = 0;

        while (min_heap.top() < k)
        {
            long x = min_heap.top();
            min_heap.pop();
            long y = min_heap.top();
            min_heap.pop();
            min_heap.push(min(x, y) * 2 + max(x, y));

            num_operations++;
        }
        return num_operations;
    }
};