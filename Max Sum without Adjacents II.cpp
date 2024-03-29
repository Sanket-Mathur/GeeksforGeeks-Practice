//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    vector<vector<int>> dp(2, vector<int> (n, 0));
	    dp[0][0] = arr[0];
	    
	    for (int i = 1; i < n; ++i) {
	        dp[0][i] = dp[1][i - 1] + arr[i];
	        dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]);
	    }
	    
	    return max(dp[0][n - 1], dp[1][n - 1]);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends