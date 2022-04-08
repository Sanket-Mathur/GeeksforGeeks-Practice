// { Driver Code Starts
#include <bits/stdc++.h>
#define N 10000
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    vector<int> print_next_greater_freq(int arr[],int n)
    {
        unordered_map<int, int> cnts;
        for (int i = 0; i < n; ++i) {
            cnts[arr[i]]++;
        }
        
        stack<int> stk;
        vector<int> result(n, -1);
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && (stk.top() == arr[i] || cnts[stk.top()] <= cnts[arr[i]])) {
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


// { Driver Code Starts.

int main()
{
    int arr[N];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans=ob.print_next_greater_freq(arr,n);
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout << endl;
    }
	return 1;
}
  // } Driver Code Ends