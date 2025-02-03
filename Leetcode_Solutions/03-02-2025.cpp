#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestMonotonicSubarray(vector<int> &nums)
    {
        int len = 1, maxlen = 1, flag = 0, last = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > last)
            {
                if (flag == 2)
                {
                    maxlen = max(maxlen, len);

                    len = 2;
                }
                else
                    len++;
                flag = 1;
            }
            else if (nums[i] < last)
            {
                if (flag == 1)
                { // Switch from increasing to decreasing
                    maxlen = max(maxlen, len);
                    len = 2; // Reset length
                }

                else
                    len++;
                flag = 2;
            }
            else
            {
                maxlen = max(maxlen, len);
                flag = 0;
                len = 1;
            }
            last = nums[i];
        }
        maxlen = max(maxlen, len);
        return maxlen;
    }
};