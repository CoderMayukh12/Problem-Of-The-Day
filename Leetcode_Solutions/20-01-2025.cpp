// #include <bits/stdc++.h>
// using namespace std;
// class Solution
// {
// public:
//     int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
//     {
//         unordered_map<int, pair<int, int>> mpp;
//         for (int i = 0; i < mat.size(); i++)
//         {
//             for (int j = 0; j < mat[i].size(); j++)
//             {
//                 int x = mat[i][j];
//                 mpp[x] = {i, j};
//             }
//         }
//         // Mapped SuccessFully
//         int n = mat.size();
//         int m = mat[0].size();
//         vector<int> r(n, m);
//         vector<int> c(m, n);
//         for (int i = 0; i < arr.size(); i++)
//         {
//             int ele = arr[i];
//             auto it = mpp[ele];
//             int x = it.first;
//             int y = it.second;
//             r[x]--;
//             c[y]--;
//             if (!r[x] || !c[y])
//                 return i;
//         }
//         return 0;
//     }
// };
// int main()
// {
//     return 0;
// }