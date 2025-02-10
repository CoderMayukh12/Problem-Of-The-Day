#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string clearDigits(string s)
    {
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < s.length(); i += 1)
        {
            if (isdigit(s[i]))
                st.pop();
            else
                st.push(s[i]);
        }
        string str = "";
        while (!st.empty())
        {
            str += st.top();
            st.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};