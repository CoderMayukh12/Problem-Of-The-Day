#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int i = 0, rotated = 0;
        while (i < nums.size() - 1)
        { // Adjusted loop condition
            if (nums[i] > nums[i + 1])
                rotated++;

            i++;
        }
        if (nums[0] < nums[nums.size() - 1])
            rotated++;
        return !(rotated > 1);
    }
};
