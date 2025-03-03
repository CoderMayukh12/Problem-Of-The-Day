#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        vector<int> grr, lrr, numbers;
        for (int x : nums)
        {
            if (x < pivot)
                lrr.push_back(x);
            else if (x == pivot)
                numbers.push_back(x);
            else
                grr.push_back(x);
        }
        vector<int> ans;
        for (int x : lrr)
            ans.push_back(x);
        for (int x : numbers)
            ans.push_back(x);
        for (int x : grr)
            ans.push_back(x);
        return ans;
    }
};