//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int MOD = 1e9 + 7;
    
    int knots(int M, int N, int K){
        return (nCr(N, K) * nCr(M, K)) % MOD;
    }
    
    long long nCr(int n, int r) {
        if (r > n - r) {
            r = n - r;
        }
        
        vector<int> dp(r + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = min(i, r); j > 0; --j) {
                dp[j] = (dp[j] + dp[j - 1]) % MOD;
            }
        }
        
        return dp[r];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int M, N, K;
        cin>>M>>N>>K;
        
        Solution ob;
        cout<<ob.knots(M, N, K)<<"\n";
    }
    return 0;
}
// } Driver Code Ends