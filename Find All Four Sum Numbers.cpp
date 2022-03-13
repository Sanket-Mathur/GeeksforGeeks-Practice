// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        set<vector<int>> resultSet;
        vector<vector<int>> result;
        
        sort(arr.begin(), arr.end());
        
        for (int i = 0; i < arr.size() - 3; ++i) {
            for (int j = i + 1; j < arr.size() - 2; ++j) {
                int start = j + 1, last = arr.size() - 1;
                
                while (start < last) {
                    int sum = arr[i] + arr[j] + arr[start] + arr[last];
                    
                    if (sum == k) {
                        vector<int> res = {arr[i], arr[j], arr[start], arr[last]};
                        if (resultSet.find(res) == resultSet.end()) {
                            resultSet.insert(res);
                            result.push_back(res);
                        }
                        ++start;
                        --last;
                    } else if (sum < k) {
                        ++start;
                    } else {
                        --last;
                    }
                }
            }
        }
        
        return result;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends