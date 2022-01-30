// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int Maximum_Sum(vector<vector<int>> &mat,int N,int K){
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j < N; ++j) {
                mat[i][j] += mat[i][j - 1];
            }
        }
        for (int i = 1; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                mat[i][j] += mat[i - 1][j];
            }
        }
        
        int res = INT_MIN;
        for (int i = K - 1; i < N; ++i) {
            for (int j = K - 1; j < N; ++j) {
                int sum = mat[i][j];
                if (i > K - 1)
                    sum -= mat[i - K][j];
                if (j > K - 1)
                    sum -= mat[i][j - K];
                if (i > K - 1 && j > K - 1)
                    sum += mat[i - K][j - K];
                    
                res = max(res, sum);
            }
        }
        
        return res;
    }  
};

// { Driver Code Starts.

int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
    	int N;
        cin>>N;
        vector<vector<int>> mat(N,vector<int>(N,0));
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cin>>mat[i][j];
            }
        }
        
        int k;cin>>k;
        Solution obj;
        cout << obj.Maximum_Sum(mat,N,k)<<"\n";
    }
        
    return 0;
}
  // } Driver Code Ends