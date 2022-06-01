// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> shiftPile(int N, int n){
        vector<int> result;
        
        towerOfHanoi(N, n, 1, 2, 3, result);
        return result;
    }
    
    void towerOfHanoi(int N, int &n, int first, int aux, int final, vector<int> &result) {
        if (N == 0) {
            return;
        }
        
        towerOfHanoi(N - 1, n, first, final, aux, result);
        if (!(--n)) {
            result.push_back(first);
            result.push_back(final);
        }
        towerOfHanoi(N - 1, n, aux, first, final, result);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, n;
        cin>>N>>n;
        
        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends