//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        int mid = s.length() / 2 - 1, len = 0;
        
        while (mid >= 1) {
            if (s.substr(0, mid + 1) == s.substr(mid + 1, mid + 1)) {
                len = mid + 1;
                break;
            }
            mid--;
        }
        
        return len == 0 ? s.length() : s.length() - len + 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends