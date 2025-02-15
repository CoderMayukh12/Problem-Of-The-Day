#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // to_string(int value)

public:
    bool canPartitionSum(const std::string &digits, int index, int remaining)
    {
        // If we've reached the end of the digit string,
        // return true if and only if we've exactly hit the remaining sum.
        if (index == digits.size())
            return remaining == 0;

        int num = 0;
        // Try every possible chunk starting from 'index'
        for (int i = index; i < digits.size(); i++)
        {
            // Build the current number chunk by chunk
            num = num * 10 + (digits[i] - '0');
            // Recursively check if we can partition the remaining digits
            // to satisfy the sum condition.
            if (canPartitionSum(digits, i + 1, remaining - num))
                return true;
        }
        // No valid partition found starting at this index.
        return false;
    }

    // Main function that converts the number to a string and starts the
    // recursion.
    bool isChunkSumEqual(int x, int sq)
    {
        std::string digits = std::to_string(sq);
        return canPartitionSum(digits, 0, x);
    }

    int arr[1001] = {0};
    void done()
    {
        for (int i = 1; i <= 1000; i++)
        {
            arr[i] = arr[i - 1] + (isChunkSumEqual(i, i * i) ? i * i : 0);

            cout << i << "->" << arr[i] << endl;
        }
    }
    Solution()
    {
        done();
    }

    int punishmentNumber(int n)
    {

        return arr[n];
    }
};