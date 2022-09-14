//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int MOD = 1e9 + 7;
    long long numberOfSubsequences(int N, long long A[]){
        long long result = 1, cnt = 0;
        for (int i = 0; i < N; ++i) {
            if ((A[i] & (A[i] - 1)) == 0) {
                cnt++;
            }
        }
        
        while (cnt--) {
            result = (result * 2) % MOD;
        }
        return result - 1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        long long A[N];
        for(int i=0;i<N;++i){
            cin >> A[i];
        }
        Solution ob;
        cout << ob.numberOfSubsequences(N,A) << endl;
    }
    return 0; 
} 
// } Driver Code Ends