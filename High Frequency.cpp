// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    string solve(int N, string S) {
        unordered_map<char, int> table;
        for (int i = 0; i < N; ++i) {
            table[S[i]]++;
        }
        
        char res = S[0];
        int count = 1;
        
        for (auto p : table) {
            if (count < p.second) {
                res = p.first;
                count = p.second;
            }
            else if (count == p.second && res > p.first) {
                res = p.first;
            }
                
        }
        
        string result = "";
        result += res;
        return result;
    }
};

// { Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        string S;
        cin >> N >> S;
        Solution ob;
        cout << ob.solve(N, S) << "\n";
    }
    return 0;
}
  // } Driver Code Ends