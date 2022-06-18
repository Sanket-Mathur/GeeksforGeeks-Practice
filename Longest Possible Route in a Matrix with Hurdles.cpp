// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        if (matrix[xs][ys] == 0 || matrix[xd][yd] == 0) {
            return -1;
        }
        
        int result = -1;
        findPath(matrix, xs, ys, xd, yd, 0, result);
        
        return result;
    }
    
    void findPath(vector<vector<int>> &matrix, int xs, int ys, int xd, int yd, int currLen, int &result) {
        if (xs == xd && ys == yd) {
            result = max(result, currLen);
            return;
        } else if (xs < 0 || ys < 0 || xs >= matrix.size() || ys >= matrix[0].size() || matrix[xs][ys] == 0) {
            return;
        }
        
        matrix[xs][ys] = 0;
        findPath(matrix, xs - 1, ys, xd, yd, currLen + 1, result);
        findPath(matrix, xs + 1, ys, xd, yd, currLen + 1, result);
        findPath(matrix, xs, ys - 1, xd, yd, currLen + 1, result);
        findPath(matrix, xs, ys + 1, xd, yd, currLen + 1, result);
        matrix[xs][ys] = 1;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends