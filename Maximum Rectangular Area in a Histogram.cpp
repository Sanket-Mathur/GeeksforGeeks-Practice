//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        stack<long long> stk;
        vector<long long> left(n, -1), right(n, n);
        
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }
            
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        
        while (!stk.empty()) {
            stk.pop();
        }
        
        for (int i = n - 1; i > -1; --i) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }
            
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        
        long long result = 0;
        for (int i = 0; i < n; ++i) {
            result = max(result, (right[i] - left[i] - 1) * arr[i]);
        }
        
        return result;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends