//Problem Link--https://www.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array3611/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findMin(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;

    while (left < right) { // Use < instead of <= to avoid overflow in the final step
        int mid = left + (right - left) / 2;

        // If mid element is greater than the rightmost, the minimum is in the right half
        if (arr[mid] > arr[right]) {
            left = mid + 1;
        } 
        // Otherwise, the minimum is in the left half (including mid)
        else {
            right = mid;
        }
    }

    // At the end of the loop, left == right, pointing to the minimum element
    return arr[left];
}

};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    Solution ob;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << ob.findMin(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
