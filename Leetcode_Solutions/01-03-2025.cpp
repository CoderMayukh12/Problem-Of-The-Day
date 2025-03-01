#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> applyOperations(vector<int> &arr)
    {
        int n = arr.size();
        // Step 1: Apply the doubling operation.
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] == arr[i + 1])
            {
                arr[i] *= 2;
                arr[i + 1] = 0;
            }
        }

        // Step 2: Move zeros to the end using two pointers.
        int insertPos = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 0)
            {
                arr[insertPos++] = arr[i];
            }
        }
        // Fill the remaining positions with zeros.
        while (insertPos < n)
        {
            arr[insertPos++] = 0;
        }

        return arr;
    }
};
