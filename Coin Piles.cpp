// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minSteps(int A[], int N, int K) {
        int ans = INT_MAX;
        sort(A, A + N);
        
        vector<int> preSum(1,0);
        
        for(int i = 0; i < N; i++) {
            preSum.push_back(preSum[i] + A[i]);
        }
        
        for(int i = 0; i < N; i++) {
            if(preSum[i] >= ans) {
                return ans;
            }
                
            int p = upper_bound(A + i + 1, A + N, A[i] + K) - A;
            int total = preSum[N] - preSum[p] - (N - p) * (A[i] + K);
            
            ans = min(ans, preSum[i] + total);
        }
        
        return ans;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin>>N>>K;
        
        int A[N];
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.minSteps(A,N,K) << endl;
    }
    return 0;
}  // } Driver Code Ends