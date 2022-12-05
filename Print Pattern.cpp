//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> pattern(int N) {
        vector<int> result;
        print(N, result);
        
        return result;
    }
    
    void print(int N, vector<int> &result) {
        result.push_back(N);
        
        if (N <= 0) {
            return;
        }
        
        print(N - 5, result);
        result.push_back(N);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends