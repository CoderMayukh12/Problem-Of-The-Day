#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    string binary(int n, int bits)
    {
        string ans = "";
        for (int i = bits - 1; i >= 0; i--)
        {
            ans.push_back((n & (1 << i)) ? '1' : '0');
        }
        return ans;
    }

public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        int bits = nums[0].size();
        unordered_set<string> st(nums.begin(), nums.end());
        for (int i = 0; i < (1 << bits); i++)
        {
            string candidate = binary(i, bits);
            if (st.find(candidate) == st.end())
            {
                return candidate;
            }
        }
        return "";
    }
};
