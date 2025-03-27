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
    int minimumIndex(vector<int> &nums)
    {
        unordered_map<int, int> firstMap, secondMap;
        int n = nums.size();

        // Add all elements of nums to second half
        for (auto &num : nums)
        {
            secondMap[num]++;
        }

        for (int index = 0; index < n; index++)
        {
            // Create split at current index
            int num = nums[index];
            secondMap[num]--;
            firstMap[num]++;

            // Check if valid split
            if (firstMap[num] * 2 > index + 1 &&
                secondMap[num] * 2 > n - index - 1)
            {
                return index;
            }
        }

        // No valid split exists
        return -1;
    }
};