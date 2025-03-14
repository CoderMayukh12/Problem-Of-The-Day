#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isPossible(long long int mid, vector<int> &candies, long long k)
    {
        long long int count = 0;
        for (int x : candies)
            count += (x / mid);
        return count >= k;
    }

public:
    int maximumCandies(vector<int> &candies, long long k)
    {
        long long sum = 0;
        for (auto x : candies)
            sum += x;
        if (sum < k)
            return 0;

        long long int low = 1,
                      high = *max_element(candies.begin(), candies.end());
        long long int maximum = 0;

        while (low <= high)
        {
            long long int mid = low + (high - low) / 2;
            if (isPossible(mid, candies, k))
            {
                maximum = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return maximum;
    }
};
