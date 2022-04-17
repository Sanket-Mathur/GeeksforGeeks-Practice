// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        int r = Matrix.size();
        int c = Matrix[0].size();
        
        for (int i = r - 2; i >= 0; --i) {
            Matrix[i][0] += max(Matrix[i + 1][0], Matrix[i + 1][1]);
            Matrix[i][c - 1] += max(Matrix[i + 1][c - 1], Matrix[i + 1][c - 2]);
            
            for (int j = 1; j < c - 1; ++j) {
                Matrix[i][j] += max(Matrix[i + 1][j], max(Matrix[i + 1][j - 1], Matrix[i + 1][j + 1]));
            }
        }
        
        int res = INT_MIN;
        for (int i = 0; i < c; ++i) {
            res = max(res, Matrix[0][i]);
        }
        
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends