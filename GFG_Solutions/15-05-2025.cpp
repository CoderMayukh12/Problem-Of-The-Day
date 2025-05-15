#include <bits/stdc++.h>
using namespace std;
#define int long long
class Solution
{
private:
    int nc2(int n)
    {

        return (n < 2) ? 0 : (n * (n - 1) / 2);
    }

public:
    int countSubstring(string &s)
    {

        // Store The Frequency of Each character:
        vector<int> freq(26, 0);

        for (char ch : s)
        {
            freq[ch - 'a']++;
        }

        int count = 0;

        // Each Character Contributes Two Way
        // 1.Each Character has it's own solo contribution.
        // 2.Any 2 occurance of a Character contributes 1 here.
        // So, Add it Up.
        for (int &x : freq)
        {
            count += (x + (nc2(x)));
        }

        return count;
    }
    // Remarks:
    //  I Had to read the article for better perspective.
};
unsigned main()
{
    return 0;
}
