#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define mod 1000000007
int power(int a, int b, int MOD)
{
    int response = 1;
    a = a % MOD; // Ensure a is reduced modulo MOD initially
    while (b > 0)
    {
        if (b & 1)
        { // If the current bit of b is 1
            response = (1LL * response * a) % MOD;
        }
        a = (1LL * a * a) % MOD; // Square a and take modulo MOD
        b = b >> 1;              // Shift b to the right (divide by 2)
    }
    return response; // Return the result
}

int32_t main()
{
    fast;
    cout << "Hello World" << endl;
    return 0;
}
class Solution
{
public:
    int countDays(int days, vector<vector<int>> &meetings)
    {
        map<int, int> dayMap;
        int prefixSum = 0, freeDays = 0, previousDay = days;
        bool hasGap = false;

        for (auto &meeting : meetings)
        {
            // Set first day of meetings
            previousDay = min(previousDay, meeting[0]);

            // Process start and end of meeting
            dayMap[meeting[0]]++;
            dayMap[meeting[1] + 1]--;
        }

        // Add all days before the first day of meetings
        freeDays += (previousDay - 1);
        for (auto &day : dayMap)
        {
            int currentDay = day.first;
            // Add current range of days without a meeting
            if (prefixSum == 0)
            {
                freeDays += currentDay - previousDay;
            }
            prefixSum += day.second;
            previousDay = currentDay;
        }

        // Add all days after the last day of meetings
        freeDays += days - previousDay + 1;
        return freeDays;
    }
};