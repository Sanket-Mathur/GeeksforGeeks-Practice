//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int MOD = 1e8;
  public:
    int fillingBucket(int N) {
        if (N < 3) {
            return N;
        }
        
        vector<int> dp(N + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i < N + 1; ++i) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }
        return dp[N];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends