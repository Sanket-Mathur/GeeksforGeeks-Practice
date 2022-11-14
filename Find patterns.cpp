//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int numberOfSubsequences(string S, string W){
        int res = 0;
        vector<bool> visited(S.size() + 1, false);
        
        for (int i = 0; i < S.size(); ++i) {
            int k = 0;
            for (int j = i; j < S.size() && k < W.size(); ++j) {
                if (!visited[j] && W[k] == S[j]) {
                    visited[j] = true;
                    ++k;
                }
            }
            
            if (k == W.size()) {
                ++res;
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S,W;
        cin >> S >> W;
        Solution ob;
        cout << ob.numberOfSubsequences(S,W) << endl;
    }
    return 0; 
} 


// } Driver Code Ends