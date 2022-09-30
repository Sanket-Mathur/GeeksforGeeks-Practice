//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int safePos(int n, int k) {
        int res = 1;
        for (int i = 2; i <= n; ++i) {
            res = (res + k - 1) % i + 1;
        }
        
        return res;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << ob.safePos(n,k) << endl;
    }
    return 0;
}
// } Driver Code Ends