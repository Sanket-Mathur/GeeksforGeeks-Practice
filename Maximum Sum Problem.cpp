// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    unordered_map<int, int> memo;
    public:
        int maxSum(int n)
        {
            if (n == 0)
                return 0;
            if (memo.find(n) != memo.end())
                return memo[n];
            
            int a = n / 2, b = n / 3, c = n / 4;
            a = max(a, maxSum(a)); 
            b = max(b, maxSum(b)); 
            c = max(c, maxSum(c));
            
            memo[n] = a + b + c;
            return a + b + c;
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
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends