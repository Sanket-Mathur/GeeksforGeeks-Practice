// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    int result = 0;
	    long long int sum = 0;
	    unordered_map<long long int, int> mp;
	    
	    for (int i = 0; i < n; ++i) {
	        sum += arr[i];
	        
	        int rem = ((sum % k) + k) % k;
	        
	        if (rem == 0) {
	            result = i + 1;
	        } else if (mp.find(rem) != mp.end()) {
	            result = max(result, i - mp[rem]);
	        } else {
	            mp[rem] = i;
	        }
	    }
	    
	    return result;
	}
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
  // } Driver Code Ends