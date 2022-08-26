//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int MOD = 1e9 + 7;
    /*You are required to complete below method */
    long long int countPS(string str)
    {
        int n = str.length();
        vector<vector<long long int>> dp(n, vector<long long int> (n, 0));
        
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                if (str[j] == str[j + i]) {
                    dp[j][j + i] = (1 + dp[j + 1][j + i] + dp[j][j + i - 1]) % MOD;
                } else {
                    dp[j][j + i] = (dp[j + 1][j + i] + dp[j][j + i - 1] - dp[j + 1][j + i - 1] + MOD) % MOD;
                }
            }
        }
        
        return dp[0][n - 1];
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends