
// This question should be solved in O(n) complexity.
//  This is almost same as Leetcode https://leetcode.com/problems/squares-of-a-sorted-array/description/
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
private:
    int transformed(int x, int a, int b, int c)
    {
        return a * x * x + b * x + c;
    }

public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C)
    {
        // code here
        multiset<int> st;

        for (int &x : arr)
        {

            st.insert(transformed(x, A, B, C));
        }

        return vector<int>(st.begin(), st.end());
    }
};

//{ Driver Code Starts.
int main()
{

    return 0;
}
// } Driver Code Ends