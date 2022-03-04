// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<int> canMakeTriangle(vector<int> A, int N){
        vector<int> res(N - 2, 0);
        
        for (int i = 0; i < N - 2; ++i) {
            if (A[i] < A[i + 1] + A[i + 2] && A[i + 1] < A[i] + A[i + 2] && A[i + 2] < A[i] + A[i + 1]) {
                res[i] = 1;
            }
        }
        
        return res;
    }
}; 

// { Driver Code Starts.
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++)
            cin>>A[i];
        Solution ob;
        auto ans = ob.canMakeTriangle(A, N);
        for(int i=0;i<ans.size();i++)
            cout << ans[i] << " ";
        cout << endl;
        
    }

    return 0; 
}   // } Driver Code Ends