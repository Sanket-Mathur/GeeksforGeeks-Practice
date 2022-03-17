// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    int MOD = 1000000007;
  
    int kvowelwords(int N, int K) {
        vector<vector<long long>> dp(N + 1, vector<long long> (K + 1, -1));
        return (int)helper(N, K, K, dp);
    }
    
    long long helper(int N, int K, int x, vector<vector<long long>> &dp) {
        if (N == 0) {
            return 1;
        } else if (dp[N][x] != -1) {
            return dp[N][x];
        }
        
        long long resVowel = 0, resConsonent = 0;
        if (x > 0) {
            resVowel = (5 * helper(N - 1, K, x - 1, dp)) % MOD;
        }
        resConsonent = (21 * helper(N - 1, K, K, dp)) % MOD;
        
        dp[N][x] = (resVowel + resConsonent) % MOD;
        return dp[N][x];
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;int K;
        cin >>N>>K;
        
        Solution ob;
        int ans = ob.kvowelwords(N,K);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends