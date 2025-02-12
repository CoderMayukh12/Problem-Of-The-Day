#include <bits/stdc++.h>
using namespace std;
int sumDigits(int num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
class Solution
{
public:
    int maximumSum(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int ans = -1;
        for (int x : nums)
        {
            int s = sumDigits(x);
            if (mp.find(s) != mp.end())
            {
                ans = max(ans, mp[s] + x);
            }
            if (mp.find(s) == mp.end())
            {
                mp[s] = x;
            }
            else
            {
                mp[s] = max(mp[s], x);
            }
        }
        return ans;
    }
};
