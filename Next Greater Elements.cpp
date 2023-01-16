//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        vector<long long> result(n, -1);
        stack<long long> stk;
        
        for (int i = n - 1; i > -1; --i) {
            while (!stk.empty() && stk.top() <= arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                result[i] = stk.top();
            }
            
            stk.push(arr[i]);
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends