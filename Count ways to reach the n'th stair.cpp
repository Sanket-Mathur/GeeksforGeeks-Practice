// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    int MOD = 1000000007;
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        int a = 1, b = 1, c;
        for (int i = 1; i < n; ++i) {
            c = (a + b) % MOD;
            a = b;
            b = c;
        }
        
        return b;
    }
};



// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}
  // } Driver Code Ends