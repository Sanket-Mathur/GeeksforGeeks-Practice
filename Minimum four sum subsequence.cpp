// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
/*You are required to complete below method */

class Solution{
public:
    int minSum(int arr[], int n){
        vector<int> table(arr, arr + n);
        for (int i = 4; i < n; ++i) {
            table[i] = arr[i] + *min_element(table.begin() + (i - 4), table.begin() + i);
        }
        
        return n >= 4 ? *min_element(table.begin() + (n - 4), table.end()) : *min_element(arr, arr + n);
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
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.minSum(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends