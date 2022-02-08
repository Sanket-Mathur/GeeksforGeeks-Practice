// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> primeRange(int M, int N) {
        vector<bool> prime (N + 1, true);
        prime[0] = prime[1] = false;
        
        int p = 2;
        while (p * p <= N) {
            if (prime[p]) {
                for (int i = p * p; i <= N; i += p) {
                    prime[i] = false;
                }
            }
            ++p;
        }
        
        vector<int> result;
        for (int i = M; i <= N; ++i) {
            if (prime[i]) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, K;
        cin >> M >> N;
        Solution ob;
        vector<int> ans = ob.primeRange(M, N);
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
}  // } Driver Code Ends