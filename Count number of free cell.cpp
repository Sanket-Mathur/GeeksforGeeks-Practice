//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      long long int cnt = n * n, nc = 0, nr = 0;
      vector<long long int> result;
      vector<bool> row(n + 1, false), col(n + 1, false);
      
      for (auto i : arr) {
          if (!row[i[0]]) {
              row[i[0]] = true;
              nr++;
              cnt -= n - nc;
          }
          if (!col[i[1]]) {
              col[i[1]] = true;
              nc++;
              cnt -= n - nr;
          }
          
          result.push_back(cnt);
      }
      
      return result;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends