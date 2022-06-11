// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int canRepresentBST(int arr[], int N) {
        int prev = INT_MIN;
        stack<int> stk;
        
        for (int i = 0; i < N; ++i) {
            while (stk.size() > 0 && stk.top() < arr[i]) {
                prev = stk.top();
                stk.pop();
            }
            
            if (arr[i] < prev) {
                return 0;
            }
            stk.push(arr[i]);
        }
        
        return 1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    }
    return 0;
}  // } Driver Code Ends