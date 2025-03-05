#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<long long int> arr;

public:
    Solution()
    {
        arr.resize(1e5 + 1, 0);
        arr[1] = 1;
        arr[2] = 5;
        for (int i = 2; i < 1e5 + 1; i++)
        {
            arr[i] = arr[i - 1] + 4 * (i - 1);
        }
    }
    long long coloredCells(int n)
    {
        return arr[n];
    }
};