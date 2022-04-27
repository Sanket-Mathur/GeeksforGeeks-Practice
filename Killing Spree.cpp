// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
public:
    long long int killinSpree(long long int n)
    {
        long long int lo = 1, hi = sqrt(n) + 1, mid;
        
        while (lo <= hi) {
            mid = lo + (hi - lo) / 2;
            long long int sum = mid * (mid + 1) * (2 * mid + 1) / 6;
            
            if (n == sum) {
                return mid;
            } else if (n > sum) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return hi;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n; cin>>n;
        Solution obj;
        long long int ans = obj.killinSpree(n);
        cout<<ans<<"\n";
    }
    return 0;
}
  // } Driver Code Ends