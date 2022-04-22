// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    int findMidSum(int ar1[], int ar2[], int n) {
        int l1 = 0, l2 = 0, h1 = n - 1, h2 = n - 1;
        
        while ((h1 - l1 + 1) + (h2 - l2 + 1) > 2) {
            if (ar1[l1] < ar2[l2]) {
                ++l1;
            } else {
                ++l2;
            }
            
            if (ar1[h1] > ar2[h2]) {
                --h1;
            } else {
                --h2;
            }
        }
        
        if (l1 == h1) {
            return ar1[l1] + ar2[l2];
        } else if (l1 > h1) {
            return ar2[l2] + ar2[h2];
        }
        return ar1[l1] + ar1[h1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int ar1[n], ar2[n];
        for (i = 0; i < n; i++) {
            cin >> ar1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> ar2[i];
        }
        Solution ob;
        auto ans = ob.findMidSum(ar1, ar2, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends