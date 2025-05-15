
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string generate(string previous)
    {
        char last = previous[0];
        string ans = "";
        int count = 1;
        for (int i = 1; i < previous.length(); i++)
        {
            if (previous[i] != last)
            {
                ans = ans + to_string(count) + last;
                count = 1;
                last = previous[i];
            }
            else
            {
                count++;
            }
        }
        // Add the last group
        ans = ans + to_string(count) + last;
        return ans;
    }
    string countAndSay(int n)
    {
        // code here
        vector<string> results(30, "");
        vector<string> samples = {"1", "11", "21", "1211", "111221"};
        for (int i = 0; i < 5; i++)
        {
            results[i] = samples[i];
        }
        for (int i = 5; i < 30; i++)
        {
            results[i] = generate(results[i - 1]);
        }
        // All Precomputation is Done.
        //  Now, Just return the result.

        return results[n - 1];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.countAndSay(n) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends