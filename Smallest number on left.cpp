//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        vector<int> result;
        stack<int> stk;
        
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && stk.top() >= a[i]) {
                stk.pop();
            }
            
            if (stk.empty()) {
                result.push_back(-1);
            } else {
                result.push_back(stk.top());
            }
            stk.push(a[i]);
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i = 0;i < n;i++)
            cin>>a[i];
        
        Solution ob;
        vector<int> ans = ob.leftSmaller(n, a);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends