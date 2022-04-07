// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string LCP(string ar[], int n)
    {
        string prefix = ar[0];
        
        for (int i = 1; i < n; ++i) {
            int len = 0;
            for (; len < prefix.length() && len < ar[i].length() && prefix[len] == ar[i][len]; ++len);
            
            prefix = prefix.substr(0, len);
        }
        
        return prefix.length() > 0 ? prefix : "-1";
    }
};

// { Driver Code Starts.

int main() 
{

	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        string arr[n];
	        for(int i = 0;i<n;i++)
	            cin>>arr[i];
	        Solution ob;
	        cout<<ob.LCP(arr,n)<<endl;
	    }
	return 0;
}  // } Driver Code Ends