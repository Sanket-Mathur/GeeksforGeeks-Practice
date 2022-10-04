//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int MOD = 1e9+ + 7;
  
    long long int numberOfPaths(int m, int n){
        vector<vector<long long int>> grid(m, vector<long long int> (n, 0));
        
        grid[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }
                
                if (i > 0 && j > 0) {
                    grid[i][j] = (grid[i - 1][j] + grid[i][j - 1]) % MOD;
                } else if (i > 0) {
                    grid[i][j] = grid[i - 1][j];
                } else {
                    grid[i][j] = grid[i][j - 1];
                }
            }
        }
        
        return grid[m - 1][n - 1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends