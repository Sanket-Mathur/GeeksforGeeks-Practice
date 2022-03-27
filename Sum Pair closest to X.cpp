// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    vector<int> sumClosest(vector<int>arr, int x)
    {
        int i = 0, j = arr.size() - 1;
        vector<int> res = {arr[i], arr[j]};
        
        while (i < j) {
            if (abs(x - arr[i] - arr[j]) < abs(x - res[0] - res[1])) {
                res = {arr[i], arr[j]};
            }
            
            if (arr[i] + arr[j] < x) {
                ++i;
            } else {
                --j;
            }
        }
        
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumClosest(arr, x);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends