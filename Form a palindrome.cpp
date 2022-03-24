// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMinInsertions(string S){
        int n = S.length();
        vector<vector<int>> table(n, vector<int> (n, 0));
        
        for (int i = n; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (S[i] == S[j]) {
                    if (i - j == 1) {
                        table[i][j] = 0;
                    } else {
                        table[i][j] = table[i + 1][j - 1];
                    }
                } else {
                    table[i][j] = 1 + min(table[i][j - 1], table[i + 1][j]);
                }
            }
        }
        
        return table[0][n - 1];
    }
};

// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends