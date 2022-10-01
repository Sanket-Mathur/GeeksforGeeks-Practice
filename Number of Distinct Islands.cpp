//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<string> strSet;
        
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    string str;
                    find(grid, i, j, str, '0');
                    
                    if (strSet.find(str) == strSet.end()) {
                        strSet.insert(str);
                    }
                }
            }
        }
        
        return strSet.size();
    }
    
    void find(vector<vector<int>>& grid, int i, int j, string &str, char dir) {
        if (!isValid(grid, i, j)) {
            return;
        }
        
        grid[i][j] = 0;
        str.push_back(dir);
        
        find(grid, i + 1, j, str, 'R');
        find(grid, i - 1, j, str, 'L');
        find(grid, i, j + 1, str, 'D');
        find(grid, i, j - 1, str, 'U');
        
        str.push_back('-');
    }
    
    bool isValid(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) {
            return false;
        }
        return true;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends