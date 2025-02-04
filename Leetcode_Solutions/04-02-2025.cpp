#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxAscendingSum(vector<int> &nums)
    {
        int n = nums.size();
        int last = nums[0], sum = last, maxi = 0;
        for (int i = 1; i < n; i++)
        {
            if (last < nums[i])
            {
                sum += nums[i];
                last = nums[i];
            }
            else
            {
                maxi = max(maxi, sum);
                sum = last = nums[i];
            }
        }
        maxi = max(maxi, sum);
        return maxi;
    }
};