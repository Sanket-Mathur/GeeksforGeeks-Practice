//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int N, int K, vector<long long> GeekNum) {
        if (N <= K) {
            return GeekNum[N - 1];
        }
        
        long long sum = 0;
        for (auto i : GeekNum) {
            sum += i;
        }
        GeekNum.push_back(sum);
        
        for (int i = K; i < N - 1; ++i) {
            sum += (sum - GeekNum[i - K]);
            GeekNum.push_back(sum);
        }
        
        return sum;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends