#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumRecolors(string blocks, int k)
    {
        int n = blocks.size();
        int white = 0, mini = INT_MAX;

        // Count the number of 'W' in the first window of size k
        for (int i = 0; i < k; i++)
        {
            if (blocks[i] == 'W')
                white++;
        }
        mini = white; // Initial minimum recolors

        // Slide the window across the string
        for (int i = k; i < n; i++)
        {
            if (blocks[i] == 'W')
                white++; // Add the new right-end character
            if (blocks[i - k] == 'W')
                white--;             // Remove the left-end character
            mini = min(mini, white); // Update minimum recolors needed
        }
        return mini;
    }
};
