//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	bool check_elements(int arr[], int n, int A, int B)
	{
	    vector<bool> checkExistance(B + 1, false);
	    for (int i = 0; i < n; ++i) {
	        if (arr[i] >= A && arr[i] <= B) {
	            checkExistance[arr[i]] = true;
	        }
	    }
	    
	    for (int i = A; i < B + 1; ++i) {
	        if (!checkExistance[i]) {
	            return false;
	        }
	    }
	    return true;
	}

};
	

//{ Driver Code Starts.


int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,A,B;
		cin>>n>>A>>B;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];

        

        Solution ob;
        if (ob.check_elements(a, n, A, B))
			cout << "Yes";
		else
			cout << "No";
	    
        
	    cout << "\n";
	     
    }
    return 0;
}







// } Driver Code Ends