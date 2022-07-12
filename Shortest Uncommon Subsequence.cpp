// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int MAX = 1000;
    
    int shortestUnSub(string S, string T) {
        int m = S.length(), n = T.length();
        
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for (int i = 0; i < m + 1; ++i) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n + 1; ++j) {
            dp[0][j] = MAX;
        }
        
        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                int k;
                for (k = j - 1; k >= 0; --k) {
                    if (T[k] == S[i - 1]) {
                        break;
                    }
                }
                
                if (k == -1) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i - 1][k]);
                }
            }
        }
        
        return dp[m][n] >= MAX ? -1 : dp[m][n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        cin>>S>>T;

        Solution ob;
        cout << ob.shortestUnSub(S,T) << endl;
    }
    return 0;
}  // } Driver Code Ends