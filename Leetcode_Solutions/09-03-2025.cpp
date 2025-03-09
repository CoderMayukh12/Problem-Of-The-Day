#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define mod 1000000007
class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        int maxLen = 1, ans = 0, n = colors.size();
        for (int i = 1; i <= n + k - 2; i++)
        {
            if (colors[i % n] != colors[(i - 1 + n) % n])
            {
                maxLen++;
            }
            else
            {
                maxLen = 1;
            }
            if (maxLen >= k)
                ans++;
        }
        return ans;
    }
};
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
    fast
            cout
        << "Hello World" << endl;
    return 0;
}
