#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        vector<int> diff;

        // Collect indices where s1 and s2 differ
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] != s2[i])
            {
                diff.push_back(i);
            }
        }

        // No mismatch, already equal
        if (diff.empty())
            return true;

        // More than 2 mismatches → cannot be fixed by one swap
        if (diff.size() != 2)
            return false;

        // Check if swapping the two mismatched characters makes the strings equal
        return s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]];
    }
};
