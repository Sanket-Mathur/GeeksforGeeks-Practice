// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    unordered_map<int, int> maxSum;
	    return solver(arr, n, 0, maxSum);
	}
	int solver(int *arr, int n, int i, unordered_map<int, int> &maxSum) {
	    if (i == n)
	        return 0;
	    else if (i == n - 1)
	        return arr[i];
	    else if (maxSum.find(i) != maxSum.end())
	        return maxSum[i];
	        
	    int res = max(arr[i] + solver(arr, n, i + 2, maxSum), solver(arr, n, i + 1, maxSum));
	    maxSum[i] = res;
	    return res;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends