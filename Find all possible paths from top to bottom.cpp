// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<int>> result;
        vector<int> curr;
        
        findPath(grid, result, n, m, curr, 0, 0);
        
        return result;
    }
    
    void findPath(vector<vector<int>> &grid, vector<vector<int>> &result, int n, int m, vector<int> curr, int i, int j) {
        if (i == n || j == m) {
            return;
        }
        
        curr.push_back(grid[i][j]);
        
        if (i == n - 1 && j == m - 1) {
            result.push_back(curr);
        }
        
        findPath(grid, result, n, m, curr, i + 1, j);
        findPath(grid, result, n, m, curr, i, j + 1);
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
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends