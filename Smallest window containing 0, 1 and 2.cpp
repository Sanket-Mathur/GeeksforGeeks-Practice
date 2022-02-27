// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        vector<int> counts(3, 0);
        
        int minLength = INT_MAX;
        int i = 0, j = 0;
        
        while (j < S.length()) {
            counts[S[j++] - '0']++;
            
            while (*min_element(counts.begin(), counts.end()) > 0) {
                minLength = min(minLength, j - i);
                
                counts[S[i++] - '0']--;
            }
        }
        
        return minLength == INT_MAX ? -1 : minLength;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}  // } Driver Code Ends