// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> primeDivision(int N) {
        vector<bool> primes(N + 1, true);

        for (int p = 2; p * p <= N; ++p) {
            if (primes[p]) {
                for (int i = p * p; i <= N; i += p) {
                    primes[i] = false;
                }
            }
        }
        
        for (int i = 2; i <= N; ++i) {
            if (primes[i] && primes[N - i]) {
                return vector<int> {i, N - i};
            }
        }
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.primeDivision(N);
        cout<<ans[0]<<" "<<ans[1]<<"\n";
    }
    return 0;
}  // } Driver Code Ends