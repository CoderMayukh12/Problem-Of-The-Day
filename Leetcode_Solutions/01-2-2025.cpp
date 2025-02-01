#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isArraySpecial(vector<int> &nums)
    {
        vector<bool> check;
        for (int i = 0; i < nums.size(); i++)
        {
            bool flag = (nums[i] % 2 == 0);
            if (check.size() == 0)
            {
                check.push_back(flag);
            }
            else
            {
                if (flag == check.back())
                    return false;
                else
                    check.push_back(flag);
            }
        }
        return true;
    }
};