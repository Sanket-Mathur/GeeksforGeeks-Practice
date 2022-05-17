// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> maximizeArray(int arr1[], int arr2[], int n) {
        set<int> set1, set2;
        for (int i = 0; i < n; ++i) {
            set1.insert(arr1[i]);
            set2.insert(arr2[i]);
        }
        
        auto a = set1.rbegin(), b = set2.rbegin();
        unordered_set<int> resSet;
        
        while (resSet.size() < n) {
            if (a == set1.rend() && b == set2.rend()) {
                break;
            } else if (a == set1.rend()) {
                resSet.insert(*b);
                ++b;
            } else if (b == set2.rend()) {
                resSet.insert(*a);
                ++a;
            } else {
                if (*a > *b) {
                    resSet.insert(*a);
                    ++a;
                } else {
                    resSet.insert(*b);
                    ++b;
                }
            }
        }
        
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (resSet.find(arr2[i]) != resSet.end()) {
                result.push_back(arr2[i]);
                resSet.erase(arr2[i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (resSet.find(arr1[i]) != resSet.end()) {
                result.push_back(arr1[i]);
                resSet.erase(arr1[i]);
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
        int n, i;
        cin >> n;
        int arr1[n], arr2[n];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < n; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        auto ans = ob.maximizeArray(arr1, arr2, n);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends