// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) {
        vector<vector<int>> dp(s.length() + 1, vector<int> (t.length() + 1, 0));
        
        for (int i = 0; i < s.length() + 1; ++i) {
            dp[i][0] = i;
        }
        for (int i = 0; i < t.length() + 1; ++i) {
            dp[0][i] = i;
        }
        
        for (int i = 1; i < s.length() + 1; ++i) {
            for (int j = 1; j < t.length() + 1; ++j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }
        }
        
        return dp[s.length()][t.length()];
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends