#include <bits/stdc++.h>
using namespace std;

int kthDiff(int a[], int n, int k);

// Driver code
int main() {
    int t, i;
    int k;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;

        cout << kthDiff(a, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends

int lessDiff(int a[], int n, int k) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += upper_bound(a + i, a + n, a[i] + k) - (a + i + 1);
    }
    
    return cnt;
}

int kthDiff(int a[], int n, int k) {
    sort(a, a + n);
    
    int low = INT_MAX, high = a[n - 1] - a[0];
    for (int i = 1; i < n; ++i) {
        low = min(low, a[i] - a[i - 1]);
    }
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (lessDiff(a, n, mid) < k) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    
    return low;
}