//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int maxCoins(int N, vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (n));
        
        for (int x = 0; x < n; ++x) {
            for (int i = 0, j = x; j < n; ++i, ++j) {
                int maxVal = INT_MIN;
                for (int k = i; k <= j; ++k) {
                    int l = k == i ? 0 : dp[i][k - 1];
                    int r = k == j ? 0 : dp[k + 1][j];
                    
                    int val = (i == 0 ? 1 : arr[i - 1]) * arr[k] * (j == n - 1 ? 1 : arr[j + 1]);
                    
                    maxVal = max(maxVal, l + r + val);
                }
                dp[i][j] = maxVal;
            }
        }
        
        return dp[0][n - 1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends