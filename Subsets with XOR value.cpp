// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
public:
    int subsetXOR(vector<int> arr, int N, int K) {
        unordered_map<string, int> memo;
        return helper(arr, K, N, 0, memo);
    }
    
    int helper(vector<int> &arr, int K, int N, int XOR, unordered_map<string, int> &memo) {
        if (N == 0) {
            return XOR == K ? 1 : 0;
        }
        
        string key = to_string(N) + "-" + to_string(XOR);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        
        memo[key] = helper(arr, K, N - 1, XOR ^ arr[N - 1], memo) + helper(arr, K, N - 1, XOR, memo);
        return memo[key];
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}  // } Driver Code Ends