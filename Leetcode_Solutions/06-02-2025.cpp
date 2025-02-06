#include <bits/stdc++.h>
using namespace std;
// Each position in the tuple (a, b, c, d) can be arranged in multiple ways:
// (a, b) can be swapped → 2 ways
// (c, d) can be swapped → 2 ways
// (a, b) and (c, d) can swap places → 2 ways
// Thus, multiplying them together:

// 2
// ×
// 2
// ×
// 2
// =
// 8
// 2×2×2=8
// Summary
// nc2 → Chooses 2 distinct pairs that have the same product.
// Multiply by 8 → Accounts for all valid permutations.
class Solution
{
public:
    int tupleSameProduct(vector<int> &nums)
    {
        map<long long int, int> mpp;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                mpp[nums[i] * nums[j]]++;
            }
        }
        int count = 0;
        for (auto it : mpp)
        {
            if (it.second >= 2)
                count += (it.second * (it.second - 1) / 2);
        }
        return count * 8;
    }
};