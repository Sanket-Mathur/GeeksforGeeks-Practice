//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& Arr, int N){
      vector<long long int> conSum(N, 0);
      conSum[0] = Arr[0];
      for (int i = 1; i < N; ++i) {
          conSum[i] = conSum[i - 1] + Arr[i];
      }
      
      long long int sum = 0;
      for (int i = 0; i < N; ++i) {
          sum += conSum[i] < 0 ? -conSum[i] : conSum[i];
      }
      
      return sum;
  }
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends