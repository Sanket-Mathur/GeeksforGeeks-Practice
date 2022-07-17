//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        vector<vector<int>> dp(n + 1, vector<int> (k + 1, 0));
        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < k + 1; ++j) {
                if (j == 1) {
                    dp[i][j] = 1;
                } else if (i == 1) {
                    dp[i][j] = j;
                } else {
                    int minVal = INT_MAX;
                    for (int x = j - 1, y = 0; x >= 0; --x, ++y) {
                        minVal = min(minVal, max(dp[i][x], dp[i - 1][y]));
                    }
                    dp[i][j] = minVal + 1;
                }
            }
        }
        
        return dp[n][k];
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends