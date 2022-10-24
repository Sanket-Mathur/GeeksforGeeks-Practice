//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

struct alphanumeric {
    string name;
    int count;
};
class Solution {
  public:
    vector<alphanumeric> sortedStrings(int N, vector<string> A) {
        unordered_map<string, int> mp;
        for (int i = 0; i < N; ++i) {
            if (mp.find(A[i]) != mp.end()) {
                mp[A[i]]++;
            } else {
                mp[A[i]] = 1;
            }
        }
        
        vector<alphanumeric> result;
        for (auto p : mp) {
            alphanumeric tmp;
            tmp.name = p.first;
            tmp.count = p.second;
            
            result.push_back(tmp);
        }
        
        sort(result.begin(), result.end(), [](const alphanumeric &a, const alphanumeric &b) -> bool {
            return a.name < b.name;
        });
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        cin.ignore();
        vector<string> v;
        for (int i = 0; i < N; i++) {
            string s;
            getline(cin, s);
            v.push_back(s);
        }
        Solution ob;
        vector<alphanumeric> ans = ob.sortedStrings(N, v);
        for (auto u : ans) cout << u.name << " " << u.count << "\n";
    }
}
// } Driver Code Ends