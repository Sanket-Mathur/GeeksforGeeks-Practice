//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<string> pattern(int n) {
        vector<string> res;
        
        int start = 1, end = n * (n + 1);
        for (int i = 0; i < n; ++i) {
            res.push_back("");
            
            for (int j = 0; j < 2 * i; ++j) {
                res[i] += "-";
            }
            for (int j = start; j < start + (n - i); ++j) {
                res[i] += to_string(j) + "*";
            }
            start = start + (n - i);
            for (int j = end - (n - i) + 1; j <= end; ++j) {
                res[i] += to_string(j) + "*";
            }
            end = end - (n - i);
            
            res[i].pop_back();
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<string> ans = ob.pattern(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<"\n";
    }
    return 0;
}
// } Driver Code Ends