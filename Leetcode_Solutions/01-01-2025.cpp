#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxScore(string s)
    {
        vector<int> prefix(s.length() + 1, 0);
        int i = 1;
        for (char ch : s)
        {
            int x = ch - '0';
            prefix[i] = prefix[i - 1] + x;
            i = i + 1;
        }

        int maxScore = 0;

        // Iterate over possible split points (from 1 to n - 1)
        for (int i = 1; i < s.length(); i++)
        {
            // Left score: Count of `0`s in the left part
            int leftZeros = i - prefix[i];

            // Right score: Count of `1`s in the right part
            int rightOnes = prefix[s.length()] - prefix[i];

            // Total score
            maxScore = max(maxScore, leftZeros + rightOnes);
        }

        return maxScore;
    }
};