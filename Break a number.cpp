//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution{ 
    int MOD = 1e9 + 7;
public:
    int waysToBreakNumber(int N){
        return (int)((((long long)N + 1) % MOD) * (((long long)N + 2) % MOD) % MOD) / 2;
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
        Solution ob;
        cout << ob.waysToBreakNumber(N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends