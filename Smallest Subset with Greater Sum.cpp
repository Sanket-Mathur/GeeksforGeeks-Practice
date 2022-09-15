//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int minSubset(vector<int> &Arr,int N){
        sort(Arr.begin(), Arr.end(), greater<int> ());
        
        long long sum = 0;
        for (auto i : Arr) {
            sum += i;
        }
        
        long long removed = 0;
        int count = 0, j = N - 1;
        for (int i = 0; i < N; ++i) {
            sum -= Arr[i];
            removed += Arr[i];
            count++;
            
            if (removed > sum) {
                return count;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        cout<<ob.minSubset(Arr,N)<<endl;
    }
    return 0;
}
// } Driver Code Ends