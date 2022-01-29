// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        int global = 0;
        vector<int> dp(n, 0);
        
        for (int i = 0; i < n; ++i) {
            int local = 0;
            for (int j = 0; j < i; ++j) {
                if (a[i] > a[j]) {
                    local = max(local, dp[j]);
                }
            }
            
            dp[i] = local + 1;
            global = max(global, dp[i]);
        }
        
        return global;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends