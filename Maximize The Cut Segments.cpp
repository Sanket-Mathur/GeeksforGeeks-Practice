// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        unordered_map<int, int> memo;
        
        int result = helper(n, x, y, z, memo);
        return result < 0 ? 0 : result;
    }
    
    int helper(int n, int x, int y, int z, unordered_map<int, int> &memo) {
        if (n == 0)
            return 0;
        if (n < 0)
            return INT_MIN;
        if (memo.find(n) != memo.end())
            return memo[n];
        
        int res = INT_MIN;
        res = max(res, 1 + helper(n - x, x, y, z, memo));
        res = max(res, 1 + helper(n - y, x, y, z, memo));
        res = max(res, 1 + helper(n - z, x, y, z, memo));
        
        memo[n] = res;
        return res;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends