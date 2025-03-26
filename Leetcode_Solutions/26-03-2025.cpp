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
    int minOperations(vector<vector<int>> &grid, int x)
    {
        vector<int> numsArray;
        int result = 0;

        // Flatten the grid into numsArray
        for (int row = 0; row < grid.size(); row++)
        {
            for (int col = 0; col < grid[0].size(); col++)
            {
                numsArray.push_back(grid[row][col]);
            }
        }

        int length = numsArray.size();

        // Partially sorts the array so that the median element is placed at the
        // middle index
        nth_element(numsArray.begin(), numsArray.begin() + length / 2,
                    numsArray.end());

        // Store the median element as the final common value to make all
        // elements equal to
        int finalCommonNumber = numsArray[length / 2];

        for (int number : numsArray)
        {
            // If the remainder when divided by x is different for any number,
            // return -1
            if (number % x != finalCommonNumber % x)
                return -1;
            // Add the number of operations required to make the current number
            // equal to finalCommonNumber
            result += abs(finalCommonNumber - number) / x;
        }

        return result;
    }
};