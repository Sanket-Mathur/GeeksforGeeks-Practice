//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends


int findElement(int arr[], int n) {
    vector<int> prefix(n, INT_MIN), suffix(n, INT_MAX);
    for (int i = 1; i < n; ++i) {
        prefix[i] = max(prefix[i - 1], arr[i - 1]);
    }
    for (int i = n - 2; i > -1; --i) {
        suffix[i] = min(suffix[i + 1], arr[i + 1]);
    }
    
    for (int i = 1; i < n - 1; ++i) {
        if (prefix[i] <= arr[i] && suffix[i] >= arr[i]) {
            return arr[i];
        }
    }
    return -1;
}