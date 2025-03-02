#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> mergeArrays(vector<vector<int>> &nums1, vector<vector<int>> &nums2)
    {
        vector<int> arr(1001, 0);
        for (int i = 0; i < nums1.size(); i++)
            arr[nums1[i][0]] = nums1[i][1];
        for (int i = 0; i < nums2.size(); i++)
            arr[nums2[i][0]] += nums2[i][1];
        vector<vector<int>> ans;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i])
                ans.push_back({i, arr[i]});
        }
        return ans;
    }
};