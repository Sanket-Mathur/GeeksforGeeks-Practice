//{ Driver Code Starts
//Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    long long maxProduct(int arr[], int n) {
        long long l1 = INT_MAX, l2 = INT_MAX, h1 = INT_MIN, h2 = INT_MIN, h3 = INT_MIN;
        for (int i = 0; i < n; ++i) {
            if (arr[i] < l1) {
                l2 = l1;
                l1 = arr[i];
            } else if (arr[i] < l2) {
                l2 = arr[i];
            }
            
            if (arr[i] > h1) {
                h3 = h2;
                h2 = h1;
                h1 = arr[i];
            } else if (arr[i] > h2) {
                h3 = h2;
                h2 = arr[i];
            } else if (arr[i] > h3) {
                h3 = arr[i];
            }
        }
        
        return max(h1 * l1 * l2, h1 * h2 * h3);
    }
};

//{ Driver Code Starts.
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
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends