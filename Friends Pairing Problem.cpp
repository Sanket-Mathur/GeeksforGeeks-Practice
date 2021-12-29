// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int MOD = 1000000007;
    
    int countFriendsPairings(int n) 
    {
        unordered_map<int, int> memo;
        memo[0] = 0;
        memo[1] = 1;
        
        util(n, memo);
        return memo[n];
    }
    
    long long util(int n, unordered_map<int, int> &memo) {
        if (n < 2)
            return 1;
        if (memo.find(n) != memo.end())
            return memo[n];
        
        long long result = util(n - 1, memo) + ((n - 1) * util(n - 2, memo));
        memo[n] = (int) (result % MOD);
        return result % MOD;
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends