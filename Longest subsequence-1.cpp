// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int longestSubsequence(int N, int A[])
    {
        vector<int> table(N, 1);
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                if (abs(A[i] - A[j]) == 1)
                    table[j] = max(table[j], table[i] + 1);
            }
        }
        
        return *max_element(table.begin(), table.end());
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  // } Driver Code Ends