//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q) {
        vector<int> freq(N, 0);
        for (int i = 0; i < N; ++i) {
            for (int j = i; j < N; ++j) {
                if (A[i] == A[j]) {
                    freq[i]++;
                }
            }
        }
        
        vector<int> result;
        for (auto query : Q) {
            int cnt = 0;
            for (int i = query[0]; i <= query[1]; ++i) {
                if (freq[i] == query[2]) {
                    cnt++;
                }
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
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends