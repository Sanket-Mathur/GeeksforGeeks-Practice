//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        int start = 0, end = 0, sum = 0, minLen = INT_MAX;
        while (end < n) {
            if (sum <= x) {
                sum += arr[end];
                ++end;
            } else {
                minLen = min(minLen, end - start);
                sum -= arr[start];
                ++start;
            }
        }
        while (sum > x) {
            minLen = min(minLen, end - start);
            sum -= arr[start];
            ++start;
        }
        
        return minLen == INT_MAX ? 0 : minLen;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends