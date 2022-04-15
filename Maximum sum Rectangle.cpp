// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        vector<int> dp(R, 0);
        int maxRes = INT_MIN, maxSingle = INT_MIN;
        
        for (int i = 0; i < C; ++i) {
            for (int j = i; j < C; ++j) {
                for (int k = 0; k < R; ++k) {
                    dp[k] += M[k][j];
                    maxSingle = max(maxSingle, M[k][j]);
                }
                maxRes = max(maxRes, kadane(dp));
            }
            dp = vector<int> (R, 0);
        }
        
        return maxRes == 0 ? maxSingle : maxRes;
    }
    
    int kadane(vector<int> arr) {
        int res = 0, curr = 0;
        for (int i = 0; i < arr.size(); ++i) {
            curr += arr[i];
            res = max(res, curr);
            
            if (curr < 0) {
                curr = 0;
            }
        }
        
        return res;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends