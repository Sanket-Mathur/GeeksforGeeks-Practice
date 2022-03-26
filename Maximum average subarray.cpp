// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMaxAverage(int arr[], int n, int k) {
        double maxAvg = 0, avg, currSum = 0;
        int startingIndex = 0;
        
        for (int i = 0; i < k; ++i) {
            currSum += arr[i];
        }
        maxAvg = currSum / k;
        
        for (int i = k; i < n; ++i) {
            currSum += arr[i];
            currSum -= arr[i - k];
            avg = currSum / k;
            
            if (avg > maxAvg) {
                maxAvg = avg;
                startingIndex = i - k + 1;
            }
        }
        
        return startingIndex;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxAverage(arr, n, k);
        for (int i = ans; i < ans + k; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends