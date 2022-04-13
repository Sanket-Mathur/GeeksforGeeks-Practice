// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    vector<int> negTemp, posTemp;
	    for (int i = 0; i < n; ++i) {
	        if (arr[i] >= 0) {
	            posTemp.push_back(arr[i]);
	        } else {
	            negTemp.push_back(arr[i]);
	        }
	    }
	    
	    int negPtr = 0, posPtr = 0;
	    for (int i = 0; i < n; ++i) {
	        if (i % 2 == 0) {
	            arr[i] = posPtr == posTemp.size() ? negTemp[negPtr++] : posTemp[posPtr++];
	        } else {
	            arr[i] = negPtr == negTemp.size() ? posTemp[posPtr++] : negTemp[negPtr++];
	        }
	    }
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends