// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int count(int N, vector<int> A,int X)
    {
        int p = 0, result = N;
        
        for (int i = 31; i >= 0; --i) {
            if ((X >> i) & 1) {
                p = p | (1 << i);
            } else {
                int mask = p | (1 << i);
                int cnt = 0;
                for (int item : A) {
                    if ((item & mask) != mask) {
                        cnt++;
                    }
                }
                
                result = min(result, cnt);
            }
        }
        
        return result;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int N,X;
        cin>>N>>X;
        vector<int> A(N);
        for(auto &i:A)
            cin>>i;
        Solution obj;
        int ans = obj.count(N, A, X);
        cout<<ans<<endl;
    }
}  // } Driver Code Ends